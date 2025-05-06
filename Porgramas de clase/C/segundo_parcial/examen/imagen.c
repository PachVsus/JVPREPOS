// Nombre: Jesus Vargas Pacheco

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <time.h>

// Definicion de la estructura Pixel
typedef struct {
    int r; // Canal rojo
    int g; // Canal verde
    int b; // Canal azul
} Pixel;

// Definicion de la estructura Image
typedef struct {
    Pixel **pixels; // Matriz de pixeles
    int rows;       // Numero de filas
    int cols;       // Numero de columnas
} Imagen;

// Definicion de la estructura ThreadData
typedef struct {
    Imagen *original; // Imagen original
    Imagen *smoothed; // Imagen suavizada
    int row;          // Fila a procesar
} ThreadData;

// Funcion para crear una imagen
void createImage(Imagen *img, int rows, int cols) {
    img->rows = rows;
    img->cols = cols;
    img->pixels = (Pixel **)malloc(rows * sizeof(Pixel *));
    for (int i = 0; i < rows; i++) {
        img->pixels[i] = (Pixel *)malloc(cols * sizeof(Pixel));
    }
}

// Funcion para liberar la memoria de una imagen
void freeImage(Imagen *img) {
    for (int i = 0; i < img->rows; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
}

// Funcion para llenar la imagen con valores aleatorios
void fillImage(Imagen *img) {
    for (int i = 0; i < img->rows; i++) {
        for (int j = 0; j < img->cols; j++) {
            img->pixels[i][j].r = rand() % 256;
            img->pixels[i][j].g = rand() % 256;
            img->pixels[i][j].b = rand() % 256;
        }
    }
}

// Funcion para imprimir la imagen
void printImage(Imagen *img) {
    for (int i = 0; i < img->rows; i++) {
        for (int j = 0; j < img->cols; j++) {
            printf("(%d, %d, %d) ", img->pixels[i][j].r, img->pixels[i][j].g, img->pixels[i][j].b);
        }
        printf("\n");
    }
}

// Funcion para calcular el promedio de los pixeles
// Se verifica si el pixel es un borde, en caso afirmativo se copia directamente de la imagen original
void *smoothRow(void *arg) {
    ThreadData *data = (ThreadData *)arg;   // Convertir el argumento a ThreadData
    Imagen *original = data->original;      // Obtener la imagen original
    Imagen *smoothed = data->smoothed;      // Obtener la fila a procesar
    int row = data->row;            // Obtener la fila a procesar

    for (int j = 0; j < original->cols; j++) {  // Recorrer cada columna de la fila
        if (row == 0 || row == original->rows - 1 || j == 0 || j == original->cols - 1) {   // Si es un borde
            smoothed->pixels[row][j] = original->pixels[row][j];    // Copiar directamente de la imagen original
        } else {    // Si no es un borde
            // Calcular el promedio de los pixeles vecinos
            int r_sum = original->pixels[row][j].r +    // Sumar el valor del pixel actual
                        original->pixels[row - 1][j].r +    // Sumar el valor del pixel de arriba
                        original->pixels[row + 1][j].r +    // Sumar el valor del pixel de abajo
                        original->pixels[row][j - 1].r +    // Sumar el valor del pixel de la izquierda
                        original->pixels[row][j + 1].r;   // Sumar el valor del pixel de la derecha
            int g_sum = original->pixels[row][j].g +    // Sumar el valor del pixel actual
                        original->pixels[row - 1][j].g +    // Sumar el valor del pixel de arriba
                        original->pixels[row + 1][j].g +    // Sumar el valor del pixel de abajo
                        original->pixels[row][j - 1].g +    // Sumar el valor del pixel de la izquierda
                        original->pixels[row][j + 1].g;  // Sumar el valor del pixel de la derecha
            int b_sum = original->pixels[row][j].b +    // Sumar el valor del pixel actual
                        original->pixels[row - 1][j].b +    // Sumar el valor del pixel de arriba
                        original->pixels[row + 1][j].b +    // Sumar el valor del pixel de abajo
                        original->pixels[row][j - 1].b +    // Sumar el valor del pixel de la izquierda
                        original->pixels[row][j + 1].b; // Sumar el valor del pixel de la derecha

            smoothed->pixels[row][j].r = round(r_sum / 5.0);    // Calcular el promedio y redondear
            smoothed->pixels[row][j].g = round(g_sum / 5.0);    // Calcular el promedio y redondear
            smoothed->pixels[row][j].b = round(b_sum / 5.0);    // Calcular el promedio y redondear
        }
    }
    pthread_exit(NULL); // Terminar el hilo
}

// Funcion principal: MAIN
int main() {
    srand(time(NULL)); // Inicializar la semilla para los numeros aleatorios

    int n, m; // Variables para las dimensiones de la imagen
    printf("Ingrese el numero de filas (n): ");
    scanf("%d", &n);
    printf("Ingrese el numero de columnas (m): ");
    scanf("%d", &m);

    // Verificar que las dimensiones sean validas
    if (n <= 3 || n >= 120 || m <= 3 || m >= 120) {
        printf("Las dimensiones deben ser mayores a 3 y menores a 120.\n");
        return 1;
    }

    Imagen original, smoothed; // Declarar las imagenes original y suavizada
    createImage(&original, n, m); // Crear la imagen original
    createImage(&smoothed, n, m); // Crear la imagen suavizada

    fillImage(&original); // Llenar la imagen original con valores aleatorios

    printf("Imagen original:\n");
    printImage(&original); // Imprimir la imagen original

    pthread_t threads[n]; // Crear un arreglo de hilos
    ThreadData threadData[n]; // Crear un arreglo de datos para los hilos

    for (int i = 0; i < n; i++) {   // Recorrer cada fila
        threadData[i].original = &original;   // Asignar la imagen original al hilo
        threadData[i].smoothed = &smoothed;   // Asignar la imagen suavizada al hilo
        threadData[i].row = i;   // Asignar la fila a procesar al hilo
        pthread_create(&threads[i], NULL, smoothRow, (void *)&threadData[i]);   // Crear el hilo
    }

    for (int i = 0; i < n; i++) {   // Esperar a que todos los hilos terminen
        pthread_join(threads[i], NULL);   // Unir el hilo
    }

    printf("Imagen suavizada:\n");
    printImage(&smoothed); // Imprimir la imagen suavizada

    freeImage(&original);   // Liberar la memoria de la imagen original
    freeImage(&smoothed);   // Liberar la memoria de la imagen suavizada

    return 0;
}