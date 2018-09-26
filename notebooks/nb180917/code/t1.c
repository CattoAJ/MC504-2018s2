#include <stdio.h>
#include "mythreads.h"
#include <stdlib.h>
#include <pthread.h>

int max;
volatile int counter = 0; // shared global variable

void *mythread(void *arg) {
	char *letter = arg;
	int i;                                            // stack (private per thread)
	printf("%s: begin [addr of counter: %p] [addr of i: %p]\n",
	       letter, &counter, &i);
	for (i = 0; i < max; i++) {
		counter = counter + 1;                                    // shared: only one
	}
	printf("%s: done [i: %8d]\n", letter, i);
	return NULL;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "usage: main-first <loopcount>\n");
		exit(1);
	}
	max = atoi(argv[1]);

	pthread_t p1, p2;
	printf("main: begin [counter = %d] [addr of counter: %p]\n",
	       counter, &counter);
	Pthread_create(&p1, NULL, mythread, "A");
	Pthread_create(&p2, NULL, mythread, "B");
	// join waits for the threads to finish
	Pthread_join(p1, NULL);
	Pthread_join(p2, NULL);
	printf("main: done\n [counter: %8d]\n [should:  %8d]\n",
	       counter, max*2);
	return 0;
}
