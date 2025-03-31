#include <stdio.h>
#include <stdlib.h>

// Modifique el programa para almacenar un arreglo de numeros flotantes.

int main(void) {
    float arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5}; // Se declara un arreglo de numeros flotantes
    float *ptr; // Se declara un apuntador a un numero flotante
    ptr = arr; // Se asigna la direccion de memoria del arreglo arr al apuntador ptr

    for (int i = 0; i < 5; i++) // Se recorre el arreglo
        printf("El valor de arr[%d] es: %.1f\n", i, *(ptr + i)); // Se imprime el valor del arreglo
    
    return 0;
}