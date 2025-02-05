#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int data=9;
    int *iptr;
    char *cptr;

    iptr = &data;
    cptr = (char *) &data;

    printf("==================================================================\n");
    printf("| Value of data = %d hex value = %x\n", data, data);
    printf("| Address of data = %p\n", &data);
    printf("| Integer pointer pointing at %p\n", iptr);
    printf("| Character pointer pointing at %p\n", cptr);
    printf("| Printing address of all the four bytes of variable int data\n");

    for(int i=0; i<4; i++) {
        printf("| Address: %p, have %x\n", cptr, *cptr);
        cptr++;
    }

    return 0;
}