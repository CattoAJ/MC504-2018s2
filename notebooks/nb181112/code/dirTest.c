#include <assert.h>
//#include <fcntl.h>
#include <stdio.h>
//#include <string.h>
//#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    
struct dirent {
    char		d_name[256]; 	/* filename */
    ino_t	  	d_ino;		/* inode number */
    off_t	  	d_off;		/* offset to the next direct */
    unsigned short	d_reclen;		/* length of this record */
    unsigned char	d_type;		/* type of file */
}

int link(const char *path1, const char *path2);
    
    
    DIR *dp = opendir("."); 		    // open current directory
    assert(dp != NULL);
    struct dirent *d;
    while ((d = readdir(dp)) != NULL)	// read one directory entry 
    {
        // print outthe name and inode number of each file
        printf("%d %s\n", (int) d->d_ino, d->d_name);
    }
    closedir(dp); 			            // close current directory
    return 0;
}
