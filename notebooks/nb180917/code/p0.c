#include <stdio.h>
#include <assert.h>
#include <pthread.h>
#include "mythreads.h"

void *mythread(void *arg) {
	printf("%s\n", (char *) arg);
	return NULL;
}

int main(int argc, char *argv[]) {

	pthread_t p1, p2;
	printf("main : begin\n");
	Pthread_create(&p1, NULL, mythread, "A");
	Pthread_create(&p2, NULL, mythread, "B");

	// join waits for the threads to finish
	Pthread_join(p1, NULL);
	Pthread_join(p2, NULL);

	printf("main : end\n");
	return 0;
}

int pthread_create(pthread_t *thread, pthread_attr_t *attr,
                   void *func, void *arg);

int pthread_join(pthread_t thread, void **thread_return);
