#include <stdio.h>
#include "mythreads.h"

// basic node structure
typedef struct node_t {
    int key;
    struct node_t *next;
} node_t;

// basic list structure (one used per list)
typedef struct list_t {
    node_t *head;
    Mutex_t lock;
} list_t;

void List_Init(list_t *L) {
    L->head = NULL;
    Mutex_init(&L->lock);
}

int List_Insert(list_t *L, int key) {
    Mutex_lock(&L->lock);
    node_t *new = malloc(sizeof(node_t));
    if (new == NULL) {
        perror("malloc");
        Mutex_unlock(&L->lock);
        return -1; // fail
    }
    new->key = key;
    new->next = L->head;
    L->head = new;
    Mutex_unlock(&L->lock);
    return 0; // success
}

int List_Lookup(list_t *L, int key) {
    Mutex_lock(&L->lock);
    node_t *curr = L->head;
    while (curr) {
        if (curr->key == key) {
            Mutex_unlock(&L->lock);
            return 0; // success
        }
        curr = curr->next;
    }
    Mutex_unlock(&L->lock);
    return -1; // failure
}
