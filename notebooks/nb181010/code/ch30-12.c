cond_t not_empty, not_full;
mutex_t mutex;

void *producer(void *arg) {
    for (int i = 0; i < LOOPS; i++)	{
        mutex_lock(&mutex);                 // p1
        while (count == MAX)                // p2
            cond_wait(&not_full, &mutex);   // p3
        put(i);                             // p4
        cond_signal(&not_empty);            // p5
        mutex_unlock(&mutex);               // p6
    }
    return NULL;
}

void *consumer(void *arg) {
    for (int i = 0; i < loops; i++)	{
        mutex_lock(&mutex);                 // c1
        while (count == 0)                  // c2
            cond_wait(&not_empty, &mutex);  // c3
        int tmp = get();                    // c4
        ond_signal(&not_full);              // c5
        mutex_unlock(&mutex);               // c6
        printf("%d\n", tmp);
    }
    return NULL;
}