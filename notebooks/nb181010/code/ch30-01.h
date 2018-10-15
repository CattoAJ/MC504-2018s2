POSIX Operations on Condition Variables

\\ Including mythreads.h header
#include "mythreads.h"

\\ Declaring a condition variable
cond_t cv;
\\ Declaring and initializing a condition variable
cond_t cv = PTHREAD_COND_INITIALIZER;
\\ Waiting on a condition variable
cond_wait(cond_t *cv, mutex_t *m);
\\ Signalling on a condition variable
cond_signal(cond_t *cv);
