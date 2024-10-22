#include "mythreads.h"
#include <stdio.h>
#include <stdlib.h>

volatile int counter = 0;
int loops;
Mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
;

void *worker(void *arg) {
  int i;
  for (i = 0; i < loops; i++) {
    Mutex_lock(&lock);
    counter++;
    Mutex_unlock(&lock);
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  if (argc < 2)
    loops = 1000000;
  else
    loops = atoi(argv[1]);

  pthread_t p1, p2;
  printf("Initial value: %d\n", counter);

  Pthread_create(&p1, NULL, worker, NULL);
  Pthread_create(&p2, NULL, worker, NULL);

  Pthread_join(p1, NULL);
  Pthread_join(p2, NULL);
  printf("Final value: %d\n", counter);
  return 0;
}
