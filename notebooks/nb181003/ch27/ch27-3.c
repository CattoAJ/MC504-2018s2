#include "mythreads.h"
#include <stdio.h>

// A program passing a simple argument to and
// receiving a simple result from
// a thread it creates

void *mythread(void *arg) {
  int m = (int)arg;
  printf("% d\n", m);
  return (void *)(arg + 1);
}

int main(int argc, char *argv[]) {
  pthread_t p;
  int m;
  Pthread_create(&p, NULL, mythread, (void *)100);
  Pthread_join(p, (void **)&m);
  printf("returned % d\n", m);
  return 0;
}
