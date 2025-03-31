#include <stdio.h>
#include <stdlib.h>

void imprimir(int **matriz, int filas, int columnas); // Prototipo de la función imprimir

int main() {
    int filas, columnas;

    printf("| Programa para capturar una matriz de n x m elementos (n y m definidos por el usuario) y calcular su transpuesta. |\n");
    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    int **matriz = (int **)malloc(filas * sizeof(int *)); // Reserva de memoria para la matriz
    if (matriz == NULL) { // Verificación de la reserva de memoria
        printf("Error al asignar memoria a la matriz, no se pudo reservar.\n");     // Mensaje de error
        return -1; // Salida del programa con error
    }

    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas * sizeof(int)); // Reserva de memoria para las filas de la matriz
        if (matriz[i] == NULL) {
            printf("No se pudo reservar memoria para la fila %d de la matriz.\n", i); // Mensaje de error
            return -2; // Salida del programa con error
        }
    }

    printf("Capture los elementos de la matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el elemento para M [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    int **transpuesta = (int **)malloc(columnas * sizeof(int *));
    if (transpuesta == NULL) {
        printf("Error al asignar memoria a la matriz transpuesta, no se pudo reservar.\n");
        return -1;
    }

    for (int i = 0; i < columnas; i++) {
        transpuesta[i] = (int *)malloc(filas * sizeof(int));
        if (transpuesta[i] == NULL) {
            printf("No se pudo reservar memoria para la fila %d de la matriz transpuesta.\n", i);
            return -2;
        }
    }

    for (int i = 0; i < columnas; i++) {
        for (int j = 0; j < filas; j++) {
            transpuesta[i][j] = matriz[j][i];
        }
    }

    printf("Matriz original:\n");
    imprimir(matriz, filas, columnas);
    
    printf("Matriz transpuesta:\n");
    imprimir(transpuesta, columnas, filas);
    
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
    
    for (int i = 0; i < columnas; i++) {
        free(transpuesta[i]);
    }
    free(transpuesta);
    
    return 0;
}

void imprimir(int **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}