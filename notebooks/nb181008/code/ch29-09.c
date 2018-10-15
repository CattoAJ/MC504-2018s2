typedef struct 	node_t {
    int	value;
    struct 	node_t *next;
} node_t;

typedef struct 	queue_t {
node_t *head;
node_t *tail;
Mutex_t headLock;
Mutex_t tailLock;
} queue_t;

void Queue_Init(queue_t *q)	{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->next = NULL;
    q->head = q->tail = tmp;
    Mutex_init(&q->headLock, NULL)
    Mutex_init(&q->tailLock, NULL)
}

void Queue_Enqueue(queue_t *q, int value) {
    node_t *tmp = Malloc(sizeof(node_t));
    tmp->value = value;
    tmp->next = NULL;
    Mutex_lock(&q->tailLock) ;
    q->tail->next = tmp;
    q->tail = tmp;
    Mutex_unlock(&q->tailLock) ;
}

int Queue_Dequeue(queue_t *q, int *value) {
    Mutex_lock(&q->headLock);
    node_t *tmp = q->head;
    node_t *newHead = tmp->next;
    if (newHead == NULL) {
        Mutex_unlock(&q->headLock) ;
        return -1; // queue was empty
    }
    *value = newHead->value;
    q->head = newHead;
    Mutex_unlock(&q->headLock) ;
    free(tmp);
    return 0;
}

