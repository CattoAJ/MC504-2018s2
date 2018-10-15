#include "mysemaphore.h"

sem_t empty;
sem_t full;
sem_t mutex;

void *producer(void *arg) {
    for (int i = 0; i < loops; i++)	{
        sem_wait(&mutex);
        sem_wait(&empty);
        put(i);
        sem_post(&full);
        sem_post(&mutex);
    }
}

void *consumer(void *arg) {
    for (int i =0; i < loops; i++)	{
        sem_wait(&mutex);
        sem_wait(&full);
        int tmp = get ( );
        sem_post(&empty);
        sem post(&mutex);
        printf("%d\n", tmp);
    }
}

int main(int arge, char *argv[]) {
    // ...
    sem_init(&empty, 0, MAX); // MAX buffers are empty to begin with...
    sem_init(&full, 0, 0);    // ... and 0 are full
    sem_init(&mutex, 0, 1);	  // mutex = l because it is a lock
    // ...
}

