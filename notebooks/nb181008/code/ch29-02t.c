#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "mythreads.h"
#include "ch29-02.h"
#include "timespec_m.h"

counter_t ctr;

void *worker(void *arg) {
    for (int i = 0; i < 1000000; i++)
        increment(&ctr);
    return NULL;
}

int main(int argc, char *argv[]) {
    int nThreads;
    if (argc < 2)
        nThreads = 1;
    else {
        nThreads = atoi(argv[1]);
    }
    
    struct timespec t1, t2, td;
    pthread_t t[10];
    
    clock_gettime(CLOCK_REALTIME, &t1);
    
    init(&ctr);
    for (int i = 0; i < nThreads; i++)
        Pthread_create(&t[i], NULL, worker, NULL);
        
    for (int i = 0; i < nThreads; i++)
        Pthread_join(t[i], NULL)
    
    
    clock_gettime(CLOCK_REALTIME, &t2);
    sub_timespec(t1, t2, &td);
    
    printf("nThreads = %d\n", nThreads);
    printf("ctr      = %d\n", ctr.value);
    
    enum {BUF_LEN = 9};
    char buf[BUF_LEN];
    fmt_timespec(&td, 6, buf, BUF_LEN);
    printf("time     = %s s\n", buf);
}
