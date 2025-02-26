#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 int main(int argc, char* argv[])
 {
        struct datawptr
        {
                int i;
                char *c;
        };

        struct datawptr dptr1;
        struct datawptr dptr2;

        dptr1.i = 10;
        dptr1.c = (char*)malloc(sizeof(char));
        *(dptr1.c) = 'c';

        memcpy(&dptr2, &dptr1, sizeof(struct datawptr));
        dptr2.c = (char*)malloc(sizeof(char));


        printf("Int member value of 2nd variable = %d\n", dptr2.i);
        printf("Char ptr member value of 2nd variable = %c\n", *(dptr2.c));
        printf("value of char ptr in 1st variable = %p\n", dptr1.c);
        printf("value of char ptr in 2nd variable = %p\n", dptr2.c);
        printf("Changing value of 2nd member in 2nd variable (dptr2)\n");

        dptr1.i = -23;
        *(dptr2.c) = 'a';
        printf("Value of int of 2nd variable = %d and 1st variable = %d\n", dptr2.i, dptr1.i);
        printf("Value of char ptr of 2nd variable = %c and 1st variable = %c\n", *(dptr2.c), *(dptr1.c));

        free(dptr1.c);
        free(dptr2.c);
        return 0;
 }
 