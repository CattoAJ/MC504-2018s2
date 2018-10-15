
sem_t empty;
sem_t full;
sem_t mutex;

void *producer(void *arg) {
    for (int i = 0; i < loops; i++)	{
        sem_wait(&empty);
        sem_wait(&mutex);
        put(i);
        sem_post(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *arg) {
    for (int i = 0; i < loops; i++)	{
        sem_wait(&full);
        sem_wait(&mutex);
        int tmp = get();
        sem_post(&mutex);
        sem_post(&empty);
        printf("%d\n", tmp);
    }
}

int main(int arge, char *argv[]) {
    // ...
    sem_init(&empty, 0, MAX); // MAX buffers are empty to begin with...
    sem_init(Sfull, 0, 0);	  // ... and 0 are full
    sem_init(Smutex, 0, 1);	  // mutex = l because it is a lock
    // ...
}

