// Jesus Vargas Pacheco

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX 10001    // Máximo valor para la moda (10000.00)

float *array;
int N;

void *calcular_media(void *arg) {   // Función para calcular la media
    float suma = 0;  // Inicializa la suma
    for (int i = 0; i < N; i++) {   // Recorre el arreglo
        suma += array[i];    // Suma los elementos
    }
    float *media = malloc(sizeof(float));   // Reserva memoria para la media
    if (media == NULL) {   // Manejo de error
        perror("Error al reservar memoria para la media");
        pthread_exit(NULL); // Termina el hilo si hay error
    }
    *media = suma / N;    // Calcula la media
    pthread_exit(media); // Termina el hilo y devuelve la media
}

void *calcular_moda(void *arg) {   // Función para calcular la moda
    int *frecuencia = calloc(MAX, sizeof(int));  // Inicializa el arreglo de frecuencias
    if (frecuencia == NULL) {   // Manejo de error
        perror("Error al reservar memoria para la frecuencia");
        pthread_exit(NULL); // Termina el hilo si hay error
    }
    for (int i = 0; i < N; i++) {   // Recorre el arreglo
        frecuencia[(int)(array[i] * 100)]++; // Incrementa la frecuencia
    }

    int max_frecuencia = 0;   // Inicializa la frecuencia máxima
    for (int i = 0; i < MAX; i++) {   // Busca la moda
        if (frecuencia[i] > max_frecuencia) {
            max_frecuencia = frecuencia[i];   // Actualiza la frecuencia máxima
        }
    }
    float *moda = malloc(sizeof(float));    // Reserva memoria para la moda
    if (moda == NULL) {   // Manejo de error
        perror("Error al reservar memoria para la moda");
        free(frecuencia);   // Libera memoria si hay error
        pthread_exit(NULL); // Termina el hilo si hay error
    }
    *moda = -1;  // Inicializa la moda
    for (int i = 0; i < MAX; i++) {  // Busca la moda
        if (frecuencia[i] == max_frecuencia) {  // Si la frecuencia coincide con la máxima
            *moda = i / 100.0;  // Actualiza la moda
            break;  // Sale del bucle al encontrar la primera moda
        }
    }
    free(frecuencia);    // Libera memoria del arreglo de frecuencias
    pthread_exit(moda); // Termina el hilo y devuelve la moda
}

void *calcular_mediana(void *arg) {  // Función para calcular la mediana
    float *ordenado = malloc(N * sizeof(float));  // Reserva memoria para el arreglo ordenado
    if (ordenado == NULL) {   // Manejo de error
        perror("Error al reservar memoria para el arreglo ordenado");
        pthread_exit(NULL); // Termina el hilo si hay error
    }
    for (int i = 0; i < N; i++) {   // Copia el arreglo original al nuevo arreglo
        ordenado[i] = array[i];   // Copia cada elemento
    }

    for (int i = 0; i < N - 1; i++) {   // Ordena el arreglo usando burbuja
        for (int j = i + 1; j < N; j++) {   // Recorre el arreglo
            if (ordenado[i] > ordenado[j]) {    // Si el elemento actual es mayor que el siguiente
                // Intercambia los elementos
                float temp = ordenado[i]; // Almacena el elemento actual
                ordenado[i] = ordenado[j];  // Asigna el siguiente elemento al actual
                ordenado[j] = temp;   // Asigna el elemento actual al siguiente
            }
        }
    }

    float *mediana = malloc(sizeof(float));  // Reserva memoria para la mediana
    if (mediana == NULL) {   // Manejo de error
        perror("Error al reservar memoria para la mediana");
        free(ordenado);   // Libera memoria si hay error
        pthread_exit(NULL); // Termina el hilo si hay error
    }
    if (N % 2 == 0) {   // Si el número de elementos es par
        *mediana = (ordenado[N / 2 - 1] + ordenado[N / 2]) / 2;  // Calcula la mediana
    } else {
        *mediana = ordenado[N / 2];    // Si es impar, toma el elemento del medio
    }
    free(ordenado);   // Libera memoria del arreglo ordenado
    pthread_exit(mediana);   // Termina el hilo y devuelve la mediana
}

int main() {    // Función principal
    printf("Ingrese el número de elementos (N): "); // Solicita el número de elementos
    scanf("%d", &N);    // Lee el número de elementos

    array = malloc(N * sizeof(float));  // Reserva memoria para el arreglo
    if (array == NULL) {   // Manejo de error
        perror("Error al reservar memoria para el arreglo");
        exit(EXIT_FAILURE); // Termina el programa si hay error
    }
    srand(time(NULL));  // Inicializa la semilla para la generación aleatoria
    for (int i = 0; i < N; i++) {   // Genera números aleatorios
        array[i] = (rand() % 10000) / 100.0;    // Genera un número aleatorio entre 0.00 y 99.99
    }

    printf("Arreglo generado:\n");  // Muestra el arreglo generado
    for (int i = 0; i < N; i++) {   // Recorre el arreglo
        printf("%.2f ", array[i]);  // Muestra cada elemento
    }
    printf("\n");

    pthread_t hilo_media, hilo_moda, hilo_mediana;  // Declara los hilos

    pthread_create(&hilo_media, NULL, calcular_media, NULL);   // Crea el hilo para la media
    pthread_create(&hilo_moda, NULL, calcular_moda, NULL);   // Crea el hilo para la moda
    pthread_create(&hilo_mediana, NULL, calcular_mediana, NULL);   // Crea el hilo para la mediana

    float *media, *moda, *mediana;    // Declara punteros para almacenar los resultados
    pthread_join(hilo_media, (void **)&media);  // Une el hilo de la media y obtiene el resultado
    pthread_join(hilo_moda, (void **)&moda);  // Une el hilo de la moda y obtiene el resultado
    pthread_join(hilo_mediana, (void **)&mediana);  // Une el hilo de la mediana y obtiene el resultado

    printf("Media: %.2f\n", *media); // Muestra la media
    printf("Moda: %.2f\n", *moda);  // Muestra la moda
    printf("Mediana: %.2f\n", *mediana); // Muestra la mediana

    free(media);   // Libera memoria de la media
    free(moda);  // Libera memoria de la moda
    free(mediana);   // Libera memoria de la mediana
    free(array);    // Libera memoria del arreglo
    printf("Memoria liberada.\n");   // Mensaje de liberación de memoria

    return 0;
}