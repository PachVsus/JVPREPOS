#include <stdio.h>
#include <stdlib.h>
#define Max_Elements 20

int main() {
    int array[Max_Elements] = {2, 3, 5, -7, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73};

    int *iptr = array;

    while(iptr < array + 20) {
        printf("En la direccion %p se encuentra el valor %d\n", iptr, *iptr);
        iptr++;
    }
    return 0;
}