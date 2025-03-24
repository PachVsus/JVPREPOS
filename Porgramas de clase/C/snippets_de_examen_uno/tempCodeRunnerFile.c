// Jesús Vargas Pacheco

#include <stdio.h>
#include <stdlib.h>

#define max 10

// funcion para la multiplicacion de matrices
void multiplicar_matrices(double resultado[max][max], double matrizA[max][max], double B[max][max], int m) {
    double temp[max][max] = {0};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                temp[i][j] += matrizA[i][k] * B[k][j];
            }
        }
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            resultado[i][j] = temp[i][j];
        }
    }
}

// Funcion para elevar la matriz a la n
void elevar_matriz(double matriz[max][max], int m, int n) {
    double resultado[max][max] = {0};

    // Incicio resultado como matriz identidad
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            resultado[i][j] = (i == j) ? 1 : 0;
        }
    }

    // Multiplicar la matriz n veces
    for (int i = 0; i < n; i++) {
        multiplicar_matrices(resultado, matriz, resultado, m);
    }

    // Copiar el resultado a la matriz original
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = resultado[i][j];
        }
    }
}

// Funcion para pedir al usuario los elementos de la matriz y el valor de n
void pedir_elementos(double matriz[max][max], int m, int *n) {
    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("Ingrese el elemento en la posicion [%d][%d]: ", i, j);
            scanf("%lf", &matriz[i][j]);
        }
    }
    printf("Ingrese el valor de n: ");
    scanf("%d", n);
}

// Funcion para mostrar la matriz
void mostrar_matriz(double matriz[max][max], int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.2lf ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n;
    printf("Ingrese el tamaño de la matriz cuadrada: ");
    scanf("%d", &m);

    double matriz[max][max];

    pedir_elementos(matriz, m, &n);
    elevar_matriz(matriz, m, n);
    mostrar_matriz(matriz, m);

    return 0;
}