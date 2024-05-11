#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <string.h>
#include <errno.h>


sem_t *semaphore;

int main (int argc, char *argv[]){
	if (2 != argc){
		printf("usage: sender [message]\n");
		exit(-1);

	} else {

		char *msg = argv[1];
		semaphore = sem_open("sem_new_send_receive", O_RDWR);

		if (semaphore == SEM_FAILED){
			printf("There was an error in initializing semaphore. Exiting ....");
			exit(EXIT_FAILURE);
		} else {
		sem_wait(semaphore);
		int fd = open("channel.txt", O_CREAT | O_WRONLY, S_IRWXU);
		write(fd, msg, strlen(msg));
		write(fd, "\n", 1);
		close(fd);

		sem_post(semaphore);
		sleep(1);
	}

	sem_close(semaphore);

	}

	return 0;

}
