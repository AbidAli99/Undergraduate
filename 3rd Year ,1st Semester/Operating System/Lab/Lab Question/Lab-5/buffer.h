typedef int buffer_item;
#define BUFFER_SIZE 10
#include <semaphore.h>

//mutex is used to provide mutual exclusion for critical section
//empty is the number of empty slots in buffer
//full is the number of slots filled
sem_t full, empty, mutex;

int in = 0; //index at which producer will put the next data
int out = 0; // index from which the consumer will consume next data

buffer_item buffer[BUFFER_SIZE];

int insert_item(buffer_item item);

int remove_item(buffer_item* item);