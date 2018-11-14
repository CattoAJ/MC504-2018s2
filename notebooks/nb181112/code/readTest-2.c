#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 
    
int main() { 
    char c1, c2; 
    int fd1 = open("foo.txt", O_RDONLY, 0); 
    int fd2 = open("foo.txt", O_RDONLY, 0); 
    read(fd1, &c1, 1); 
    read(fd2, &c2, 1); 
    printf("c1 = %c\n", c1); 
    printf("c2 = %c\n", c2); 
    exit(0); 
} 
