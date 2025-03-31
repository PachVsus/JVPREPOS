#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Estructura para las alarmas
typedef struct alarm_tag {
    struct alarm_tag *next;  // siguiente alarma en la lista
    int seconds;             // tiempo en segundos hasta la expiración
    char message[64];        // mensaje de la alarma
} alarm_t;

// Variables globales para la lista de alarmas
alarm_t *alarm_list = NULL;
pthread_mutex_t alarm_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t alarm_cond = PTHREAD_COND_INITIALIZER;

// Función que maneja la alarma
void *alarm_thread(void *arg) {
    alarm_t *alarm;
    int sleep_time;

    while (1) {
        pthread_mutex_lock(&alarm_mutex);

        // Si no hay alarmas, esperamos
        while (alarm_list == NULL) {
            pthread_cond_wait(&alarm_cond, &alarm_mutex);
        }

        alarm = alarm_list;
        alarm_list = alarm_list->next;  // Tomar de la cola la primera alarma

        sleep_time = alarm->seconds;
        pthread_mutex_unlock(&alarm_mutex);

        sleep(sleep_time);
        printf("\nAlarm: %s\n", alarm->message);
        free(alarm);
    }

    return NULL;
}

// Función para agregar nuevas alarmas en orden
void add_alarm(int seconds, const char *message) {
    alarm_t *alarm, *last, *next;

    // Crear nueva alarma
    alarm = (alarm_t *)malloc(sizeof(alarm_t));
    if (alarm == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    alarm->seconds = seconds;
    strncpy(alarm->message, message, sizeof(alarm->message) - 1);
    alarm->message[sizeof(alarm->message) - 1] = '\0';
    alarm->next = NULL;

    pthread_mutex_lock(&alarm_mutex);

    // Insertar la alarma en la posición correcta basada en el tiempo
    last = NULL;
    next = alarm_list;
    while (next != NULL && next->seconds <= seconds) {
        last = next;
        next = next->next;
    }

    // Insertar la alarma en la lista ordenada
    if (last == NULL) {
        // Insertar al principio si es la primera o la más próxima a expirar
        alarm_list = alarm;
    } else {
        // Insertar después de `last`
        last->next = alarm;
    }
    alarm->next = next;

    // Notificar al hilo de alarma que hay una nueva alarma
    pthread_cond_signal(&alarm_cond);
    pthread_mutex_unlock(&alarm_mutex);
}

int main(int argc, char *argv[]) {
    pthread_t thread;
    char line[128];
    int seconds;
    char message[64];

    // Crear el hilo de alarmas
    if (pthread_create(&thread, NULL, alarm_thread, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // Leer alarmas del usuario
    while (1) {
        printf("Enter alarm (seconds message): ");
        if (fgets(line, sizeof(line), stdin) == NULL) exit(EXIT_SUCCESS);
        if (sscanf(line, "%d %64[^\n]", &seconds, message) < 2) {
            fprintf(stderr, "Bad input. Try again.\n");
        } else {
            add_alarm(seconds, message);
        }
    }

    return 0;
}

// ejemplo de uso:
// gcc -pthread cola_de_alarmas.c -o cola_de_alarmas
// ./cola_de_alarmas
// Enter alarm (seconds message): 5 Wake up!
// Enter alarm (seconds message): 10 Go to work
// Enter alarm (seconds message): 3 Take a break
// Enter alarm (seconds message): 1 Drink water