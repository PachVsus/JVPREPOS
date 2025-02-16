#include <stdio.h>

// Modifique el programa para almacenar un numero entero.

int main(void) {
    int a = 5; // Se declara una variable de tipo entero
    int *ptr; // Se declara un apuntador a un entero
    ptr = &a; // Se asigna la direccion de memoria de la variable a al apuntador ptr
    printf("El valor de a es: %d\n", a); // Se imprime el valor de la variable a
    printf("La direccion de memoria de a es: %p\n", &a); // Se imprime la direccion de memoria de la variable a

    return 0;
}