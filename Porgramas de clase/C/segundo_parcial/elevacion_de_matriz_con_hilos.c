#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> // la libreria para los hilos
#include <unistd.h>

// Estructura que representa la matriz
typedef struct {
    int **matriz;
    int n; // dimensión
    int k; // potencia
} matriz_t;

// Función que multiplica la matriz por sí misma (una vez)
void* elevar_matriz(void* arg) { // Se define la función para elevar la matriz
    matriz_t* matriz = (matriz_t*)arg;  // Se obtiene la matriz de los argumentos
    int n = matriz->n;  // Se obtiene la dimensión de la matriz

    int** temp = (int**)malloc(n * sizeof(int*));   // Se crea una matriz temporal para guardar el resultado
    for (int i = 0; i < n; i++) {   // Se recorre la matriz en las filas
        temp[i] = (int*)malloc(n * sizeof(int));    // Se reserva memoria para las columnas
    }

    for (int i = 0; i < n; i++) {   // Se recorre la matriz en las filas
        for (int j = 0; j < n; j++) {   // Se recorre la matriz en las columnas
            temp[i][j] = 0; // Se inicializa la matriz temporal en 0
            for (int l = 0; l < n; l++) {   // Se recorre la matriz en las columnas
                temp[i][j] += matriz->matriz[i][l] * matriz->matriz[l][j];  // Se multiplica la matriz por sí misma
            }
        }
    }

    for (int i = 0; i < n; i++) {   // Se recorre la matriz en las filas
        for (int j = 0; j < n; j++) {   // Se recorre la matriz en las columnas
            matriz->matriz[i][j] = temp[i][j];  // Se copia el resultado a la matriz original
        }
    }

    for (int i = 0; i < n; i++) {   // Se recorre la matriz en las filas
        free(temp[i]);  // Se libera la memoria de las columnas
    }
    free(temp); // Se libera la memoria de la matriz

    pthread_exit(NULL); // Se termina el hilo
}

// Función para imprimir la matriz
void imprimir_matriz(int** matriz, int n) { // Se define la función para imprimir la matriz
    for (int i = 0; i < n; i++) {   // Se recorre la matriz en las filas
        for (int j = 0; j < n; j++) {   // Se recorre la matriz en las columnas
            printf("%d ", matriz[i][j]);    // Se imprime el elemento de la matriz
        }   
        printf("\n");
    }
}

int main() {    // Se define la función principal
    int n, k;   // Se declaran las variables para la dimensión y la potencia
    matriz_t matriz;    // Se declara la estructura para la matriz
    pthread_t* hilos;   // Se declara un arreglo de hilos

    printf("Elevación de matriz con hilos\n");  // Se imprime el nombre del programa
    printf("Ingrese la dimensión de la matriz (n): ");  // Entrada de usuario de la dimensión
    scanf("%d", &n);    // Se guarda la dimensión de la matriz
    printf("Ingrese la potencia a la que se elevará la matriz (k): ");  // Entrada de usuario de la potencia
    scanf("%d", &k);        // Se guarda la potencia a la que se elevará la matriz

    matriz.n = n;   // Se asigna la dimensión a la matriz
    matriz.k = k;   // Se asigna la potencia a la matriz

    // Reservar memoria para la matriz
    matriz.matriz = (int**)malloc(n * sizeof(int*));    // Se reserva memoria para las filas
    for (int i = 0; i < n; i++) {   // Se recorre la matriz en las filas
        matriz.matriz[i] = (int*)malloc(n * sizeof(int));   // Se reserva memoria para las columnas
    }

    // Leer los elementos de la matriz
    printf("Ingrese cada uno de los elementos de la matriz en forma de salto de línea (%d x %d):\n", n, n);    // Entrada de usuario de los elementos de la matriz
    for (int i = 0; i < n; i++) {   // Se recorre la matriz en las filas
        for (int j = 0; j < n; j++) {   // Se recorre la matriz en las columnas
            scanf("%d", &matriz.matriz[i][j]);  // Se guarda el elemento en la matriz
        }   
    }

    // Reservar memoria para los hilos
    hilos = (pthread_t*)malloc((k - 1) * sizeof(pthread_t));    // Se reserva memoria para los hilos

    // Elevar la matriz a la potencia k usando hilos
    for (int p = 1; p < k; p++) {
        pthread_create(&hilos[p - 1], NULL, elevar_matriz, (void*)&matriz);   // Se crea un hilo para elevar la matriz
        pthread_join(hilos[p - 1], NULL);   // Se espera a que el hilo termine
    }

    // Mostrar solo el resultado final
    printf("Matriz elevada a la potencia k = %d:\n", k);    // Se imprime la matriz elevada a la potencia k
    imprimir_matriz(matriz.matriz, n);  // Se llama la función para imprimir la matriz

    // Liberar memoria
    for (int i = 0; i < n; i++) {   // Se recorre la matriz en las filas
        free(matriz.matriz[i]); // Se libera la memoria de las columnas
    }
    free(matriz.matriz);    // Se libera la memoria de la matriz
    free(hilos);    // Se libera la memoria de los hilos

    return 0;
}
