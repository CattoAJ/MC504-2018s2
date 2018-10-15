// Parent Waiting For Child: Use A Condition Variable

#include <stdio.h>
#include "mythreads.h"

int done = 0;
mutex_t m = PTHREAD_MUTEX_INITIALIZER;
cond_t c = PTHREAD_COND_INITIALIZER;

void thr_exit() {
    mutex_lock(&m);
    done = 1;
    cond_signal(&c);
    mutex_unlock(&m);
}

void thr_join() {
    mutex_lock(&m);
    if (done == 0)
        cond_wait(&c, &m);
    mutex_unlock(&m);
}

void *child(void *arg) {
    printf("child\n") ;
    thr_exit( ) ;
    return NULL;
}

int main(int argc, char *argv[]) {
    printf("parent: begin\n");
    pthread_t p;
    Pthread_create(&p, NULL, child, NULL);
    thr_join();
    printf("parent: end\n");
    return 0;
}
