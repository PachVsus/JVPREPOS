#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[] = {1, 2, -3, 4, 0, 0, -5, -6, 6, 7, 8, -50};

    // Sacar porcentaje de elementos que sean positivos y negativos y ceros.

    int pos = 0, neg = 0, ceros = 0;            // Inicializamos las variables porque se van a usar para contar los elementos del arreglo
    int size = sizeof(arr) / sizeof(arr[0]);    // Esto es para sacar el tamaño del arreglo
    for (int i = 0; i < size; i++) {            // Recorremos el arreglo
        if (arr[i] > 0) {                       // Si el elemento es positivo
            pos++;                              // Aumentamos el contador de positivos
        } else if (arr[i] < 0) {                // Si el elemento es negativo
            neg++;                              // Aumentamos el contador de negativos
        } else {                                // Si el elemento es cero
            ceros++;                            // Aumentamos el contador de ceros
        }
    }
    printf("Porcentaje de positivos: %.2f\n", (float) pos / size * 100);
    printf("Porcentaje de negativos: %.2f\n", (float) neg / size * 100);
    printf("Porcentaje de ceros: %.2f\n", (float) ceros / size * 100);

    return 0;

}