// (BUGGED) Producer/Consumer: Single CV and While Statement

cond_t cond;
mutex_t mutex;

void *producer(void *arg) {
    for (int i =0; i < loops; i++)	{
        mutex_lock(&mutex);            // p1
        while (count == 1)                     // p2
            cond_wait(&cond, &mutex);  // p3
        put (i);                               // p4
        cond_signal(&cond);            // p5
        mutex_unlock(&mutex);          // p6
    }
    return NULL;
}

void *consumer(void *arg) {
    for (int i =0; i < loops; i++) {
        mutex_lock(&mutex);            // c1
        while (count == 0)                     // c2
            cond_wait(&cond, &mutex);  // c3
        int tmp = get();                       // c4
        cond_signal(&cond);            // c5
        mutex_unlock(&mutex);          // c6
        printf("%d\n", tmp);
    }
    return NULL;
}