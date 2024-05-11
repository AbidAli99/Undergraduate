#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUF_LEN 512





sem_t *semaphore;

int main(int argc, char *argv[]){

	int fd;

	char message_received[BUF_LEN];


	
	struct stat curr_stat;


	time_t most_recently_modified;
	time_t curr_modified;

	while (1) {

		int unlink = sem_unlink("sem_new_send_receive");
		if (unlink != 0) {
			printf("Error indicated by %s\n", strerror(errno));
		}


		semaphore = sem_open("sem_new_send_receive", O_CREAT | O_EXCL, S_IRWXU | S_IRWXG | S_IRWXO, 1);
		if (semaphore == SEM_FAILED){
			printf("There was an error in accessing semaphore\n");
			printf("Error is %s\n", strerror(errno));
			exit(-1);		
		} else {
			fd = open("channel.txt", O_RDONLY);

			if (fstat(fd, &curr_stat) == 0){

				curr_modified = curr_stat.st_mtime;

			} else {

				printf("There was an error reading file info\n");

			}

			memset(message_received, 0, BUF_LEN);
			read(fd, &message_received, (size_t)(BUF_LEN - 1));
			
			char *tokenized;
			char *curr_msg = NULL;
			tokenized = strtok(&message_received, "\n");

			while(tokenized != NULL) {

				curr_msg = tokenized;
				tokenized = strtok(NULL, "\n");

			}
			
			


			if (curr_msg != NULL && (curr_modified > most_recently_modified)){
				printf("%s\n", curr_msg);
				most_recently_modified = curr_modified;
			}

			close(fd);

			sem_close(semaphore);
		}
	}

	return 0;
}
