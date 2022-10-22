#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <errno.h>


int main()
{
    int number;
    if (number == 0)
        printf("Zero\n"); // 3

    int* ptr = (int*) malloc(10*sizeof(int));
    ptr[10] = 0; // 2

    return 0; //1
}