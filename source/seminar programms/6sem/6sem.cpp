#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int a = 0;

struct name_and_content {
    char name_of_file[100];
    char content[10000];
};

void* reader(void* param) {
    int fd = open(((name_and_content*)param) -> name_of_file, O_RDONLY);
    if(fd == -1) printf("Failed to open file. \n");
    read(fd, ((name_and_content*)param) -> content, 10000);
    close (fd);
}


int main(int argc, char* argv[]) {
    name_and_content param;

    pthread_t main_thid = pthread_self();
    pthread_t thid;

    scanf("%s", &(param.name_of_file));

    int res = pthread_create(&thid, NULL, reader, &param);
    if(res > 0) {
        printf("Failed to create thread. \n");
        exit(-1);
    }

    pthread_join(thid, NULL);

    printf("%s", param.content);

    return 0; 
}