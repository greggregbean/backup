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

#define MAXDIRNAME 1000

void listFiles(const char* dirname);

#endif