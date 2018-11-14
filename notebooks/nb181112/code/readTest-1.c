#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 

int main(void) { 
    int fd, sz; 
    char *c = (char *) calloc(100, sizeof(char)); 
    
    fd = open("foo.txt", O_RDONLY); 
    if (fd < 0) 
        { perror("r1"); exit(1); } 
    
    sz = read(fd, c, 20); 
    printf("System call read(%d, c, 20) returned that"
           " %d bytes  were read.\n", fd, sz); 
    c[sz] = '\0'; 
    printf("Those bytes were as follows: %s\n", c); 
} 