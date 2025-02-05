#include <stdio.h>
#include <stdlib.h>

int main(void) {            // Este programa muestra la direccion de memoria de cada byte de una variable int
    int data=9;             // y su valor en hexadecimal
    int *iptr;              // Se declara un apuntador a un entero y un apuntador a un caracter
    char *cptr;             // Se declara un apuntador a un caracter

    iptr = &data;           // Se asigna la direccion de memoria de la variable data al apuntador iptr
    cptr = (char *) &data;  // Se asigna la direccion de memoria de la variable data al apuntador cptr

    printf("==================================================================\n");
    printf("| Value of data = %d hex value = %x\n", data, data);
    printf("| Address of data = %p\n", &data);
    printf("| Integer pointer pointing at %p\n", iptr);
    printf("| Character pointer pointing at %p\n", cptr);
    printf("| Printing address of all the four bytes of variable int data\n");

    for(int i=0; i<4; i++) {  // Se imprime la direccion de memoria de cada byte de la variable data
        printf("| Address: %p, have %x\n", cptr, *cptr);
        cptr++;
    }

    return 0;
}