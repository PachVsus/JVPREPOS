#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Estructura para datos de cada hilo
struct thread_data {    
    int row;    // Fila de la matriz
    int size;   // Tamaño de la matriz
    int **A;    // Apuntador a la matriz A
    int **B;    // Apuntador a la matriz B
    int **C;    // Apuntador a la matriz C
};

// Multiplica una fila de A por todas las columnas de B
void* multiplicar_fila(void* arg) {   // Se define la función para multiplicar una fila
    struct thread_data* data = (struct thread_data*) arg;   // Se obtienen los datos de los argumentos
    int n = data->size; // Se obtiene el tamaño de la matriz
    int i = data->row;  // Se obtiene la fila de la matriz

    for (int j = 0; j < n; j++) {   // Se recorre la matriz en las columnas
        data->C[i][j] = 0;  // Se inicializa la matriz C en 0
        for (int k = 0; k < n; k++) {   // Se recorre la matriz en las columnas
            data->C[i][j] += data->A[i][k] * data->B[k][j];   // Se multiplica la matriz por sí misma
        }
    }

    pthread_exit(NULL); // Se termina el hilo
}

// Reserva memoria para una matriz cuadrada de tamaño n
int** crear_matriz(int n) {   // Se define la función para crear una matriz
    int** matriz = (int**)malloc(n * sizeof(int*));   // Se reserva memoria para la matriz
    for (int i = 0; i < n; i++) {   // Se recorre la matriz en las filas
        matriz[i] = (int*)malloc(n * sizeof(int));  // Se reserva memoria para las columnas
    }
    return matriz;  // Se regresa la matriz
}

// Libera memoria de una matriz
void liberar_matriz(int** matriz, int n) {  // Se define la función para liberar la memoria de la matriz
    for (int i = 0; i < n; i++) {   // Se recorre la matriz en las filas
        free(matriz[i]);    // Se libera la memoria de las columnas
    }
    free(matriz);   // Se libera la memoria de la matriz
}

// Copia el contenido de B en A
void copiar_matriz(int** destino, int** origen, int n) {    // Se define la función para copiar la matriz
    for (int i = 0; i < n; i++) {   // Se recorre la matriz en las filas
        for (int j = 0; j < n; j++) {   // Se recorre la matriz en las columnas
            destino[i][j] = origen[i][j];   // Se copia el contenido de la matriz de origen a la matriz de destino
        }
    }
}

// Imprime una matriz
void imprimir_matriz(int** matriz, int n) { // Se define la función para imprimir la matriz
    for (int i = 0; i < n; i++) {   // Se recorre la matriz en las filas
        for (int j = 0; j < n; j++) {   // Se recorre la matriz en las columnas
            printf("%d ", matriz[i][j]);    // Se imprime el elemento de la matriz
        }
        printf("\n");
    }
}

int main() {    // Se define la función main
    int n, k;   // Se definen las variables para la dimensión de la matriz y la potencia

    printf("Ingrese la dimensión de la matriz (n): ");  // Entrada de usuario de la dimensión
    scanf("%d", &n);    // Se guarda la dimensión de la matriz
    printf("Ingrese la potencia a la que se elevará la matriz (k): ");  // Entrada de usuario de la potencia
    scanf("%d", &k);    // Se guarda la potencia a la que se elevará la matriz

    // Reservar matrices
    int** M = crear_matriz(n);
    int** temp = crear_matriz(n);
    int** resultado = crear_matriz(n);

    // Leer la matriz original
    printf("Ingrese los elementos de la matriz en forma de lista (%d x %d):\n", n, n);    // Entrada de usuario de los elementos de la matriz
    for (int i = 0; i < n; i++) {   // Se recorre la matriz en las filas
        for (int j = 0; j < n; j++) {   // Se recorre la matriz en las columnas
            scanf("%d", &M[i][j]);  // Se guarda el valor en la matriz
            resultado[i][j] = M[i][j]; // Copia inicial
        }
    }

    // Elevar matriz a la potencia k usando multiplicación repetida
    for (int pot = 1; pot < k; pot++) {
        copiar_matriz(temp, resultado, n); // Copia del resultado anterior

        pthread_t hilos[n]; // Se crea un arreglo de hilos
        struct thread_data datos[n];    // Se crea una estructura para los datos de los hilos

        for (int i = 0; i < n; i++) {   // Se recorre la matriz en las filas
            datos[i].row = i;   // Se asigna la fila a la estructura
            datos[i].size = n;  // Se asigna el tamaño a la estructura
            datos[i].A = temp;  // Se asigna la matriz temporal a la estructura
            datos[i].B = M;     // Se asigna la matriz original a la estructura
            datos[i].C = resultado; // Se asigna el resultado a la estructura

            pthread_create(&hilos[i], NULL, multiplicar_fila, (void*)&datos[i]);    // Se crea un hilo para multiplicar la fila
        }

        for (int i = 0; i < n; i++) {   // Se recorre la matriz en las filas
            pthread_join(hilos[i], NULL);   // Se espera a que los hilos terminen
        }
    }

    // Mostrar resultado final
    printf("Matriz elevada a la potencia k = %d:\n", k);    // Se imprime la matriz elevada a la potencia k
    imprimir_matriz(resultado, n);  // Se llama la función para imprimir la matriz

    // Liberar memoria
    liberar_matriz(M, n);   // Se llama la función para liberar la memoria de la matriz
    liberar_matriz(temp, n);    // Se llama la función para liberar la memoria de la matriz
    liberar_matriz(resultado, n);   // Se llama la función para liberar la memoria de la matriz

    return 0;   // Fin del programa
}
