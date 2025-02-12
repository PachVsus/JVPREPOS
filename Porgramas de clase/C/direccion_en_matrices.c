#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;                           // Declaración de variables
    int data[4][4];                     // Declaración de una matriz de 4x4
    
    int count = 0;                      // Inicialización de la variable count
    for (i = 0; i < 4; i++) {           // Ciclo para recorrer la matriz verticalmente
        for (j = 0; j < 4; j++) {       // Ciclo para recorrer la matriz horizontalmente
            data[i][j] = count++;       // Llena la matriz con números del 0 al 15
        }
    }
    for (i = 0; i < 4; i++) {           // Ciclo para recorrer la matriz verticalmente
        for (j = 0; j < 4; j++) {       // Ciclo para recorrer la matriz horizontalmente
            printf("%d ", data[i][j]);  // Imprime la matriz
        }
        printf("\n");
    }

    printf("%d\n", data[2][3]);         // Imprime la dirección de memoria de data en la posición 2, 3
    printf("%d\n", *(data[1] + 3));     /* Imprime la dirección de memoria de data en la posición 1, 3.
                                           la suma significa que se mueve en la matriz.
                                           en simples palabras, se mueve a la derecha.*/
    return 0;
}