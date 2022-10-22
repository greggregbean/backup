#include "backupSetup.h"

int main(int argc, char* argv[]) {
    printf("\t!!!!!!!!!!!!!!!!!!!!!!!!!\n\t!!!!  Г  О  Й  Д  А  !!!!\n\t!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
  
    printf("Source name: \"%s\". \n", argv[1]);
    printf("Dest name: \"%s\". \n\n", argv[2]);

    printf("[____LIST_OF_SORCE____]\n");
    listFiles(argv[1]);
    printf("\n[____LIST_OF_DEST____]\n");
    listFiles(argv[2]);
}