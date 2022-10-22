#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd = 0;
    if ((fd = open("third.cpp", O_RDONLY)) < 0) {
        printf("Failed to open file. \n");
        exit(-1);
    }

    printf("Файловый дескриптор fd = %d. \n", fd);

    char str[1000] = {'\0'};
    int nbytes = 1000;
    read(fd, str, nbytes);

    if(close(fd) < 0){
        printf("Failed. \n");
    }

    int i = 0;

    while(str[i] != '\0')
    {
        printf("%c", str[i]);
        i++;
    }
    printf("\n");
    
    return 0;
}