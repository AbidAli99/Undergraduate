#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
#include<omp.h>
#include<time.h>
int main(){
  struct timeval tv;
  time_t t;
  struct tm *info;
  char buffer[64];

  gettimeofday(&tv, NULL);
  t = tv.tv_sec;
  int n,sum=0;
  double bf = omp_get_wtime();
  double af;
  printf("=================================================================================\n");
  printf("Suppose\n");
  printf("If we want sum of first 6th consecutive term.\n");
  printf("In the program,the value of 'n' represents that sum of 6th consecutive terms.\n");
  printf("1+4+9+16+25+36 = 91\n");
  printf("=================================================================================\n");
  printf("Please enter n value: ");
  scanf("%d", &n);
  for(int i=0; i<=n; i++)
    {
         sum += (i*i);
         af = omp_get_wtime();
    }
  printf("Sum of squares of first %d natural numbers = %d      Time: %fs\n", n, sum, af-bf);
  info = localtime(&t);
  printf("%s",asctime (info));
  strftime (buffer, sizeof buffer, "Today is %A, %B %d.\n", info);
  printf("%s",buffer);
  strftime (buffer, sizeof buffer, "The time is %I:%M %p.\n", info);
  printf("%s",buffer);
  return 0;
  }
