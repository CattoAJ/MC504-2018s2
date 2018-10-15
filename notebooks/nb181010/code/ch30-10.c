// Producer/Consumer: Two CVs and While Statement

cond_t not_empty, not_full;
mutex_t mutex;

void *producer(void *arg) {
    for (int i = 0; i < loops; i++)	{
        Pthread_mutex_lock(&mutex);                 // p1
        while (count == 1)                          // p2
            Pthread_cond_wait(&not_full, &mutex);   // p3
        put (i);                                    // p4
        Pthread_cond_signal(&not_empty);            // p5
        Pthread_mutex_unlock(&mutex);               // p6
    }
    return NULL;
}

void *consumer(void *arg) {
    for (int i = 0; i < loops; i++)	{
        Pthread_mutex_lock(&mutex);                 // c1
        while (count == 0)                          // c2
            Pthread_cond_wait(&not_empty, &mutex);  // c3
        int tmp = get();                            // c4
        Pthread_cond_signal(&not_full);             // c5
        Pthread_mutex_unlock(&mutex);               // c6
        printf("%d\n", tmp);
    }
    return NULL;
}