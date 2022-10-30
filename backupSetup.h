#ifndef BACKUP_SETUP_H
#define BACKUP_SETUP_H

#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

#define MAX_NUM_SIZE 100
#define MAX_COMMAND_SIZE 100
#define MAX_BUF_SIZE 10000

char* num_to_str(size_t num);
void listFiles(const char* dirname, const char* file);
void update_check(const char* dirname, size_t minutes);
void update_dir(const char* dirname);

#endif