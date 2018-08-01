#include <stdio.h>
#include <unistd.h>
#include "common.h"

int main(void) {
    int mypid = getpid();
    int i = 0;
    while (i < 5) {
        Spin(1);
        i++;
        printf("(pid:%d) i:%d t:%d\n", mypid, i, (int) GetTime());
    }
    return 0;
}
