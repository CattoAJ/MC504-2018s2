// (BUGGED) Parent Waiting For Child: No "done" Variable

#include <stdio.h>
#include "mythreads.h"

mutex_t m = PTHREAD_MUTEX_INITIALIZER;
cond_t c = PTHREAD_COND_INITIALIZER;

void thr_exit() {
    mutex_lock(&m) ;
    cond_signal(&c) ;
    mutex_unlock(&m);
}

void thr_join()	{
    mutex_lock(&m);
    cond_wait(&c, &m)
    mutex_unlock(&m);
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
