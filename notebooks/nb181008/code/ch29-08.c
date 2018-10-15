void List_Init(list_t *L)	{
    L->head = NULL;
    Mutex_init(&L->lock, NULL);
}

void List_Insert(list_t *L, int key) {
    // synchronization not needed
    node_t *new = malloc(sizeof(node_t));
    if (new == NULL) {
        perror("malloc" ) ;
        return;
    }
    new->key = key;
    // just lock critical section
    Mutex_lock(&L->lock);
    new->next = L->head;
    L->head = new;
    Mutex_unlock(&L->lock);
}

int List_Lookup(list_t *L, int key) {
    int rv = -1;
    Mutex_lock (&L->lock);
    node_t *curr = L->head;
    while (curr) {
        if (curr->key == key) {
            rv = 0;
            break;
        }
        curr = curr->next;
    }
    Mutex_unlock(&L->lock);
    return rv; // now both success and failure
}

