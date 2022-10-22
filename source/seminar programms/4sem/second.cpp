#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd = 0;
    if ((fd = open("file.txt", O_WRONLY | O_CREAT | O_APPEND, 0666)) < 0) {
        printf("Failed to open file. \n");
        exit(-1);
    }

    printf("Файловый дескриптор fd = %d. \n", fd);

    char str[] = "Hello world!\n";
    size_t nbytes = strlen(str) + 1;
    if(write(fd, str, nbytes) != nbytes) {
        printf("Failed. \n");
    }

    if(close(fd) < 0){
        printf("Failed. \n");
    }

    printf("Hello world in your file! \n");

    return 0;
}