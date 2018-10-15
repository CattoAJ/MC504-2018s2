
void getforks(void) {
    sem_wait(forks[left(p)]);
    sem_wait(forks[right(p)]);
}

void putforks(void) {
    sem_post(forks[left(p)]);
    sem_post(forks[right(p)]);
}
