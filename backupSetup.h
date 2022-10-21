#ifndef BACKUP_SETUP_H
#define BACKUP_SETUP_H

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXDIRNAME 100

void rec_cpy(char* src_dir, char* dst_dir);

#endif