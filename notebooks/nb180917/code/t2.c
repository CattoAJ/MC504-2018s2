#include <stdio.h>
#include "mythreads.h"
#include <pthread.h>
#include <stdlib.h>

#define N 100
#define NUM_THREADS 6

void *adder(void *param); /* the thread */

int main(void) {
	pthread_t tid[NUM_THREADS];                     /* thread ids */
	int thread_arg[NUM_THREADS][4];
	int sum = 0;
	int range = N / NUM_THREADS;

	/* create the threads */
	for (int i = 0; i < NUM_THREADS; ++i) {
		thread_arg[i][0] = i;
		thread_arg[i][1] = i * range + 1;
		thread_arg[i][2] = (i == NUM_THREADS-1) ? N : (i+1) * range;
		printf("Main creating thread %d to sum %3d to %3d.\n",  i, thread_arg[i][1], thread_arg[i][2]);
		Pthread_create(&tid[i], NULL, adder,  (void *) &thread_arg[i][0]);
	}

	/* wait for the threads to exit and calculate total */
	for (int i = 0; i < NUM_THREADS; ++i) {
		Pthread_join(tid[i], NULL);
		printf("Thread %d returned %d.\n", i, thread_arg[i][3]);
		sum += thread_arg[i][3];
	}

	printf("Main again... sum = %d.\n", sum);
}

void *adder(void *param) {
	int i;
	int ix    = *((int *)param);
	int lower = *((int *)param + 1);
	int upper = *((int *)param + 2);

	printf("Thread %d summing %3d to %3d...\n",  ix, lower, upper);

	int sum = 0;

	for (i = lower; i <= upper; i++)
		sum += i;

	*((int *)param + 3) = sum;
	printf("Thread %d summed %3d to %3d... Result %d.\n",  ix, lower, upper, sum);

	pthread_exit(NULL);
}
