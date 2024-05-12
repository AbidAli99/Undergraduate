#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
// Set two matrix sizes 500x500 and 50x50
#define M 500
#define N 500
// Threads set to 1,4,8,16
#define Max_threads 16

int main(int argc, char *argv) {
 omp_set_num_threads(Max_threads);//set number of threads here
 int i, j, k;
 double sum;
 double start, end; // used for timing
 double **A, **B, **C;
   /* FILE *fp; C provides a number of build-in function to perform basic file operations: 
                                                                                           fopen() - create a new file or open a existing file. 
                                                                                           fclose() - close a file  */
    
    //FILE *fp;  // Create file pointers.
 A = malloc(M*sizeof(double *));
 B = malloc(M*sizeof(double *));
 C = malloc(M*sizeof(double *));
     /* After a call to freopen, it associates STDOUT to file file.txt, so whatever we write at STDOUT that goes inside file.txt */
   
    //fp = freopen("file.txt", "w+", stdout);

 for (i = 0; i < M; i++) {
    A[i] = malloc(N*sizeof(double));
    B[i] = malloc(N*sizeof(double));
    C[i] = malloc(N*sizeof(double));
 }
//initialize matrix A, B, C  
 for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
        A[i][j] = j*1; 
        B[i][j] = i*j+2;
        C[i][j] = j-i*2;
    }
 }
 start = omp_get_wtime(); //start time measurement

 for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
        sum = 0;
        for (k=0; k < M; k++) {
            sum += A[i][k]*B[k][j];
    }
    C[i][j] = sum;
    }
 }
 end = omp_get_wtime(); //end time measurement
 printf("Time of computation: %f\n", end-start);
     // Closing the file using fclose() function.
    //fclose(fp);
}
