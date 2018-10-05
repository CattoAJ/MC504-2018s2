// Condition variables

int pthread_mutex_trylock(pthread_mutex_t *mutex);
int pthread_mutex_timelock(pthread_mutex_t *mutex,
                           struct timespec *abs_timeout);

// ...

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t init = PTHREAD_COND_INITIALIZER;

pthread_mutex_lock(&lock);
while (ready == 0)
  pthread_cond_wait(&init, &lock);
pthread_mutex_unlock(&lock);

// ...

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t init = PTHREAD_COND_INITIALIZER;

pthread_mutex_lock(&lock);
while (ready == 0)
  pthread_cond_wait(&init, &lock);
pthread_mutex_unlock(&lock);

// ...

pthread_mutex_lock(&lock);
ready = 1;
pthread_cond_signal(&init);
pthread_mutex_unlock(&lock);

// ...

// DON'T EVER DO THIS...

// A thread calling waiting start_routine
while (ready == 0)
  ; // spin

// A thread calling signal start_routine
ready = 1;
