#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SCALE_FACTOR 1000

pthread_mutex_t chopsticks[5];
unsigned int seeds[5] = {100, 101, 102, 103, 104};

// FIGURE OUT HOW TO DO THE SEEDING
void wait(int t, int tid){
  float random;
  random = SCALE_FACTOR*(float)t*(float)rand_r(&seeds[tid])/(float)RAND_MAX;
  //printf("%f\n", random);
  usleep(random);
}


void * Philosopher (void *id){
  int ID = (int) id;
  while(1){
    if (ID < (ID+1)%5){ // true for every philosopher except last one
      printf("Philosopher %d is thinking.\n", ID);
      wait(2, ID);
      printf("Philosopher %d is hungry.\n", ID);
      pthread_mutex_lock(&chopsticks[ID]); // attempt to use left chopstick
      printf("Philosopher %d is picking up chopstick %d\n", ID, ID);
      //wait(1000, ID);
      pthread_mutex_lock(&chopsticks[(ID+1)%5]); //attempt to use right chopstick
      printf("Philosopher %d is picking up chopstick %d\n", ID, (ID+1)%5);
      printf("Philosopher %d starting to eat.\n", ID);
      wait(1, ID);
      printf("Philosopher %d is done eating.\n", ID);
      pthread_mutex_unlock(&chopsticks[(ID+1)%5]); // release right chopstick
      printf("Philosopher %d is putting down chopstick %d\n", ID, (ID+1)%5);
      pthread_mutex_unlock(&chopsticks[ID]); //release left chopstick
      printf("Philosopher %d is putting down chopstick %d\n", ID, ID);

    }
    else{ // ID > (ID+1)%5
      printf("Philosopher %d is thinking.\n", ID);
      wait(2, ID);
      printf("Philosopher %d is hungry.\n", ID);
      pthread_mutex_lock(&chopsticks[(ID+1)%5]); //attempt to use right chopstick
      printf("Philosopher %d is picking up chopstick %d\n", ID, (ID+1)%5);
      //wait(1000, ID);
      pthread_mutex_lock(&chopsticks[ID]); // attempt to use left chopstick
      printf("Philosopher %d is picking up chopstick %d\n", ID, ID);
      printf("Philosopher %d starting to eat.\n", ID);
      wait(1, ID);
      printf("Philosopher %d is done eating.\n", ID);
      pthread_mutex_unlock(&chopsticks[ID]); //release left chopstick
      printf("Philosopher %d is putting down chopstick %d\n", ID, ID);
      pthread_mutex_unlock(&chopsticks[(ID+1)%5]); // release right chopstick
      printf("Philosopher %d is putting down chopstick %d\n", ID, (ID+1)%5);
    }
  }
  // return 0;
}


int main(){
  pthread_t philos[5];
  int i;
  long long j;

  // initialize the mutexes
  for(i = 0; i < 5; i++){
    if(pthread_mutex_init(&chopsticks[i], NULL) != 0){
      printf("ERROR IN MUTEX %d CREATION!", i);
      exit(-1);
    }
  }
  // initialize philosphers
  for(j = 0; j < 5; j++){
    if(pthread_create(&philos[i], NULL, Philosopher, (void *) j)){
      printf("ERROR IN THREAD CREATION OF PHILOSOPHER %d", (int) j);
      exit(-1);
    }
  }
  sleep(10);
  // pthread_exit(NULL);
  //return 0;
}
