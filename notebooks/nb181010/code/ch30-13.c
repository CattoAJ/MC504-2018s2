
// how many bytes of the heap are free?
int bytesLeft = MAX_HEAP_SIZE;

// need lock and condition too
Cond_t c;
Mutex_t m;

void *allocate(int size) {
    Mutex_lock(&m);
    while (bytesLeft < size)
        Cond_wait(&c, &m);
    void *ptr = ...; // get mem from heap
    bytesLeft -= size;
    Mutex_unlock(&m);
    return ptr;
}

void free(void *ptr, int size) {
    Mutex_lock(&m);
    bytesLeft += size;
    Cond_signal(&c); // whom to signal??
    Mutex_unlock(&m);
}

