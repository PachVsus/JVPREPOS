#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 5 // Numero de filosofos y tenedores

pthread_mutex_t forks[N]; // Mutexes que representan los tenedores
pthread_t philosophers[N]; // Hilos para los filósofos

void* philosopher(void* num) {
    int id = *(int*)num;

    while (1) {
        printf("Filosofo %d esta pensando.\n", id);
        sleep(rand() % 3); // Simula pensar

        // Tomar los tenedores (adquirir los mutexes)
        printf("Filosofo %d intenta tomar el tenedor izquierdo.\n", id);
        pthread_mutex_lock(&forks[id]); // Tenedor izquierdo
        printf("Filosofo %d ha tomado el tenedor izquierdo.\n", id);

        printf("Filosofo %d intenta tomar el tenedor derecho.\n", id);
        pthread_mutex_lock(&forks[(id + 1) % N]); // Tenedor derecho
        printf("Filosofo %d ha tomado ambos tenedores y empieza a comer.\n", id);

        sleep(rand() % 3); // Simula comer

        // Dejar los tenedores (liberar los mutexes)
        pthread_mutex_unlock(&forks[id]); // Deja el tenedor izquierdo
        pthread_mutex_unlock(&forks[(id + 1) % N]); // Deja el tenedor derecho

        printf("Filosofo %d ha terminado de comer y deja los tenedores.\n", id);
    }
}

int main() {
    int ids[N];

    // Inicializar los mutexes
    for (int i = 0; i < N; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Crear los hilos para los filósofos
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    // Esperar a que los hilos terminen (en este caso, nunca terminan)
    for (int i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destruir los mutexes
    for (int i = 0; i < N; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
 