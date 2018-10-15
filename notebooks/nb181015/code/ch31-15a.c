#include <stdio.h>

void think(void);
void getforks(void);
void eat(void);
void putforks(void);

int left(int p)  { return p; }
int right(int p) { return (p + 1) % 5; }

int main(int argc, char *argv[]) {
    while (1) {
        think();
        getforks();
        eat();
        putforks();
    }
    return 0;
}