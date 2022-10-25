#include "backupSetup.h"

int main(int argc, char* argv[]) {
                                                           
    printf("Source name: \"%s\". \n", argv[1]);
    printf("Dest name: \"%s\". \n\n", argv[2]);

    printf("[____LIST_OF_SORCE____]\n");
    listFiles(argv[1]);
    printf("\n[____LIST_OF_DEST____]\n");
    listFiles(argv[2]);

    DIR* src_dir = opendir(argv[1]);
    DIR* dst_dir = opendir(argv[2]);
    
    struct dirent* first_src_dir = readdir(src_dir);
    printf("First dir in \"%s\" is \"%s\". \n", argv[1], first_src_dir -> d_name);
    find(first_src_dir, dst_dir);

}