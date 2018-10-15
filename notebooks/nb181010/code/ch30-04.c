// Producer/Consumer: Put and Get Routines (Version 1)

#include <assert.h>

int buffer;
int count = 0; // initially, empty

void put(int value) {
    assert(count == 0);
    count = 1;
    buffer = value;
}

int get(void) {
    assert(count == 1);
    count = 0;
    return buffer;
}

