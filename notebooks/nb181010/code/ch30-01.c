#include <stdio.h>

void *child(void *arg) {
    printf("child\n") ;
    // XXX how to indicate we are done?
    return NULL;
}

int main(int argc, char *argv[])	{
    printf("parent: begin\n");
    pthread_t c;
    Pthread_create(&c, NULL, child, NULL); // create child
    // XXX how to wait for child?
    printf("parent: end\n") ;
    return 0;
}
