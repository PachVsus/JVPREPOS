#include <stdio.h>
#include <stdlib.h>

int main() {
    int data[5][5];                    // Declaración de una matriz de 5x5
    int i, j;                          // Declaración de variables
    int count = 0;                     // Inicialización de la variable count
    int (*aptr)[5];                    // Declaración de un apuntador a un arreglo de 5 elementos

    for (i = 0; i < 5; i++) {          // Ciclo para recorrer la matriz verticalmente
        for (j = 0; j < 5; j++) {      // Ciclo para recorrer la matriz horizontalmente
            data[i][j] = count++;      // Llena la matriz con números del 0 al 24
        }
    }

    aptr = data;                       // Asigna la dirección de memoria de data a aptr
    for (i = 0; i < 5; i++) {
        printf("%dth row = %p\n", i, *aptr++); // Imprime la dirección de memoria de la fila i
    }

    printf("/n/n");

    aptr = data;                       // Asigna la dirección de memoria de data a aptr
    for (i = 0; i < 5; i++) {
        printf("%dth row = %p\n", i, aptr++); // Imprime la dirección de memoria de la fila i
        for (j = 0; j < 5; j++) {
            printf("%d ", *(*(aptr - 1) + j)); // Imprime la matriz
        }
        *aptr++;
        printf("\n");

    return 0;
    }
}