// Jesus Vargas Pacheco

#include <stdio.h>
#include <stdlib.h>


int main (void) {
    float *arr = (float *) malloc(8 * sizeof(float));   // Esto hace que arr sea un puntero a un bloque de memoria de 8 floats
    for (int i = 7; i > -1; i--) {                      // Recorremos el arreglo de atrás para adelante
        if (i % 2) {                                    // Si el índice es impar
            *(arr + i) = (float) (i * i);               // Asignamos el cuadrado del índice al arreglo
        } else {                                        // Si el índice es par
            *(arr + i) = (float) (i * i%3);             // Asignamos el residuo de dividir el cuadrado del índice entre 3 al arreglo
        }
    }

    // Imprimimos el valor en la posición que se obtiene de sumar el valor en la posición 4 del arreglo y el residuo de dividirlo entre 3
    float *ptr = arr;                                   // Hacemos que ptr apunte al mismo lugar que arr
    printf("%.2f\n", *(ptr+((int)*(ptr+4))%3));         // Imprime el valor en la posición 1 del arreglo
}

