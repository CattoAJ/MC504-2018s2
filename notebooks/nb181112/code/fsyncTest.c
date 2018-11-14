#include <stdio.h> 
#include <string.h> 
#include <assert.h>
#include <unistd.h> 
#include <fcntl.h> 

int main(void) {
    char buffer[12] = "hello world"; 
    int size = strlen(buffer);
    int fd = open("foo.txt", O_CREAT | O_WRONLY | O_TRUNC);
    assert ( !(fd < 0) );
    int rc = write(fd, buffer, size);
    assert (rc == size);
    rc = fsync(fd);
    assert (rc == 0);
    return 0;
}