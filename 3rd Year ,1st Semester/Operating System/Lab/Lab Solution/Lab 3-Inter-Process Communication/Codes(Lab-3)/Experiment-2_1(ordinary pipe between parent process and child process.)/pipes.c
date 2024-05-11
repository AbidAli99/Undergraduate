#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include<sys/wait.h>
#include <assert.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 30
#define READ_END 0
#define WRITE_END 1

int main(void)
{
    char writemsg[BUFFER_SIZE] = "Greetings!";
    char readmsg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;
    pipe(fd);
    /* create the pipe */
    if ((pid=fork()) == -1) 
    {
        perror("fork");
        //fprintf(stderr,"Pipe failed");
    return 1;
    }
    /* fork a child process */
    pid = fork();
    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    if (pid > 0){/* parent process */
        /* close the unused end of the pipe */
        close(fd[READ_END]);
        dup2(fd[WRITE_END],1);
        execlp("ls","-a",NULL);
        /* write to the pipe */
        write(fd[WRITE_END], writemsg, strlen(writemsg)+1);
        /* close the write end of the pipe */
        close(fd[WRITE_END]);
        //printf("Receive Greetings from child :%s\n");
    }
    else{ /* child process */
        /* close the unused end of the pipe */
        close(fd[WRITE_END]);
        /* read from the pipe */

        read(fd[READ_END], readmsg, BUFFER_SIZE);
        printf("read %s\n",readmsg);
        /* close the write end of the pipe */
        printf("Receive Greetings from child :%s\n",writemsg);
        close(fd[READ_END]);
    }
    
    return 0;
}
