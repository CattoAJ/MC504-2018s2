// (BUGGED) Parent Waiting For Child: No Mutex

#include <stdio.h>
#include "mythreads.h"

int done = 0;
cond_t c = PTHREAD_COND_INITIALIZER;

void thr_exit() {
    done = 1;
    cond_signal(&c);
}

void thr_join()	{
    if (done == 0)
        cond_wait(&c)
}

void *child(void *arg) {
    printf("child\n") ;
    thr_exit( ) ;
    return NULL;
}

int main(int arge, char *argv[]) {
    printf("parent: begin\n");
    pthread_t p;
    Pthread_create(&p, NULL, child, NULL);
    thr_join();
    printf("parent: end\n");
    return 0;
}
