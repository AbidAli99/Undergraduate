#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int num = 0;
void ChildProcess(void); /* child process prototype
*/
void ParentProcess(void); /* parent process prototype */
void main(void)
{
    pid_t
    pid;
    pid = fork();
    if(pid == -1)
    {
        printf("something went wrong in fork");
        exit(-1);
    }
    else if (pid == 0)
        ChildProcess();
    else
        ParentProcess();
}
void ChildProcess(void)
{
    int i;
    int mypid;
    mypid = getpid();
    for (i = 1; i <= num; i++)

        printf("This line is from child, value = %d\n", i);
    fflush(stdout);
    printf("*** Child process %d is done ***\n",mypid);
    exit(0);
}
void ParentProcess(void)
{
    int
    i,status;
    int got_pid,mypid;
    mypid = getpid();
    for (i = 1; i <= num; i++)
        printf("This line is from parent, value = %d\n", i);
    fflush(stdout);
    printf("*** Parent %d is done ***\n",mypid);
    got_pid = wait(&status);
    printf("[%d] bye %d (%d)\n", mypid, got_pid, status);
}

