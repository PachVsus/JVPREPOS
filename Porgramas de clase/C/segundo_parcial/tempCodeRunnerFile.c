#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>    // Para usar hilos
#include <time.h>   // Para la función rand()
#include <unistd.h>  // Para la función sleep()

#define BUFFER_SIZE 5   // Tamaño del buffer circular
#define TOTAL_ITEMS 15  // Total de elementos a producir y consumir

// Estructura de datos compartida
struct {
    int buffer[BUFFER_SIZE];  // Buffer circular de 5 elementos
    int count;                // Número de elementos en el buffer
    int in;                   // Índice para producir siguiente elemento
    int out;                  // Índice para consumir siguiente elemento
    pthread_mutex_t mutex;      // Mutex para proteger el acceso al buffer
    pthread_cond_t cond_producer;   // Condición para el productor
    pthread_cond_t cond_consumer;   // Condición para el consumidor
} production_line = { {0}, 0, 0, 0, PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER, PTHREAD_COND_INITIALIZER };    // Inicialización de la estructura

// Función del productor
void* producer(void* arg) {                 // Inicializar el productor
    for (int i = 0; i < TOTAL_ITEMS; i++) {             // Producir TOTAL_ITEMS elementos
        pthread_mutex_lock(&production_line.mutex);     // Bloquear el mutex para acceder al buffer


 while (production_line.count == BUFFER_SIZE) {       // Comprobar si el buffer está lleno
        // Esperar si el buffer está lleno
        pthread_cond_wait(&production_line.cond_producer, &production_line.mutex);
    }

    // Producir un elemento y añadirlo al buffer
    production_line.buffer[production_line.in] = i + 1; // Producir un elemento (i+1)
    printf("Producer: produced %d\n", production_line.buffer[production_line.in]);  // Mostrar el elemento producido
    production_line.in = (production_line.in + 1) % BUFFER_SIZE;    // Actualizar el índice de producción
    production_line.count++;    // Incrementar el contador de elementos en el buffer
    printf("\tThere are %d elements in the buffer.\n", production_line.count);  // Mostrar el número de elementos en el buffer

    // Señalar al consumidor que hay nuevos datos disponibles
    pthread_cond_signal(&production_line.cond_consumer);    // Señalar al consumidor que hay nuevos datos disponibles
    printf("\tSignaling that there are products ready to be consumed.\n");  // Señalar al consumidor que hay nuevos datos disponibles

    pthread_mutex_unlock(&production_line.mutex);   // Desbloquear el mutex
    sleep(rand()%3);  // Simular tiempo de producción   
}
return NULL;


}

// Función del consumidor
void* consumer(void* arg) {
    for (int i = 0; i < TOTAL_ITEMS; i++) {            // Consumir TOTAL_ITEMS elementos
        pthread_mutex_lock(&production_line.mutex);    // Bloquear el mutex para acceder al buffer


 while (production_line.count == 0) {     // Comprobar si el buffer está vacío
        // Esperar hasta que el buffer tenga datos
        pthread_cond_wait(&production_line.cond_consumer, &production_line.mutex);  // Esperar hasta que el buffer tenga datos
    }

    // Consumir el elemento del buffer
    int item = production_line.buffer[production_line.out]; // Consumir el elemento del buffer
    printf("Consumer: consumed %d\n", item);    // Mostrar el elemento consumido
    production_line.out = (production_line.out + 1) % BUFFER_SIZE;  // Actualizar el índice de consumo
    production_line.count--;    // Decrementar el contador de elementos en el buffer
    printf("\tThere are %d elements in the buffer.\n", production_line.count);  // Mostrar el número de elementos en el buffer

    // Señalar al productor que hay espacio disponible
    pthread_cond_signal(&production_line.cond_producer);    // Señalar al productor que hay espacio disponible
    printf("\tSignaling that there are slots ready to be filled.\n");   // Señalar al productor que hay espacio disponible

    pthread_mutex_unlock(&production_line.mutex);   // Desbloquear el mutex
    sleep(rand()%3);    // Simular tiempo de consumo
}
return NULL;    // Función del consumidor


}

// Función principal
int main() {
    srand(time(NULL));  // Inicializar la semilla para la función rand()
    // Inicializar el mutex y las variables de condición
    pthread_t prod_thread, cons_thread;


 // Crear hilos productor y consumidor
    pthread_create(&prod_thread, NULL, producer, NULL); // Crear hilo productor
    pthread_create(&cons_thread, NULL, consumer, NULL); // Crear hilo consumidor

    // Esperar a que ambos hilos terminen
    pthread_join(prod_thread, NULL);    // Esperar a que el hilo productor termine
    pthread_join(cons_thread, NULL);    // Esperar a que el hilo consumidor termine

    // Limpieza de recursos
    pthread_mutex_destroy(&production_line.mutex);  // Destruir el mutex
    pthread_cond_destroy(&production_line.cond_producer);   // Destruir la variable de condición del productor
    pthread_cond_destroy(&production_line.cond_consumer);   // Destruir la variable de condición del consumidor
    printf("All items produced and consumed.\n");  // Mostrar mensaje de finalización

    return 0;   // Fin de la función principal


}