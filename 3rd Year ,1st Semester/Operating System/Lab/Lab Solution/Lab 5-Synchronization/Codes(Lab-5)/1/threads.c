#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>

pthread_t tid[2];
sem_t m;
int counter;
void* doSomeThing(void *arg)
{
    unsigned long i = 0;
    sem_wait(&m);
    counter += 1;
    
    		printf("\n Job %d started\n", counter);
    for(i=0; i<1000;i++);
            //sem_wait (&m);
    		printf("\n Job %d finished\n", counter);
    
    sem_post(&m);
    return NULL;
}

int main(void)
{
    int i = 0;
    int err;
    sem_init(&m,0,1);
    while(counter < 2)
    {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
   // sleep(10);
    return 0;
}
