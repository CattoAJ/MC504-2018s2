// POSIX OPERATIONS ON CONDITION VARIABLES
   
// declaring a condition variable
pthread_cond_t c;

// declaring and initializing a condition variable
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

// waiting on a condition variable
pthread_cond_wait(pthread_cond_t *c, pthread_mutex_t *m);

// signalling on a condition variable
pthread_cond_signal(pthread_cond_t *c);
