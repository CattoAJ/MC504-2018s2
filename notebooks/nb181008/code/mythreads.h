#ifndef __MYTHREADS_h__
#define __MYTHREADS_h__

// Wrapper macros and functions for the pthread package

#include <pthread.h>
#include <assert.h>
#include <sched.h>
#include <stdlib.h>

#ifdef __linux__
#include <semaphore.h>
#endif

#define Pthread_create(thread, attr, start_routine, arg)    assert(pthread_create(thread, attr, start_routine, arg) == 0);
#define Pthread_join(thread, value_ptr) assert(pthread_join(thread, value_ptr) == 0);

#define Pthread_mutex_init(thread, arg)    assert(pthread_mutex_init(thread, arg) == 0);
#define Pthread_mutex_lock(m)   assert(pthread_mutex_lock(m) == 0);
#define Pthread_mutex_unlock(m) assert(pthread_mutex_unlock(m) == 0);

#define Pthread_cond_init(cond) assert(pthread_cond_init(cond, NULL) == 0);
#define Pthread_cond_signal(cond)   assert(pthread_cond_signal(cond) == 0)
#define Pthread_cond_wait(cond, mutex)  assert(pthread_cond_wait(cond, mutex) == 0);

#define Mutex_t pthread_mutex_t
#define Mutex_init(m)   assert(pthread_mutex_init(m, NULL) == 0);
#define Mutex_lock(m)   assert(pthread_mutex_lock(m) == 0);
#define Mutex_unlock(m) assert(pthread_mutex_unlock(m) == 0);

#define Cond_init(cond) assert(pthread_cond_init(cond, NULL) == 0);
#define Cond_signal(cond)   assert(pthread_cond_signal(cond) == 0);
#define Cond_wait(cond, mutex)  assert(pthread_cond_wait(cond, mutex) == 0);

void *Malloc (size_t nbytes) {
    void *ptr;
    ptr = malloc (nbytes);
    assert(ptr != NULL);
    return ptr;
}

#ifdef __linux__
#define Sem_init(sem, value)    assert(sem_init(sem, 0, value) == 0);
#define Sem_wait(sem)   assert(sem_wait(sem) == 0);
#define Sem_post(sem)   assert(sem_post(sem) == 0);
#endif // __linux__

#endif // __MYTHREADS_h__
