#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(void) {
    int mypid = getpid();
    int d = mypid % 10;
    int i = 0;
    int x = 0;
    while (i < 5) {
        Spin (1);
        i = i + 1;
        x = x + d;
        printf("(%d) i:%d x:%d\n", mypid, i, x);
    }
    return 0;
}
