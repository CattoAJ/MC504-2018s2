#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(void) {
    int *p = malloc(sizeof (int) );
    assert (p != NULL);
    printf("(%d) address pointed to by p: %p\n", getpid(), p);
    *p = 0;
    while (*p < 5) {
        Spin (1);
        *p = *p + 1;
        printf("(%d) p: %d\n", getpid(), *p);
    }
    return 0;
}
