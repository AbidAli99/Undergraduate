#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>
#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

pid_t Fork(void){
  pid_t pid;
  pid = fork();
  if(pid == -1) {
    perror("Error, system call to fork() failed\n");
    exit(-1);
  }
  else{
    return pid;
  }
}

int Pipe(int pipefd[2]){
  int p;
  p = pipe(pipefd);
  if(p == -1) {
    perror("Error, system call to pipe(fd) failed\n");
    exit(-1);
  }
  else{
    return p;
  }
}

int Read(int fd, void *buf, size_t count){
  int r;
  r = read(fd,buf,count);
  if(r == -1) {
    perror("Error, system call to read() failed\n");
    exit(-1);
  }
  else{
    return r;
  }
}

int Write(int fd, const void *buf, size_t count){
  int w;
  w = write(fd, buf, count);
  if(w == -1) {
    perror("Error, system call to write() failed\n");
    exit(-1);
  }
  else{
    return w;
  }
}

int main(void){
  char p_write_msg[BUFFER_SIZE] = "Greatings!";
  char c_read_msg[BUFFER_SIZE];
  char c_write_msg[BUFFER_SIZE];
  char p_read_msg[BUFFER_SIZE];
  int fd[2];
  int fd2[2];
  int status;
  pid_t pid;
  
  /* create the pipe */
  Pipe(fd);
  Pipe(fd2);

  /* fork a child process */
  pid = Fork();

  if (pid > 0) { /* parent process */
    int i = 0;
    /* close the unused end of the pipes */
    close(fd[READ_END]);
    close(fd2[WRITE_END]);
    /* write to the pipe one character at a time*/
    printf("\nParent is writing to pipe: \n");
    printf("----------------------------\n");
    while(p_write_msg[i] != '\0'){
      printf("%s\n", &p_write_msg[i]);
       Write(fd[WRITE_END], &p_write_msg[i], sizeof(char));
      i++;
    }
    close(fd[WRITE_END]);
    wait(&status);
    int k = 0;
     /* read from the pipe one character at a time*/
    int reading_2 = Read(fd2[READ_END],&p_read_msg[k],sizeof(char));
    printf("\nParent is printing to stdout: \n");
    printf("-------------------------------");
    while(reading_2 != 0){
      printf("\n");
      Write(1, &p_read_msg[k],sizeof(char));
      k++;
      reading_2 = Read(fd2[READ_END], &p_read_msg[k],sizeof(char));
    }
    printf("\n");
    /* close the write/read end of the pipes */
    close(fd2[READ_END]);
    //exit(0);
  }
  else { /* child process */
    int j = 0;
    /* close the unused end of the pipes */
    close(fd[WRITE_END]);
    close(fd2[READ_END]);
    /* read from the pipe one character at a time */
    int reading = Read(fd[READ_END],&c_read_msg[j],sizeof(char));
    /*write to stdout the message recieved by parent*/
    printf("\nChild is printing to stdout: \n");
    printf("-------------------------------\n");
    /* while '\0' has not been read */
    while(reading != 0){
      Write(1,&c_read_msg[j],sizeof(char));
      /*write to parent through pipe toupper of char recieved*/
      c_write_msg[j] = toupper(c_read_msg[j]);
      printf("\n,converted to upper case and written to second pipe as: %c\n",c_write_msg[j]);
      Write(fd2[WRITE_END],&c_write_msg[j],sizeof(char));
      j++;
      reading = Read(fd[READ_END],&c_read_msg[j],sizeof(char));
    }
    printf("\n\nChild wrote to second pipe: %s\n",c_write_msg);
    printf("--------------------------------------");
    /* close the read/write end of the pipes */
    close(fd[READ_END]);
    close(fd2[WRITE_END]);
    //exit(0);
  }
  return 0;
}

