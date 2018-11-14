#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

size_t read (int fd, void* buf, size_t cnt);
size_t write (int fd, void* buf, size_t cnt); 


int main(void) {
    char buffer[13] = "hello world\n";
    int size = strlen(buffer);
    int fd = open("rentest.tmp", O_WRONLY | O_CREAT | O_TRUNC);
    write(fd, buffer, size); // write out new version of file
    fsync(fd);
    close(fd);
    int renres = rename("rentest.tmp", "rentest.txt");
    printf("rename returned %d\n", renres);
    return 0;
}
