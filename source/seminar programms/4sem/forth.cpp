#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {

    int fd[2];
    if ((pipe(fd)) < 0) {
        printf("Failed to create a pipe. \n");
        exit(-1);
    }

    pid_t ret;

    switch(ret = fork())
    {
        case 0:
            if(read(fd[0], str, nbytes) != nbytes) {
                printf("Failed to read all string. \n");
                exit(-1);
            }

            for (int i = 0; str[i] != '\0', i++)
            {
                printf("%c", str[i]);
            }

            exit(0);

        default:
            char str[] = "Hello world! \n";
            size_t nbytes = strlen(str) + 1;

            if(write(fd[1], str, nbytes) != nbytes) {
                printf("Failed to write all string. \n");
                exit(-1);
            }

            close(fd[1]);
            char* res = (char*) calloc(nbytes, 1);

            if(read(fd[0], res, nbytes) < 0) {
                printf("Failed to read from pipe. \n");
                exit(-1);
            }

            close(fd[0]);

            printf("%s", res);
    }
    return 0;
}