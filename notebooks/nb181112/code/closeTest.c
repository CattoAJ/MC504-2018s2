#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 

int main(void) { 
    int fd1 = open("foo.txt", O_CREAT | O_RDONLY, 0); 
    if (fd1 < 0) 
        { perror("c1"); exit(1); }
     
    printf("opened fd = %d\n", fd1); 
      
    // Using close system Call 
    if (close(fd1) < 0) 
        { perror("c1"); exit(1); }

    printf("closed fd = %d\n", fd1); 
      
    // assume that bar.txt is already created 
    int fd2 = open("bar.txt", O_CREAT | O_RDONLY, 0);  
      
    printf("opened fd = %d\n", fd2); 
    exit(0); 
}  