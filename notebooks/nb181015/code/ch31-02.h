
int sem_wait(sem_t *s)	{
	decrement the value of semaphore s by one;
	if value of semaphore s is negative
	    wait on s;
}

int sem_post(sem_t *s)	{
	increment the value of semaphore s by one;
	if there are one or more threads waiting on s
	    wake one up
}
