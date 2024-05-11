#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <grp.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <pwd.h>
#include <time.h>
#include <unistd.h>
#include "read_dir.h"

#define BUFF_LEN 1024

int process(char *name);
void enqueue(char *name, que_t *q);
void dequeue(que_t *q);
void peek_front(char *name,que_t q);
bool queue_empty(que_t q);
void initq(que_t *q);


// main function
int main(int argc,char *argv[]) {

  if (2 != argc) {
    printf(" usage: %s dirpath\n", argv[0]);
    exit(-1);
  }
  else {
    // pass in the starting directory
    process(argv[1]);       
  }
  
  return 0;
}

// traverse a directory tree applying a function when a file is found
int process (char *root) {

  int numOfFiles = 0;
  int numOfDirectories = 0;
  que_t nameq;
  char dname[MAXLENGTH];
  char cname[MAXLENGTH];
  char prefix[MAXLENGTH];
  int largestSize = 0;
  int smallestSize = 0;
  int totalSize;
  double averageSize = 0;
  unsigned int fd;
  int regFiles;

  struct stat leastRecent;
  char leastRecentName[MAXLENGTH];
  char mostRecentName[MAXLENGTH];

  struct stat mostRecent;

  struct stat currStat;


  struct dirent *dp;
  DIR *dirp;

    initq(&nameq);
    enqueue(root,&nameq);


while (true != queue_empty(nameq)) {
      peek_front(dname,nameq); 
      dequeue(&nameq);
      
      dirp = opendir(dname);
      if (dirp != NULL) { // it is a directory
	lstat(dname, &currStat);
	// check to see if link. If so, print to stdout
	if (S_ISLNK(currStat.st_mode)) { 
		printf("Encountered Symbolic Link: %s\n", dname);
	//	break;
	} 
	
	numOfDirectories++;

	printf("directory : %s\n",dname);
	strncpy(prefix, dname, MAXLENGTH);
	strncat(prefix,"/", MAXLENGTH);
	
	for (dp = readdir(dirp); NULL != dp; dp = readdir(dirp)) {
	  if ((strcmp(dp->d_name,"..") != 0) && 
	      (strcmp(dp->d_name,".") != 0)) {
	    
	    // prevent from infinite loop
	    strncpy(cname, prefix, MAXLENGTH);
	    
	    // concatenate the prefix
	    strncat(cname, dp->d_name, MAXLENGTH);  
	    enqueue(cname,&nameq);
	  }
	}
	closedir (dirp);
	}
       else { 
	// test if it is a regular file and not a device or link -- TO-DO
	// if this is a regular file, then process it -- TO-DO
	
	lstat(dname, &currStat);

	if (S_ISLNK(currStat.st_mode)) { 
			printf("Encountered Symbolic Link: %s\n", dname);
			
	}
	else {
	fd = open(dname, O_RDONLY);

	if (fstat(fd, &currStat) == 0) { 

	

		if (S_ISREG(currStat.st_mode)) {

			if (numOfFiles == 0) {
				leastRecent = currStat;
				strcpy(leastRecentName, dname);
				mostRecent = currStat;
				strcpy(mostRecentName, dname);
				smallestSize = currStat.st_size;
				largestSize = currStat.st_size;
				 
			}

			else {
				if (currStat.st_mtime > mostRecent.st_mtime) {
					mostRecent = currStat;
					strcpy(mostRecentName, dname);
				}
				if (currStat.st_size < smallestSize) {
					smallestSize = currStat.st_size;
				}
				
				else if (currStat.st_mtime < leastRecent.st_mtime) {
					leastRecent = currStat;
					strcpy(leastRecentName, dname);
				}
			}
			totalSize += currStat.st_size;
			numOfFiles++;
   		        
		}
		
		printf(" processing file: %s\n", dname);
	}
	close(fd);
	}
	fflush(stdout);
    //	close(fd);
      }      
    } // while

    averageSize = (double)totalSize / (double)numOfFiles;
    printf(" Smallest file size: %d\n", smallestSize);
    printf(" Largest file size: %d\n", largestSize);
    printf(" Average file size: %lf\n", averageSize);

    printf(" a total of %d directories were counted\n",numOfDirectories);
    printf(" a total of %d regular files were counted\n",numOfFiles);
    printf(" least recently modified file: %s\n", leastRecentName);
    printf(" most recently modified file: %s\n", mostRecentName);
    
  return 0;
}

// initialize queue data structure
void initq(que_t *q) {
  q->head = q->tail = NULL;
}

// test whether queue data structure is empty
bool queue_empty(que_t q) {
  if (NULL == q.head) {
     return true;
  } else {
    return false;
  }
}

// add an element to queue
void enqueue(char *name, que_t *q) {
  item_t *temp;
  
  temp = (item_t *)malloc(sizeof(item_t));
  strncpy(temp->name,name,MAXLENGTH);
  temp->next = NULL;
  
  if (true == queue_empty(*q)) {
    q->head = temp;
    q->tail = temp;
  } else {
    q->tail->next = temp;
    q->tail = q->tail->next;
  }
}

// remove an element from the front of the queue
void dequeue(que_t *q) {
  item_t *temp;
  
  if (true == queue_empty(*q)) {
    printf(" error in dequeue \n");
    exit(-1);
  } else {
    temp = q->head;
    q->head = q->head->next;
    free(temp);
  }
}

// find element at front of queue without removing
void peek_front(char *name, que_t q) {
  if (true == queue_empty(q)) {
    printf(" error in dequeue \n");
     exit(-1);
  } else {
    strncpy(name, q.head->name, MAXLENGTH);
  }
} 
