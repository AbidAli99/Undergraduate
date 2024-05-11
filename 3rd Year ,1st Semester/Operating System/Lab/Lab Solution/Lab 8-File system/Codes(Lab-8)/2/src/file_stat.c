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

#define BUFF_LEN 1024

int main(int argc, char *argv[]) {

  // pointer to file name string
  char *name;

  // allocate tm structure to store retrieved time
  struct tm time;

  struct tm time_two;

  struct tm time_three;

  // allocate space to hold a string with retrieved time (ASCII text)
  char asctime_str[35];
  char asctime_str_two[35];
  char asctime_str_three[35];

  // container for complete set of file permission bits (binary)
  unsigned int mode;

  // container for the three bits of user permissions
  unsigned int umode;

  // container for the three bits of group permissions
  unsigned int gmode;

  // container for the three bits of owner permission
  unsigned int omode;

  // human readable file permissions (ASCII text)
  char perm_bits_str[] = "---------";

  // file descriptor 
  unsigned int fd;

  // structure to contain the result of the fstat call (info on this file)
  struct stat file_info;

  // structure to contain the result of the vfstat call (info on file system)
  struct statvfs fs_info;
  
  // used to save the return value of realpath
  char resolved_path[PATH_MAX];
  char* ret_path;
  
  // check number of arguments for appropriate usage
  if (2 != argc) {
    printf(" usage: %s [file_name]\n", argv[0]);
    exit(-11);
  }

  // post-condition: argv[1] contains name of file to use
  
  // try to open file
  fd = open(argv[1], O_RDONLY);
  if (-1 == fd) {
    perror("Failed to open read only file - ");
    exit(-1);
  }
  
  // use fstatvfs to learn details about the file system
  if (fstatvfs(fd, &fs_info) == 0) {
      printf("== FILE SYSTEM INFO ============================\n");
      printf(" file system fstatvfs() call successful\n");
      unsigned long block_size = fs_info.f_bsize;
      printf(" file system block size: %lu\n", block_size); // TO-DO
      unsigned long max_namesize = fs_info.f_namemax;
      printf(" max. file name length: %lu\n", max_namesize); // TO-DO
  } else {
    printf("%s: File system fstatvfs call failed\n", argv[0]);
    exit(-1);
  }

  // post-condition: maximum length of file name string is known

  // use calloc to allocate space for file name string
  name = calloc(fs_info.f_namemax, 1);

  if (NULL == name) {
    perror("Problem in calloc - ");
    exit(-1);
  }

  // copy file name into name variable using secure version of string copy
  strncpy(name, argv[1], 500);
   
  // use fstat to get information on specific file
  if (fstat(fd, &file_info) == 0) {
    printf("\n== FILE INFO ============================\n");
    printf(" file fstat() call successful\n");
    
    // mode comes from the lower 9 bits in file_info.st_mode
    mode = file_info.st_mode & 0x1FF;
    
    printf(" file protection bits = 0%o\n", mode);
    
    // umode comes from the high 3 bits in mode
    umode = mode & S_IRWXU;
    umode = umode >> 6; // TO-DO
    
    // gmode comes from the middle 3 bits in mode
    gmode = mode & S_IRWXG; // TO-DO
    gmode = gmode >> 3;
    // omode comes from the low 3 bits in mode
    omode = mode & S_IRWXO; // TO-DO
      
    // once you have set umode, gmode, and omode, the code below
    // will construct the right string for you and display it

    // construct string with file protection information
    if (umode & 0x4) perm_bits_str[0] = 'r';
    if (umode & 0x2) perm_bits_str[1] = 'w';
    if (umode & 0x1) perm_bits_str[2] = 'x';
    
    if (gmode & 0x4) perm_bits_str[3] = 'r';
    if (gmode & 0x2) perm_bits_str[4] = 'w';
    if (gmode & 0x1) perm_bits_str[5] = 'x';
    
    if (omode & 0x4) perm_bits_str[6] = 'r';
    if (omode & 0x2) perm_bits_str[7] = 'w';
    if (omode & 0x1) perm_bits_str[8] = 'x';
    
    printf(" file protection string = %s\n", perm_bits_str);
    
    printf(" file protection mode (u:g:o) = %o:%o:%o\n",
	   umode, gmode, omode);

   
    struct passwd my_passwd;
    struct passwd *my_result;
    size_t buflen = BUFF_LEN;
    char buf[BUFF_LEN];

    struct group my_group; 
    struct group *my_group_result;
    char buf_group[BUFF_LEN];
    int ret_value = getpwuid_r(file_info.st_uid, &my_passwd, buf, buflen, &my_result);
    int ret_value_grp = getgrgid_r(my_result->pw_gid, &my_group, buf_group, buflen, &my_group_result);

    if (ret_value != 0) {
	printf("Error in get_pwuid_r()\n");
//	exit(EXIT_FAILURE);
    }
	
    printf(" owner user name = %s\n", my_result->pw_name); // TO-DO: man getpwuid 
    printf(" owner group name = %s\n", my_group_result->gr_name); // TO-DO: man getgrgid 
    
		// TO-DO: print "mode = x", where x may be:
		// "regular file"
		// "directory"
		// "character device"
		// "block device"
		// "symbolic link"
		// "socket"
		// "fifo"
		// "unknown"

    if (S_ISREG(file_info.st_mode)) { 
      printf(" mode = regular file\n");
		} else { // see TO-DO above
		}
       
    ret_path = realpath(name, resolved_path);
    if (NULL != ret_path) 
      printf(" absolute path = %s\n", ret_path);
    else {
      perror(" couldn't resolve path");
      exit(-1);
    }
        
    // fill in the time the last write was made to file
    localtime_r(&(file_info.st_mtime), &time);      
    asctime_r(&time, asctime_str);
    printf(" time of last modification: %s\n", asctime_str);

    localtime_r(&(file_info.st_atime), &time_two);
    asctime_r(&time_two, asctime_str_two);
    printf(" time of last access: %s\n", asctime_str_two);

    localtime_r(&(file_info.st_ctime), &time_three);
    asctime_r(&time_three, asctime_str); 
    printf(" time of last status change: %s\n", asctime_str);
    
    fflush(stdout);
    close(fd);
    exit(0);
  }
  else
    printf(" fstat call failed\n");

  return 0;
}
