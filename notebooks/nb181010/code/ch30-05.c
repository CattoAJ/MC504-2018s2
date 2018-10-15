// Producer/Consumer Threads (Version 1)

#include <stdio.h>

void *producer(void *arg) {
    int loops = *((int *)arg);
    for (int i = 0; i < loops; i++)	{
        put(i);
    }
    return NULL;
}

void *consumer(void *arg) {
    while (1) {
        int tmp = get();
        printf("%d\n", tmp);
    }
    return NULL;
}
