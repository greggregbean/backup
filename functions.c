#include "backupSetup.h"

void listFiles(const char* dirname) {
    DIR* dir = opendir(dirname);
    if(dir == NULL) {
        return;
    }

    printf("Reading files in: \"%s\". \n", dirname);

    struct dirent* entity;
    entity = readdir(dir);

    while(entity != NULL) {
        printf("%hhd %s/%s\n", entity->d_type, dirname, entity->d_name);
        if(entity->d_type == DT_DIR && (strcmp(entity->d_name, ".") != 0) && (strcmp(entity->d_name, "..") != 0)) {
            char path[100] = { 0 };
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, entity->d_name);
            listFiles(path);
        }
        entity = readdir(dir);
    }

    closedir(dir);
}

dirent* find(const dirent* entity, DIR* dir) {
    seekdir(dir, 0);
    struct dirent* iter = readdir(dir);

    while(!((strcmp(iter -> d_name, entity -> d_name) == 0) && (iter -> d_type != entity -> d_type)) && (iter != NULL)) {
        iter = readdir(dir);
    }

    return dirent; 
}

void recCpy(const char* source, char* dest) {
    DIR* src_dir = opendir(source);
    if(src_dir == NULL) printf("Failed to open source directory! \n");
    DIR* dst_dir = opendir(dest);
    if(dst_dir == NULL) printf("Failed to open destination directory! \n");

    if(src_dir == NULL) {
        return;
    }

    printf("Checking files in: \"%s\". \n", source);

    struct dirent* src_entity;
    src_entity = readdir(source);

    struct dirent* dst_entity;
    dst_entity = readdir(dest);

    while(entity != NULL) {
        printf("%hhd %s/%s\n", entity -> d_type, source, entity -> d_name);
        if(entity -> d_type == DT_DIR && (strcmp(entity -> d_name, ".") != 0) && (strcmp(entity -> d_name, "..") != 0)) {
            dirent* res_of_find = find(entity, dest);
            
            char path[MAXDIRNAME] = {'\0'};
            strcat(path, source);
            strcat(path, "/");
            strcat(path, entity->d_name);
            listFiles(path);
        }
        src_dir = readdir(src_dir);
    }

    closedir(src_dir);
}

