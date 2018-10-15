enum { NUM_CPUS = 4 };

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include "mythreads.h"
#include "timespec_m.h"
#include "ch29-05.h"

counter_t ctr;

void *worker(void *pars) {
    int tID = *((int *) pars);
    for (int i = 0; i < 1000000; i++)
        update(&ctr, tID, 1);
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
    
    for (int p2 = 0; p2 <= 10; p2++) {
        int threshold = pow(2, p2);
        init(&ctr, threshold);

        clock_gettime(CLOCK_REALTIME, &t1);
        
        for (int i = 0; i < nThreads; i++)
            Pthread_create(&t[i], NULL, worker, &i);
            
        for (int i = 0; i < nThreads; i++)
            Pthread_join(t[i], NULL);
        
        clock_gettime(CLOCK_REALTIME, &t2);
        sub_timespec(t1, t2, &td);
        
        printf("threshold = %d\n", threshold);
        printf("nThreads  = %d\n", nThreads);
        printf("ctr       = %d\n", get(&ctr));
        
        enum {BUF_LEN = 9};
        char buf[BUF_LEN];
        fmt_timespec(&td, 6, buf, BUF_LEN);
        printf("time      = %s s\n\n", buf);
    }
}
