sem_t bs;

sem_init(&bs, 0, X) ;	// initialize semaphore to X. What should X be?

sem_wait(&bs);
// critical section here
sem_post(&bs);
