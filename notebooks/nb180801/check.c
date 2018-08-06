#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <assert.h>

double GetTime() {
    struct timeval t;
    int rc = gettimeofday(&t, NULL);
    assert(rc == 0);
    return (double)t.tv_sec + (double)t.tv_usec/1e6;
}

long int Spin(int howlong) {
    double t = GetTime();
    long int n = 0;
    while (n < 30000000) {
        double diff = (GetTime() - t) - (double)howlong;
        n++; // do nothing
    }
    return n;
}

int main(void) {
    int mypid = getpid();
    int i = 0;
    long int n;
    while (i < 5) {
        n = Spin(1);
        i++;
        printf("(pid:%d) i:%d n:%ld t:%f\n", mypid, i, n, GetTime());
    }
    return 0;
}
