#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/*Crea un programa en C que toma una matriz cuadrada M de dimensión 'n' ('n' renglones x 'n' columnas) y la eleve a la potencia 'k'.

El programa debe hacer uso de hilos para elevar la matriz 'M' a la potencia 'k'*/

// Se crea la estructura de la matriz
typedef struct {
    int **matriz; // Matriz de enteros, ** significa que es un apuntador a un apuntador
    int n; // Dimension de la matriz
    int k; // Potencia a la que se elevara la matriz
} matriz_t; // Se crea un alias para la estructura. termina en _t porque es un tipo de dato definido por el usuario

// Funcion que eleva una matriz a una potencia
void* elevar_matriz(void* arg) {
    matriz_t* matriz = (matriz_t*)arg; // El argumento se convierte a un apuntador a matriz_t
    int** temp = (int**)malloc(matriz->n * sizeof(int*)); // Matriz temporal
    for (int i = 0; i < matriz->n; i++) {
        temp[i] = (int*)malloc(matriz->n * sizeof(int));
    }

    for (int i = 0; i < matriz->n; i++) {
        for (int j = 0; j < matriz->n; j++) {
            temp[i][j] = 0;
            for (int l = 0; l < matriz->n; l++) {
                temp[i][j] += matriz->matriz[i][l] * matriz->matriz[l][j];
            }
        }
    }

    for (int i = 0; i < matriz->n; i++) {
        for (int j = 0; j < matriz->n; j++) {
            matriz->matriz[i][j] = temp[i][j];
        }
    }

    for (int i = 0; i < matriz->n; i++) {
        free(temp[i]);
    }
    free(temp);

    pthread_exit(NULL);
}

// Funcion para imprimir una matriz
void imprimir_matriz(int** matriz, int n) {
    for (int i = 0; i < n; i++) {       // Se recorre la matriz por renglones
        for (int j = 0; j < n; j++) {       // Se recorre la matriz por columnas
            printf("%d ", matriz[i][j]); // Se imprime la matriz
        }
        printf("\n");
    }
}

// Funcion main
int main() {
    int n;  // Dimension de la matriz
    int k;  // Potencia a la que se elevara la matriz
    pthread_t* hilos = NULL;   // Hilos
    matriz_t matriz;    // Matriz

    printf("Elevacion de matriz con hilos\n");  // Nombre del programa
    printf("Ingrese la dimension de la matriz (n): ");
    scanf("%d", &n);
    printf("Ingrese la potencia a la que se elevara la matriz (k): ");
    scanf("%d", &k);

    matriz.n = n;   // Se asigna la dimension de la matriz
    matriz.k = k;   // Se asigna la potencia a la que se elevara la matriz

    matriz.matriz = (int**)malloc(n * sizeof(int*)); // Reserva memoria para la matriz
    for (int i = 0; i < n; i++) {
    hilos = (pthread_t*)malloc((k - 1) * sizeof(pthread_t)); // Reserva memoria para los hilos
    for (int p = 1; p < k; p++) {   // Se recorre la potencia a la que se elevara la matriz
    }
    for (int p = 1; p < k; p++) {   // Se recorre la potencia a la que se elevara la matriz
        pthread_create(&hilos[p - 1], NULL, elevar_matriz, (void*)&matriz); // Se crean los hilos
        pthread_join(hilos[p - 1], NULL);   // Se espera a que los hilos terminen

        // Se imprime la matriz después de cada multiplicación
        printf("Matriz M elevada a la potencia %d:\n", p + 1);
        imprimir_matriz(matriz.matriz, n);
    }
    printf("Matriz M elevada a la potencia k = %d:\n", k);
    for (int i = 0; i < n; i++) {       // Se recorre la matriz por renglones
        for (int j = 0; j < n; j++) {       // Se recorre la matriz por columnas
            printf("%d ", matriz.matriz[i][j]); // Se imprime la matriz
        }
        printf("\n");
    }

    // Se libera la memoria de la matriz
    for (int i = 0; i < n; i++) {
        free(matriz.matriz[i]); // Se libera la memoria de las columnas
    }
    free(matriz.matriz); // Se libera la memoria de los renglones

    // Se libera la memoria de los hilos
    free(hilos); // Se libera la memoria de los hilos
    }

    return 0;

}