#include <stdio.h>
#include <stdlib.h>

// nombre: estructuras_con_punteros.c

 int main(int argc, char* argv[])  // main function
 {
        struct data     // a structure with a pointer to char
        {
                int i;      
                char c;
                int j;
                int arr[2];
        };

         struct datawptr
        {
                int i;
                char *c;
        };

        struct datawptr dptr1;      // a structure with a pointer to char
        struct datawptr dptr2;      // a structure with a pointer to char
        struct datawptr dptr3;      // a structure with a pointer to char
        struct data svar1;          // a normal variable of type struct data
        struct data svar2;          // a normal variable of type struct data

        svar1.c = 'a';              // assigning values to members of struct variable
        svar1.i = 1;                // assigning values to members of struct variable
        svar1.j = 2;                // assigning values to members of struct variable
        svar1.arr[0] = 10;          // assigning values to members of struct variable
        svar1.arr[1] = 20;          // assigning values to members of struct variable
        svar2 = svar1;              // copying data from one struct variable to another

        printf("Value of second variable \n");              // printing values of second struct variable
        printf("Member c = %c\n", svar2.c);                 // printing values of second struct variable
        printf("Member i = %d\n", svar2.i);                 // printing values of second struct variable
        printf("Member j = %d\n", svar2.j);                 // printing values of second struct variable
        printf("Member arr0th = %d\n", svar2.arr[0]);       // printing values of second struct variable
        printf("Member arr1st = %d\n", svar2.arr[1]);       // printing values of second struct variable

        printf("\nAssigning some new values to a data member of second struct variable.\n");    // printing values of second struct variable
        svar2.i = 100;          // assigning new values to members of struct variable
        svar2.j = 500;          // assigning new values to members of struct variable
        svar2.arr[0] = -64;     // assigning new values to members of struct variable
        printf("\nSecond variable again.\n");         // printing values of second struct variable
        printf("Member c = %c\n", svar2.c);         // printing values of second struct variable
        printf("Member i = %d\n", svar2.i);         // printing values of second struct variable
        printf("Member j = %d\n", svar2.j);         // printing values of second struct variable
        printf("Member arr0th = %d\n", svar2.arr[0]);       // printing values of second struct variable
        printf("Member arr1st = %d\n", svar2.arr[1]);       // printing values of second struct variable

        printf("\nFirst variable without changes.\n");
        printf("Member c = %c\n", svar1.c);
        printf("Member i = %d\n", svar1.i);
        printf("Member j = %d\n", svar1.j);
        printf("Member arr0th = %d\n", svar1.arr[0]);
        printf("Member arr1st = %d\n", svar1.arr[1]);

        dptr1.i = 10;                                           // assigning values to members of struct variable
        dptr1.c = (char*)malloc(sizeof(char));           // assigning memory from Heap to pointer in struct variable            
        *(dptr1.c) = 'c';                                    // assigning values to members of struct variable                          
        dptr2 = dptr1;                        // copying data from one struct variable to another
        printf("\nContent of first data structure with pointer.\n");
        printf("int member = %d\n", dptr1.i);
        printf("char ptr member = %c\n", *(dptr1.c));
        printf("\nContent of second data structure with pointer.\n");
        printf("int member = %d\n", dptr2.i);
        printf("char ptr member = %c\n", *(dptr2.c));
        printf("\nAssigning new values to second data structure with pointer.\n");
        dptr2.i = 30;               // assigning new values to members of struct variable
        *(dptr2.c) = 'm';           // assigning new values to members of struct variable
        printf("\nContent of first data structure with pointer.\n");        
        printf("int member = %d\n", dptr1.i);
        printf("char ptr member = %c\n", *(dptr1.c));
        printf("\nContent of second data structure with pointer.\n");
        printf("int member = %d\n", dptr2.i);
        printf("char ptr member = %c\n", *(dptr2.c));

        printf("\nCopying data from 1st to 3rd dswp and assigning memory from Heap to pointer in third dswp.\n");
        dptr3 = dptr1;
        dptr3.c = (char*)malloc(sizeof(char));
        printf("\nAssigning some new values to third data structure with pointer.\n");
        *(dptr3.c) = 'z';

        printf("\nContent of first data structure with pointer.\n");
        printf("int member = %d\n", dptr1.i);
        printf("char ptr member = %c\n", *(dptr1.c));
        printf("\nContent of third data structure with pointer.\n");
        printf("int member = %d\n", dptr3.i);
        printf("char ptr member = %c\n", *(dptr3.c));

        return 0;
 }

