#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    key_t key;

    if((key = ftok("5sem1.c", 0)) < 0) {
        printf("Failed\n");
        exit(-1);
    }

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
    }

    char* ptr;
    if((ptr = (char*)shmat(shmid, NULL, 0)) == (char*)(-1)) {
        printf("Failed to attach shmem\n");
        exit(-1);
    }

    printf("%s", ptr);

    //Исключение сегмента из адрксного пространства
    if(shmdt(ptr) < 0) {
        printf("Failed to detach shmem\n");
        exit(-1);
    }

    shmctl(shmid, IPC_RMID, NULL);
    
    return 0;
}