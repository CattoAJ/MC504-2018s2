#include <stdio.h>

typedef struct counter_t {
    int value;
} counter_t;

void init(counter_t *c) { 
    c->value = 0; 
}

void increment(counter_t *c) { 
    c->value++; 
}

void decrement(counter_t *c) { 
    c->value--; 
}

int get(counter_t *c) { 
    return c->value; 
}
