
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
// Set two matrix sizes 500x500 and 50x50
#define M 500
#define N 500

int main(int argc, char *argv)
{   
    //set number of threads here.That is 1,4,8,16
    omp_set_num_threads(8);
    int i,j,k;
    double sum;
    double start, end, start_p, end_p;
    double **A, **B, **C;
    /* FILE *fp; C provides a number of build-in function to perform basic file operations: 
                                                                                           fopen() - create a new file or open a existing file. 
                                                                                           fclose() - close a file  */
    
    FILE *fp;  // Create file pointers.
    A= malloc(M*sizeof(double *));
    B= malloc(M*sizeof(double *));
    C= malloc(M*sizeof(double *));
   
    /* After a call to freopen, it associates STDOUT to file file.txt, so whatever we write at STDOUT that goes inside file.txt */
   
    fp = freopen("file.txt", "w+", stdout);
    for(i=0; i<M; i++)
    {
        A[i]= malloc(N*sizeof(double));
        B[i]= malloc(N*sizeof(double));
        C[i]= malloc(N*sizeof(double));
    }
    //initialize matrix A, B, C  
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            A[i][j]=j*1;
            B[i][j]=i*j+2;
            C[i][j]=j-i*2;
        }
    }
    printf("MATRIX A:\n");
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            printf("%f ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("MATRIX B:\n");
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            printf("%f ",B[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    start= omp_get_wtime(); //start time measurement
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            sum=0;
            for(k=0; k<M; k++)
            {
                sum+=A[i][k]*B[k][j];
            }
            C[i][j]=sum;
        }
    }
    end= omp_get_wtime();
    printf("Serial Execution Time: %f\n\n",(end-start));
    //////////////////////////////////
    start_p= omp_get_wtime();
    #pragma omp parallel for
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            sum=0;
            for(k=0; k<M; k++)
            {
                sum+=A[i][k]*B[k][j];
            }
            C[i][j]=sum;
        }
    }
    end_p= omp_get_wtime(); //end time measurement
    printf("Parallel Execution Time: %f\n\n",(end_p-start_p));
    printf("MATRIX MULTIPLICATION, MATRIX C:\n");
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            printf("%f ",C[i][j]);
        }
        printf("\n");
    }
    // Closing the file using fclose() function.
    fclose(fp);

    return 0;
}