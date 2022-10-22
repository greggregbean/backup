#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    umask (0);
    char fifo_name[] = "fifo_file";
    if (mknod(fifo_name, S_IFIFO | 0666, 0)) {
        printf("Cant create fifo. \n");
        exit(-1);
    }

    int fd = 0;
    
    if(res > 0) {
        if ((fd = open (fifo_name, O_WRONLY)) < 0)
    }
}