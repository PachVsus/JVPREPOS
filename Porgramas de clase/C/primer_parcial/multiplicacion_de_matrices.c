#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Multiplicación de matriz cuadrada a por matriz cuadrada b, reflejado en matriz c
// despues liberar memoria

int main(void) {
    int i, j, k, n;     // i, j, k son contadores, n es el tamaño de la matriz
    float **a, **b, **c;        // a, b, c son matrices, (**) es un apuntador a un apuntador

    printf("|| Este programa realiza la multiplicación de dos matrices cuadradas ||\n");  // Mensaje de bienvenida
    printf("Introduzca el tamaño de la matriz cuadrada (la dimension N): ");
    scanf("%d", &n);

    a = (float **)malloc(n * sizeof(float *));  // Asignación de memoria para la matriz a, la función malloc asigna memoria dinámica
    if (a == NULL) {    // Verificación de que la memoria fue asignada correctamente
        printf("Error en la asignación de memoria\n");
        return -1;
    }
    b = (float **)malloc(n * sizeof(float *));  // Asignación de memoria para la matriz b
    if (b == NULL) {    // Verificación de que la memoria fue asignada correctamente
        printf("Error en la asignación de memoria\n");
        return -2;
    }
    c = (float **)malloc(n * sizeof(float *));  // Asignación de memoria para la matriz c
    if (c == NULL) {    // Verificación de que la memoria fue asignada correctamente
        printf("Error en la asignación de memoria\n");
        return -3;
    }

    for (i = 0; i < n; i++) {
        a[i] = (float *)malloc(n * sizeof(float));  // Asignación de memoria para las filas de la matriz a
        b[i] = (float *)malloc(n * sizeof(float));  // Asignación de memoria para las filas de la matriz b
        c[i] = (float *)malloc(n * sizeof(float));  // Asignación de memoria para las filas de la matriz c
    }

    printf("Introduzca los elementos de la matriz a (separados con espacios y sin comas): \n");
    for (i = 0; i < n; i++) {       // Llenado de la matriz a, a partir de un for anidado
        for (j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Introduzca los elementos de la matriz b (separados con espacios y sin comas): \n");  // Llenado de la matriz b, a partir de un for anidado
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &b[i][j]);
        }
    }

    for (i = 0; i < n; i++) {               // Multiplicación de las matrices a y b, guardando el resultado en c, se hicieron tres for anidados
        for (j = 0; j < n; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("El resultado de la multiplicación de las matrices es: \n"); // Impresión de la matriz c
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%f ", c[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {    // Liberación de memoria de las matrices
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }

    free(a);    // Liberación de memoria de las matrices
    free(b);
    free(c);

    printf("Memoria liberada\n");  // Mensaje de que la memoria fue liberada

    return 0;

    // fin
}