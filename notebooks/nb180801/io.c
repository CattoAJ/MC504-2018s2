#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>

int main(void) {
    char fname[128], tbuffer[80], fbuffer[80];
    time_t timer;
    struct tm* tm_info;

    strcpy(fname, "/Users/arthur.catto/Documents/Unicamp/Disciplinas");
    strcat(fname, "/MC504/MC504-2018s2/github/notebooks/nb180801");
    strcat(fname, "/file.txt");
    int fd = open(fname, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    assert(fd >= 0);

    timer = time(NULL);
    tm_info = localtime(&timer);
    strftime(tbuffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    int rc = sprintf(fbuffer, "Time now = %s\n", tbuffer);
    assert(rc > 0);
    rc = write(fd, fbuffer, strlen(fbuffer));
    assert(rc == (strlen(fbuffer)));
    printf("wrote %d bytes\n", rc);
    close(fd);
    return 0;
}
