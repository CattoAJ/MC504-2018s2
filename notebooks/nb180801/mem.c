#include <stdio.h>
#include <unistd.h>
#include "common.h"

int main(void) {
    int mypid = getpid();
    int d = mypid % 10;
    int i = 0;
    int x = 0;
    double t;
    while (i < 5) {
        Spin(1);
        i = i + 1;
        x = x + d;
        t = GetTime();
        printf("(pid:%d) i:%d d:%d x:%02d t:%lf\n", mypid, i, d, x, t);
    }
    return 0;
}
