#include <stdio.h>
#include <stdlib.h>

int main() {
    int data[4] = {1, 2, 3, 4};
    int *iptr1;
    int *iptr2;

    iptr1 = &data[0];
    iptr2 = &data[1];

    if(iptr1 < iptr2) {
        printf("iptr1 is less than iptr2\n");
    } else if(iptr1 == iptr2) {
        printf("iptr1 is equal to iptr2\n");
    } else {
        printf("iptr1 is greater than iptr2\n");
    }

    return 0;
}