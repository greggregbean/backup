#include "backupSetup.h"

void update_dest(const char* dest) {
    char buf[MAX_BUF_SIZE] = {'\0'};

    int fd = open("file1.txt", O_RDONLY);
    if(fd == -1) {
        printf("Failed to open \"%s\". \n", dirname);
        exit(-1);
    }

    if(read(fd, buf, MAX_BUF_SIZE) == -1) {
        printf("Failed to read from\"%s\". \n", dirname);
        exit(-1);
    }
    
    
}

char* num_to_str(size_t num) {
    size_t num_cpy = num;

    char* str = (char*) calloc(MAX_NUM_SIZE, sizeof(char)); 
    char rev_str [MAX_NUM_SIZE] = {'\0'};

    int i = 0;
    while(num != 0) {
        rev_str[i] = '0' + num % 10;
        num /= 10;
        i++;
    }
    printf("rev_str: \"%s\". \n", rev_str);

    size_t len = strlen(rev_str);
    for(int k = 0; k != len; k++) {
        str[k] = rev_str[len-k-1];
    }
    printf("str: \"%s\". \n", str);

    return str;
}

void update_check(const char* dirname, size_t minutes) {
    if(dirname == NULL) {
        printf("Wrong name of directory! \n");
        exit(-1);
    }

    printf("Finding files updated %ld min ago in \"%s\". \n", minutes, dirname);

    pid_t pid = fork();

    int child_stat;
    wait(&child_stat);

    if(pid < 0) {
        printf("Failed to run child process. \n");
        exit(-1);
    }

    else if(pid > 0) {
        printf("Parent procces. PID = %d. Just waiting for child process. \n", getpid());
    }

    else {
        printf("Child process. PID = %d. We should run find. \n", getpid());

        char find_command[MAX_COMMAND_SIZE] = "find ";
        strcat(find_command, dirname);
        strcat(find_command, " -mmin ");
        strcat(find_command, num_to_str(minutes));
        strcat(find_command, " > ");
        strcat(find_command, "res_of_find.txt"); 
        execl("/bin/bash", "/bin/bash", "-c",  find_command, NULL);
        
    }
}

void listFiles(const char* dirname, const char* file) {
    if(dirname == NULL) {
        printf("Wrong name of directory! \n");
        exit(-1);
    }

    if(file == NULL) {
        printf("Wrong name of file! \n");
        exit(-1);
    }

    printf("Reading files in: \"%s\". \n", dirname);

    pid_t pid = fork();

    int child_stat;
    wait(&child_stat);

    if(pid < 0) {
        printf("Failed to run child process. \n");
        exit(-1);
    }

    else if(pid > 0) {
        printf("Parent procces. PID = %d. Just waiting for child process. \n", getpid());
    }

    else {
        printf("Child process. PID = %d. We should run ls in file. \n", getpid());

        char ls_command[MAX_COMMAND_SIZE] = "ls ";
        strcat(ls_command, "-R ");
        strcat(ls_command, dirname);
        strcat(ls_command, " > ");
        strcat(ls_command, file); 
        execl("/bin/bash", "/bin/bash", "-c",  ls_command, NULL);
    }
}


