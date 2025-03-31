#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>prime // Para la función usleep(), prime significa microsegundos
#include <string.h> // Para la función memset()

#define BUFFER_SIZE 5
#define TOTAL_ITEMS 30
#define NUM_PRODUCERS 3
#define NUM_CONSUMERS 2

// Estructura compartida
struct {
    int buffer[BUFFER_SIZE]; // Buffer circular
    // Lleva la cuenta de elementos en el buffer
    int count;
    // Lleva el rastro del indice de entrada para los productores
    int in;
    // Lleva el rastro del indice de salida para los consumidores
    int out;
    // Mutex para sincronizar actualización del buffer y de las variables in, out
    pthread_mutex_t mutex;
    // Variable condicional para avisar al productor que hay espacio en el buffer
    pthread_cond_t cond_producer;
    // Variable condicional para avisar al consumidor que hay producto en el buffer
    pthread_cond_t cond_consumer;
} production_line = { {0}, 0, 0, 0, PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER, PTHREAD_COND_INITIALIZER };

// Contador global de productos generados y consumidos
int produced_count = 0;
int consumed_count = 0;

// Mutex para sincronizar el conteo de productos producidos
pthread_mutex_t produced_mutex = PTHREAD_MUTEX_INITIALIZER;
// Mutex para sincronizar el conteo de productos consumidos
pthread_mutex_t consumed_mutex = PTHREAD_MUTEX_INITIALIZER;

void* producer(int id) {
    while (1) {
        // Se verifica si ya se alcanzo la cuota de productos
        pthread_mutex_lock(&produced_mutex);    // Se bloquea el mutex para acceder a produced_count
        if (produced_count >= TOTAL_ITEMS) {        // Se verifica si ya se alcanzo la cuota de productos
            pthread_mutex_unlock(&produced_mutex);  // Se desbloquea el mutex
            break;
        }
        int item = ++produced_count;    // Se incrementa el contador de productos producidos y se asigna el valor al producto
        pthread_mutex_unlock(&produced_mutex);  // Se desbloquea el mutex

        // Cierra el mutex que sincroniza la actualización del buffer y los indices 'in' y 'out'
        pthread_mutex_lock(&production_line.mutex);
        // Si el buffer está lleno no se produce más y el productor entra en estado de espera
        while (production_line.count == BUFFER_SIZE) {
            pthread_cond_wait(&production_line.cond_producer, &production_line.mutex);  // Espera si el buffer está lleno
        }

        // Ya es posible insertar un producto, que se inserta en dónde el indice 'in' indica
        production_line.buffer[production_line.in] = item;
        printf("Producer %d: produced %d\n", id, item);
        // Se actualiza el indice donde se insertara el siguiente producto producido
        production_line.in = (production_line.in + 1) % BUFFER_SIZE;
        // Actualiza la cantidad de productos en el buffer
        production_line.count++;

        // Avisa al consumidor que ya hay producto disponible en el buffer
        pthread_cond_signal(&production_line.cond_consumer);
        // Libera el mutex.
        pthread_mutex_unlock(&production_line.mutex);

        usleep((rand() % 3000 + 500) * 100);  //Pausa aleatoria
    }
    return NULL;
}

// Función del consumidor
// Se encarga de consumir los productos del buffer
void* consumer(int id) {
    while (1) {
        // Se verifica si ya se consumio la cuota de productos
        pthread_mutex_lock(&consumed_mutex);    // Se bloquea el mutex para acceder a consumed_count
        if (consumed_count >= TOTAL_ITEMS) {    // Se verifica si ya se alcanzo la cuota de productos
            pthread_mutex_unlock(&consumed_mutex);  // Se desbloquea el mutex
            break;
        }
        pthread_mutex_unlock(&consumed_mutex);  // Se desbloquea el mutex para acceder a consumed_count

        // Cierra el mutex que sincroniza la actualización del buffer y los indices 'in' y 'out'
        pthread_mutex_lock(&production_line.mutex);
        // Si el buffer está vacio no se consumir más y el consumidor entra en estado de espera
        while (production_line.count == 0) {
            pthread_cond_wait(&production_line.cond_consumer, &production_line.mutex);  // Espera si el buffer está vacío
        }

        // Ya es posible consumir un producto que se toma de dónde el indice 'out' indica
        int item = production_line.buffer[production_line.out];
        // Se actualiza el indice donde se tomara el siguiente producto
        production_line.out = (production_line.out + 1) % BUFFER_SIZE;
        // Actualiza la cantidad de productos en el buffer
        production_line.count--;

        pthread_mutex_lock(&consumed_mutex);    // Se bloquea el mutex para acceder a consumed_count
        consumed_count++;   // Se incrementa el contador de productos consumidos
        pthread_mutex_unlock(&consumed_mutex);  // Se desbloquea el mutex

        printf("Consumer %d: consumed %d\n", id, item); // Se muestra el producto consumido
        printf("\tThere are %d elements in the buffer.\n", production_line.count);  // Se muestra la cantidad de productos en el buffer

        // Avisa al productor que ya hay espacio disponible en el buffer
        pthread_cond_signal(&production_line.cond_producer);
        // Libera el mutex.
        pthread_mutex_unlock(&production_line.mutex);

        usleep((rand() % 3000 + 500) * 100);  // Pausa aleatoria
    }
    return NULL;
}

// Función principal
// Se encarga de crear los hilos productores y consumidores y esperar a que terminen
int main() {
    srand(time(NULL));  // Inicializa la semilla para la función rand()
    pthread_t producers[NUM_PRODUCERS], consumers[NUM_CONSUMERS];   // Arreglos para los hilos productores y consumidores

    // Crear hilos productores
    for (int i = 0; i < NUM_PRODUCERS; i++) {   // Crear hilos productores
        pthread_create(&producers[i], NULL, producer, i);   // Crear hilo productor
    }

    // Crear hilos consumidores
    for (int i = 0; i < NUM_CONSUMERS; i++) {   // Crear hilos consumidores
        pthread_create(&consumers[i], NULL, consumer, i);   // Crear hilo consumidor
    }

    // Esperar a que todos terminen
    for (int i = 0; i < NUM_PRODUCERS; i++) {   // Esperar a que terminen los hilos productores
        pthread_join(producers[i], NULL);   // Esperar a que termine el hilo productor
    }
    for (int i = 0; i < NUM_CONSUMERS; i++) {   // Esperar a que terminen los hilos consumidores
        pthread_join(consumers[i], NULL);   // Esperar a que termine el hilo consumidor
    }

    // Liberar recursos
    pthread_mutex_destroy(&production_line.mutex);  // Destruir el mutex
    pthread_cond_destroy(&production_line.cond_producer);   // Destruir la variable condicional del productor
    pthread_cond_destroy(&production_line.cond_consumer);   // Destruir la variable condicional del consumidor
    pthread_mutex_destroy(&produced_mutex); // Destruir el mutex de productos producidos
    pthread_mutex_destroy(&consumed_mutex); // Destruir el mutex de productos consumidos
    printf("All items produced and consumed.\n");  // Mensaje de finalización

    return 0;
}
 