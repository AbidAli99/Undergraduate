#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>


#define MAX_LINE		80 /* 80 chars per line, per command, should be enough. */


char history[MAX_LINE];
char display_history [MAX_LINE];

int command_count = 0;

/**
 * The setup function below will not return any value, but it will just: read
 * in the next command line; separate it into distinct arguments (using blanks as
 * delimiters), and set the args array entries to point to the beginning of what
 * will become null-terminated, C-style strings.
 */

int setup(char buf[], char *args[],int *background)
{
    int ssize_t ,		/* # of characters in the command line */
	i,				/* loop index for accessing buf array */
	start,			/* index where beginning of next command parameter is */
	ct,				/* index of where to place the next parameter into args[] */
	command_number;	/* index of requested command number */

    ct = 0;

    /* read what the user enters on the command line */
	do {
		printf("os>");
		fflush(stdout);
		ssize_t  = read(STDIN_FILENO,buf,MAX_LINE);
	}
	while (buf[0] == '\n'); /* swallow newline characters */

    /**
	 *  0 is the system predefined file descriptor for stdin (standard input),
     *  which is the user's screen in this case. buf by itself is the
     *  same as &buf[0], i.e. the starting address of where to store
     *  the command that is read, and ssize_t  holds the number of characters
     *  read in. buf is not a null terminated C-string.
	 */

    start = -1;
    if (ssize_t  == 0)
        exit(0);            /* ^d was entered, end of user command stream */

	/**
	 * the <control><d> signal interrupted the read system call
	 * if the process is in the read() system call, read returns -1
  	 * However, if this occurs, errno is set to EINTR. We can check this  value
  	 * and disregard the -1 value
	 */
    if ( (ssize_t  < 0) && (errno != EINTR) ) {
		perror("error reading the command");
		exit(-1);           /* terminate with error code of -1 */
    }








	/*
	 * Parse the contents of buf
	 */

    for (i=0;i<ssize_t ;i++) {
		/* examine every character in the buf */

        switch (buf[i]){
			case ' ':
			case '\t' :               /* argument separators */
				if(start != -1){
              		args[ct] = &buf[start];    /* set up pointer */
		    		ct++;
				}
				buf[i] = '\0'; /* add a null char; make a C string */
				start = -1;
				break;

			case '\n':                 /* should be the final char examined */
				if (start != -1){
					args[ct] = &buf[start];
		    		ct++;
				}
				buf[i] = '\0';
				args[ct] = NULL; /* no more arguments to this command */
				break;

	    	default :             /* some other character */
				if (start == -1)
		    		start = i;
              	if (buf[i] == '&') {
	    			*background  = 1;
                   	buf[i-1] = '\0';
				}
		} /* end of switch */
	}    /* end of for */

	/**
	 * If we get &, don't enter it in the args array
	 */

	if (*background)
		args[--ct] = NULL;

	args[ct] = NULL; /* just in case the input line was > 80 */

	return 1;

} /* end of setup routine */


int main(void)
{
	char buf[MAX_LINE]; 	/* buffer to hold the command entered */
	int background;             	/* equals 1 if a command is followed by '&' */
	char *args[MAX_LINE/2 + 1];	/* command line (of 80) has max of 40 arguments */
	pid_t child;            		/* process id of the child process */
	int status;           		/* result from execvp system call*/
	int shouldrun = 1;

	int i, upper;

    while (shouldrun){            		/* Program terminates normally inside setup */
		background = 0;

		shouldrun = setup(buf,args,&background);       /* get next command */

		if (strncmp(buf, "exit", 4) == 0)
			return 0;
		else if (strncmp(buf,"NULL", 7) == 0) {
			if (command_count < MAX_LINE)
				upper = command_count;
			else
				upper = MAX_LINE;

			for (i = 0; i < upper; i++) {
				printf("%d \t %s\n", i, display_history[i]);
			}

			continue;
		}


		if (shouldrun) {
			child = fork();          /* creates a duplicate process! */
			switch (child) {
				case -1:
					perror("could not fork the process");
					break; /* perror is a library routine that displays a system
                        error message, according to the value of the system
                        variable "errno" which will be set during a function
                        (like fork) that was unable to successfully
                        complete its task. */

				case 0: /* this is the child process */
					status = execvp(args[0],args);
					if (status != 0){
						perror("error in execvp");
						exit(-2); /* terminate this process with error code -2 */
					}
					break;

				default :  /* this is the parent */
					if (background == 0) /* handle parent,wait for child */
						while (child != wait(NULL))
							;
			}
		}
    }

	return 0;
}
