#include "mysemaphore.h"

sem_t empty;
sem_t full;

void *producer(void *arg) {
    for (int i = 0; i < loops; i++)	{
        sem_wait(&empty) ;             // p1
        put(i);                        // p2
        sem_post(&full);               // p3
    }
}

void *consumer(void *arg) {
    int i, tmp;
    for (int i = 0; i < loops; i++)	{
        sem_wait(&full);               // c1
        tmp = get();                   // c2
        sem_post(&empty);              // c3
        printf("%d\n", tmp);
    }
}

int main(int argc, char *argv[])	{
    // ...
    sem_init(&empty, 0, MAX);  // MAX buffers are empty to begin with...
    sem_init(&full, 0, 0);	   // ... and 0 are full
    // . . .

}

