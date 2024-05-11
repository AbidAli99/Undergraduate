#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "hexdump.h"


char *filename;
unsigned int offset;
unsigned int size;
FILE *fp;
int fd;
ssize_t readV;
unsigned char *buf;

int main(int argc, char *argv[]){
  
  if(argc != 4){
    printf("ERROR: must input [filename][offset][size]\n");
    exit(-1);
  }

  filename = argv[1];
  offset = atoi(argv[2]);
  size = atoi(argv[3]);
  buf = malloc(sizeof(char)*(size+1));
  //printf("%s\n",filename);
  //printf("%u\n", offset);
  //printf("%u\n", size);
 
  fp = fopen(filename, "r");
  if(fp == NULL){
    perror("ERROR: ");
    exit(-1);
  }
  
  fd = fileno(fp);


  readV = pread(fd, buf, size, offset);
  if(readV == -1){
    perror("ERROR: ");
    exit(-1);
  }
  hexdump(buf, size);
  printf("\n");



  fclose(fp);
  return 0;
}
