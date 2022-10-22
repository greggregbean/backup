#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int is_created = 0;
    key_t key;

    if((key = ftok("5sem1.c", 0)) < 0) {
        printf("Failed\n");
        exit(-1);
    }

    //Пытаемся создать сегмент
    int shmid;
    if((shmid = shmget(key, 10000, 0666|IPC_CREAT|IPC_EXCL)) < 0) {
        if(errno != EEXIST) { //Если сегмент не создан
            printf("Failed to create shmem\n");
            exit(-1);
        }

        if ((shmid = shmget(key, 10000, 0)) < 0) {
            printf("Failed to find shmem\n");
            exit(-1);
        }

        is_created = 1;
    } 

    // Отражение сегмента в адресное пространство процесса
    char* ptr;
    if((ptr = (char*)shmat(shmid, NULL, 0)) == (char*)(-1)) {
        printf("Failed to attach shmem\n");
        exit(-1);
    }

    //Самопечать
    int fd = 0;
    if ((fd = open("5sem1.c", O_RDONLY)) < 0) {
        printf("Failed to open file. \n");
        exit(-1);
    }

    printf("Файловый дескриптор fd = %d. \n", fd);

    
    read(fd, ptr, 10000);

    if(close(fd) < 0) {
        printf("Failed. \n");
    }

    return 0;
}