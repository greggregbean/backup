#include "backupSetup.h"

void listFiles(const char* dirname) {
    DIR* dir = opendir(dirname);
    if(dir == NULL) printf("Failed to open \"%s\"! \n", dirname);

    printf("Reading files in: \"%s\". \n", dirname);

    struct dirent* entity;
    entity = readdir(dir);

    while(entity != NULL) {
        printf("%hhd %s/%s\n", entity->d_type, dirname, entity->d_name);
        if(entity->d_type == DT_DIR && (strcmp(entity->d_name, ".") != 0) && (strcmp(entity->d_name, "..") != 0)) {
            char path[MAXDIRNAME] = {'\0'};
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, entity->d_name);
            listFiles(path);
        }
        entity = readdir(dir);
    }

    closedir(dir);
}

struct dirent* find(struct dirent* entity, DIR* dir) {
    printf("Looking for \"%s\". \n", entity -> d_name);
    
    seekdir(dir, 0);
    struct dirent* iter = readdir(dir);

    while(!((strcmp(iter -> d_name, entity -> d_name) == 0) && (iter -> d_type != entity -> d_type)) && (iter != NULL)) {
        iter = readdir(dir);
    }

    if(iter != NULL) printf("FOUND! \n");
    else printf("NOT FOUND. \n");

    return iter; 
}

// void rec_backup(const char* source, char* dest) {
//     DIR* src_dir = opendir(source);
//     if(src_dir == NULL) printf("Failed to open source dir \"%s\"! \n", source); 

//     DIR* dst_dir = opendir(dest);
//     if(dst_dir == NULL) printf("Failed to open dest dir \"%s\"! \n", dest);
   

//     printf("Checking files in: \"%s\". \n", source);

//     struct dirent* src_entity;
//     src_entity = readdir(source);

//     while(src_entity != NULL) {
//         if(entity -> d_type == DT_DIR && (strcmp(entity -> d_name, ".") != 0) && (strcmp(entity -> d_name, "..") != 0)) {
//             dirent* res_of_find = find(entity, dest);
//             if(res_of_find == NULL) {
//                 printf("There is no \"%s\" in \"%s\". Copying. \n", src_entity -> d_name, dest);

//             }
//             char path[MAXDIRNAME] = {'\0'};
//             strcat(path, source);
//             strcat(path, "/");
//             strcat(path, entity->d_name);
//             listFiles(path);
//         }
//         src_dir = readdir(src_dir);
//     }

//     closedir(src_dir);
// }

