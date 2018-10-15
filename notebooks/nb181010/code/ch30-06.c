// (BUGGED) Producer/Consumer: Single CV and If Statement

#include <stdio.h>
#include "mythreads.h"

cond_t cond;
mutex_t mutex;

#include "ch30-04.c"

void *producer(void *arg) {
    int loops = (int) arg;
    for (int i = 0; i < LOOPS; i++)	{
        mutex_lock(&mutex);            // p1
        if (count == 1)                // p2
            cond_wait(&cond, &mutex);  // p3
        put(i);                        // p4
        cond_signal(&cond);            // p5
        mutex_unlock(&mutex);          // p6
    }
    return NULL;
}

void *consumer(void *arg) {
    for (int i = 0; i < LOOPS; i++)	{
        mutex_lock(&mutex);            // c1
        if (count == 0)                // c2
            cond_wait(&cond, &mutex);  // c3
        int tmp = get();               // c4
        cond_signal(&cond);            // c5
        mutex_unlock(&mutex);          // c6
        printf("%d\n", tmp);
    }
    return NULL;
}