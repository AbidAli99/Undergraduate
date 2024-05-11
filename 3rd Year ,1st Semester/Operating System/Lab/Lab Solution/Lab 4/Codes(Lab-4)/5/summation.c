#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

// structure for thread arguments
struct thread_args {
	int tid;
	int a;
	int b;
	double x;
	double result;
};

extern int shared;

// function that each thread will execute
void *SumExp(void *args_ptr) {
        int i;
  //	int a;
  //	int b;
	struct thread_args *myargs_ptr = (struct thread_args*) args_ptr;
	struct timeval tv1;
	struct timeval tv2;
	struct timezone tz; //just to pass to gettimeofday
	gettimeofday(&tv1, &tz);
	int startTime = tv1.tv_usec;
	myargs_ptr->result = 0;

	shared = 123;

	printf("Thread %d starting a= %d, b= %d, x= %lf\n",
			myargs_ptr->tid,
			myargs_ptr->a,
			myargs_ptr->b,
			myargs_ptr->x);
	//	a = myargs_ptr->a;
	//	b = myargs_ptr->b;
	
	/*
	//PROBLEM 2.6
	if (myargs_ptr->tid == 0){
	  printf("calling execl\n");
	  execl("/bin/ls", "wc", (char *) NULL);
	}*/

	for (i=myargs_ptr->a; i<myargs_ptr->b; i++) {
		myargs_ptr->result += pow(i, myargs_ptr->x);
	}
	/*
	//PROBLEM 2.5
	for (i=a; i < (b-((b-a)/2)); i++) {
		myargs_ptr->result += pow(i, myargs_ptr->x);
		//printf("IN 1: %f\n", myargs_ptr->result);
	}
	if (myargs_ptr->tid == 0){
	  printf("EXITING\n");
	  exit(0);
	}
	for (i = (a + (b-a)/2); i<b; i++) {
		myargs_ptr->result += pow(i, myargs_ptr->x);
		//printf("IN 2: %f\n", myargs_ptr->result);
	}

	*/


	printf("Thread %d done a= %d, b= %d, x= %lf -> result = %lf\n",
			myargs_ptr->tid,
			myargs_ptr->a,
			myargs_ptr->b,
			myargs_ptr->x,
			myargs_ptr->result);
	gettimeofday(&tv2, &tz);
	int endTime = tv2.tv_usec;
	time_t time = tv2.tv_sec;
	char buffer[30];
	ctime_r(&time, buffer);
	printf("Total time elapsed for process %d in microseconds: %d\n",myargs_ptr->tid,(endTime-startTime));
	printf("Current Time: %s\n", buffer);
	pthread_exit((void*) args_ptr);
}

int shared;

int main (int argc, char *argv[]) {




        pthread_attr_t attr;

	struct thread_args *targs; // array for thread argument structs
	struct thread_args **tstatus; // array of pointers to returns from threads
	pthread_t *tidp; // array for thread ids

	int ret_val;
	int i;
	//void *status;
	double summation = 0;

	int num_threads, increment; // command line parameters

	if (argc < 3) {
		printf("usage: summation [numthreads] [increment]\n");
		exit(-1);
	}

	num_threads = atoi(argv[1]);
	increment = atoi(argv[2]);

	targs = (struct thread_args *) calloc(num_threads, sizeof(struct thread_args));
	tstatus = (struct thread_args **) calloc(num_threads, sizeof(struct thread_args *));
	tidp = (pthread_t *) calloc(num_threads, sizeof(pthread_t));

	// initialize attr variable
	pthread_attr_init(&attr);

	// initialize thread detached state to joinable
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (i=0; i<num_threads; i++) {
		tstatus[i] = malloc(sizeof(struct thread_args));

		targs[i].a = increment*i;
		targs[i].b = increment*(i+1);
		targs[i].x = 2;
		targs[i].tid = i;
		targs[i].result = 0;

		ret_val = pthread_create(&tidp[i], &attr, SumExp, (void *) &targs[i]);
		if (ret_val) {
			printf("ERROR in pthread_create for thread %d: return value= %d\n", 
					i, ret_val);
			exit(-1);
		}
	}
	// free attribute variable
	pthread_attr_destroy(&attr);

	// main thread waits for spawned threads to terminate
	for(i=0; i<num_threads; i++) {
		//
		ret_val = pthread_join(tidp[i], (void **) &tstatus[i]);
		if (ret_val) {
			printf("ERROR in pthread_join() for thread %d = return value= %d\n",
					i, ret_val);
			exit(-1);
		}

		summation += tstatus[i]->result;
		printf("Joined thread %d; returned= %lf\n", i, tstatus[i]->result);
	}

	printf("Total value computed = %lf\n", summation);
	pthread_exit(NULL);
	printf("still here\n");
}
