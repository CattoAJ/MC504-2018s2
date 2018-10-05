#include <pthread.h>

// How to create a thread

int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine)(void *), void *arg);
// thread: Used to interact with this thread
// attr:   Used to specify any attributes this thread might have,
//         e.g. Stack size, scheduling priority, …
// start_routine: The function this thread starts running in.
// arg:    The argument to be passed to start_routine.
//         A void pointer allows us to pass in any type of argument.

// How to wait for thread termination

int pthread_join(pthread_t thread, void **value_ptr);
// thread:     the descriptor of the thread we are waiting for.
// value_ptr:  address of pointer to where thread should return its results
