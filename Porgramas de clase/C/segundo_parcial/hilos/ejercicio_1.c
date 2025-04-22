// Jesus Vargas Pacheco

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4   // Número de hilos
#define NUM_TERMS 1000000   // Número de términos para la aproximación de Pi
#define PI 3.14159265358979323846   // Valor de Pi para comparación

typedef struct {    // Estructura para pasar datos a los hilos
    int thread_id;  // ID del hilo
    int num_threads;    // Número total de hilos
    int num_terms;  // Número total de términos
    double result;  // Resultado parcial del hilo
} ThreadData;   // Alias para la estructura ThreadData

void *calculate_pi(void *arg) {   // Función que calcula Pi usando la serie de Leibniz
    ThreadData *data = (ThreadData *)arg;   // Convierte el argumento a ThreadData
    int start = data->thread_id * (data->num_terms / data->num_threads);    // Calcula el inicio del hilo
    int end = start + (data->num_terms / data->num_threads);    // Calcula el final del hilo
    double sum = 0.0;   // Inicializa la suma parcial

    for (int i = start; i < end; i++) {   // Itera sobre los términos asignados al hilo
        double term = (i % 2 == 0 ? 1.0 : -1.0) / (2 * i + 1);  // Calcula el término de la serie
        sum += term;    // Suma el término a la suma parcial
    }

    data->result = sum; // Almacena el resultado parcial en la estructura
    pthread_exit(NULL); // Termina el hilo
}

int main() {    // Función principal
    pthread_t threads[NUM_THREADS]; // Arreglo para almacenar los hilos
    double pi = 0.0;    // Variable para almacenar el valor final de Pi
    pthread_mutex_t pi_mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex para proteger la variable pi
    double pi = 0.0;    // Variable para almacenar el valor final de Pi

    for (int i = 0; i < NUM_THREADS; i++) {   // Crea los hilos
        thread_data[i].thread_id = i;   // Asigna el ID del hilo
        thread_data[i].num_threads = NUM_THREADS;   // Asigna el número total de hilos
        thread_data[i].num_terms = NUM_TERMS;   // Asigna el número total de términos
        thread_data[i].result = 0.0;    // Inicializa el resultado parcial

        if (pthread_create(&threads[i], NULL, calculate_pi, &thread_data[i]) != 0) {    // Crea el hilo
            perror("Error al crear hilo");  // Manejo de error con salida
            exit(EXIT_FAILURE); // Termina el programa si hay error
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {  // Une los hilos
        if (pthread_join(threads[i], NULL) != 0) {  // Espera a que el hilo termine
            perror("Error al unir hilo");   // Manejo de error con salida
        pthread_mutex_lock(&pi_mutex); // Bloquea el mutex antes de actualizar pi
        pi += thread_data[i].result;   // Suma el resultado parcial al total
        pthread_mutex_unlock(&pi_mutex); // Desbloquea el mutex después de actualizar pi
        }
        pi += thread_data[i].result;    // Suma el resultado parcial al total
    }
    pthread_mutex_destroy(&pi_mutex); // Destruye el mutex antes de salir
    return 0;
    pi *= 4.0;  // Multiplica por 4 para obtener el valor final de Pi
    printf("Valor calculado de Pi: %.15f\n", pi);   // Muestra el valor calculado de Pi

    return 0;
}