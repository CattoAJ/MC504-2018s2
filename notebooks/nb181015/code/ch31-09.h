int buffer[MAX];
int fill = 0;
int use = 0;

void put(int value) {
    buffer[fill] = value;     // f1
    fill = (fill + 1) % MAX;  // f2
}

int get(void) {
int tmp = buffer[use];        // g1
use = (use + 1) % MAX;        // g2
return tmp;
