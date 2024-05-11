//#include   <unistd.h> // need this for fork
#include   <sys/types.h>
#include   <stdio.h> // need this for printf and fflush
#include<sys/wait.h>

int i = 10;
double x =3.14159;
int pid;

int main (int argc, char* argv[]) {

  int j = 2;
  double y = 0.12345;
  
  pid = fork();
  int status;
  if (pid < 0) {
		fprintf(stderr, "Fork failed");
		return 1;
	}
  if (pid > 0) {
    // parent code
    printf("parent process -- pid= %d\n", getpid()); fflush(stdout);
    printf("parent sees: i= %d, x= %lf\n", i, x); fflush(stdout);
    printf("parent sees: j= %d, y= %lf\n", j, y); fflush(stdout);
    printf("Parent process ID: %d\n",getppid());
    sleep(30); 
    printf("I didn't waited for the child process\n");   

  } else {
    // child code
    printf("child process -- pid= %d\n", getpid()); fflush(stdout);
    printf("child sees: i= %d, x= %lf\n", i, x); fflush(stdout);
    printf("child sees: j= %d, y= %lf\n", j, y); fflush(stdout);
    printf("Child process ID: %d\n",getpid());
    printf("I am child,I executed before parents\n");
    printf("I am a Zombie now\n");
    wait(&status);
  }   

  return(0);
}
