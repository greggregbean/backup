#include "backupSetup.h"

int main(int argc, char* argv[]) {                                                          
    printf("Source name: \"%s\". \n", argv[1]);
    printf("Dest name: \"%s\". \n\n", argv[2]);

    printf("List of source dir in \"file1.txt\". \n");
    listFiles(argv[1], "file1.txt");
    printf("List of dest dir in \"file2.txt\". \n");
    listFiles(argv[2], "file2.txt");

    printf("Looking for updated files. \n");
    update_check(argv[1], 1);

    update_dir(argv[2]);
}





