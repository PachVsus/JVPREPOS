// Jesús Vargas Pacheco

#include <stdio.h>
#include <stdlib.h>

#define max 10

// funcion para la multiplicacion de matrices
void multiplicar_matrices(double resultado[max][max], double matrizA[max][max], double B[max][max], int m) {    // Multiplicar dos matrices
    double temp[max][max] = {0};    // Se crea una matriz temporal para guardar el resultado

    for (int i = 0; i < m; i++) {       // Multiplicar las matrices
        for (int j = 0; j < m; j++) {   // Recorrer las filas de la matriz
            for (int k = 0; k < m; k++) {   // Recorrer las columnas de la matriz
                temp[i][j] += matrizA[i][k] * B[k][j];  // Multiplicar los elementos de las matrices
            }
        }
    }

// Copiar el resultado a la matriz original
    for (int i = 0; i < m; i++) {   // Se recorre la matriz en las filas
        for (int j = 0; j < m; j++) {   // Se recorre la matriz en las columnas
            resultado[i][j] = temp[i][j];   // Se copia de la matriz temporal a la matriz resultado
        }
    }
}

// Funcion para elevar la matriz a la n
void elevar_matriz(double matriz[max][max], int m, int n) {  // Declaro la función para elevar la matriz a la n
    double resultado[max][max] = {0};

    // Incicio resultado como matriz identidad
    for (int i = 0; i < m; i++) {   // Se recorre la matriz en las filas
        for (int j = 0; j < m; j++) {   // Se recorre la matriz en las columnas
            resultado[i][j] = (i == j) ? 1 : 0; // Se inicializa la matriz resultado como la matriz identidad
        }
    }

    // Multiplicar la matriz n veces
    for (int i = 0; i < n; i++) {   // Se recorre la matriz n veces
        multiplicar_matrices(resultado, matriz, resultado, m); // Se llama la función para multiplicar las matrices
    }

    // Copiar el resultado a la matriz original
    for (int i = 0; i < m; i++) {   // Se recorre la matriz en las filas
        for (int j = 0; j < m; j++) {   // Se recorre la matriz en las columnas
            matriz[i][j] = resultado[i][j]; // Se copia el resultado a la matriz original
        }
    }
}

// Funcion para pedir los elementos de la matriz
void pedir_elementos(double matriz[max][max], int m, int *n) {
    printf("Ingrese los elementos de la matriz:\n");    // Se piden los elementos de la matriz
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("Ingrese el elemento en la posicion [%d][%d]: ", i, j);  // Se pide al usuario que ingrese los elementos de la matriz en la posición i, j
            scanf("%lf", &matriz[i][j]);    // Se guarda el valor en la matriz
        }
    }
    printf("Ingrese el valor de n al que se elevara la matriz: "); // Se piden a que valor se quiere elevar la matriz
    scanf("%d", n);
}

// Funcion para mostrar la matriz
void mostrar_matriz(double matriz[max][max], int m) {   // Se crea una función para mostrar la matriz
    for (int i = 0; i < m; i++) {   // Se recorre la matriz en las filas
        for (int j = 0; j < m; j++) {   // Se recorre la matriz en las columnas
            printf("%.2lf ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n;
    printf("Ingrese el tamaño de la matriz cuadrada: ");    // se pide al usuario el tamaño de la matriz
    scanf("%d", &m);

    double matriz[max][max];    // Se declara la matriz

    pedir_elementos(matriz, m, &n);   // Se llama a la función para pedir los elementos de la matriz
    elevar_matriz(matriz, m, n);    // Se llama a la función para elevar la matriz a la n
    mostrar_matriz(matriz, m);  // Se llama a la función para mostrar la matriz

    return 0;
}