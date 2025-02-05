#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *iArray = (int *)malloc(32*sizeof(int));                                // funcion malloc reserva memoria en el heap, sizeof(int) es el tamaño de un entero en bytes
    if(iArray == NULL) {                                                        // si malloc no puede reservar memoria, devuelve NULL
        printf("Memory allocation failed\n");
        return -1;                                                              // termina el programa con error
    }

    for(int i=0; i<32; i++){                                                    // llenar el vector con valores
        iArray[i]=i*2;                                                          // se accede a los elementos del vector como si fuera un arreglo
    }

    for(int i=0; i<32; i++) {                                                   // imprimir los valores del vector
        printf("a[%d] in address %p contain %d\n", i, &iArray[i], iArray[i]);   // &iArray[i] es la dirección de memoria del elemento i

    }

    free(iArray);                                                               // liberar la memoria reservada por malloc

    return 0;                                                                   // termina el programa con éxito
}