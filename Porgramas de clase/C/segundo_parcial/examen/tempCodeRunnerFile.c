/*
Escribe un programa en C que simule una granja que procesa animales.
Los animales que procesa la granja son: pollos, puercos y vacas.
Procesar un animal involucra tres actividades: tomarlo del corral, pesarlo y clasificarlo.
Cada actividad se hace en una estación de trabajo.
La primera estación toma cada tipo de animal de su corral y lo coloca en una cola (FIFO) que lo envía a la siguiente estación para pesaje. 
Tomar del corral un animal es leer desde un archivo de texto un renglón. Existen tres archivos de texto.
Uno para pollos, otro para puercos y otro para vacas.
Cada renglón es un registro que al principio sólo tiene una letra y un numero entero.
La letra es 'P' si se trata de un pollo, 'C' si se trata de un puerco y 'V' si se trata de una vaca.
El número entero es el identificador del animal.  
Pesar un animal es generar un numero aleatorio entre un rango dependiendo del tipo de animal.
Para un pollo entre 2.00 y 3.00. Para un puerco entre 100.00 y 120.00 y para una vaca entre 450.00 y 500.00.
La estación indica el peso del animal colocando en pantalla el valor que generó y agregando el valor del peso del animal a su registro.
La estación de pesaje pasa el animal a la siguiente estación, mediante otra cola (FIFO), para su clasificación. 
Clasificar un animal consiste en decidir si está listo para venta o debe regresar a engorda.
Un pollo está listo para venta si su peso está en 2.50 y 3.00.
Un puerco está listo para venta si su peso está entre 110.00 y 120.00.
Y una vaca está lista para venta si su peso está entre 475.00 y 500.00.
Esta estación escribe en un sólo archivo la lista de animales que ya fueron procesados y le agrega a su registro una etiqueta que dice si está "Listo para venta" o debe "Regresar a engorda".
También muestra en pantalla si el animal está listo o debe regresar a engorda. Al final, los registros de los animales en el archivo de salida quedan como (es sólo una muestra): 
P 12 2.75 Listo para venta  
P 15 2.45 Regresar a engorda  
C 8 108.5 Regresar a engorda  
C 22 117.3 Listo para venta  
V 31 480.22 Listo para venta  
V 42 467.45 Regresar a engorda  
Cada estación debe ser ejecutada en un hilo independiente y las colas deben modelarse mediante arreglos

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>


// Definir los maximos tamaños de los corrales y colas
#define MAX_ANIMALES 100
#define MAX_COLA 50
#define MAX_REGISTROS 1000
#define MAX_LINEA 100
#define MAX_ARCHIVO 100
#define MAX_TIPO 10
#define MAX_ID 10
#define MAX_PESO 10
#define MAX_ETIQUETA 30
#define MAX_REGISTRO 100
#define MAX_TAM 1000
#define MAX_TAM_REGISTRO 1000
#define MAX_TAM_ARCHIVO 1000
#define MAX_TAM_LINEA 1000


// Definir los tipos de animales
typedef enum {
    POLLO,
    PUERCO,
    VACA
} TipoAnimal;

// Definir la estructura de un animal
typedef struct {
    TipoAnimal tipo; // Tipo de animal
    int id;         // ID del animal
    float peso;     // Peso del animal
    char etiqueta[MAX_ETIQUETA]; // Etiqueta del animal
} Animal;

// Definir la estructura de un registro
typedef struct {
    char tipo[MAX_TIPO]; // Tipo de animal
    int id;             // ID del animal
    float peso;         // Peso del animal
    char etiqueta[MAX_ETIQUETA]; // Etiqueta del animal
} Registro;

// Definir la estructura de un corral
typedef struct {
    Animal animales[MAX_ANIMALES]; // Arreglo de animales
    int numAnimales;               // Numero de animales en el corral
} Corral;

// Definir la estructura de una cola
typedef struct {
    Animal animales[MAX_COLA]; // Arreglo de animales
    int frente;               // Indice del frente de la cola
    int atras;                // Indice del atras de la cola
} Cola;

// Definir la estructura de un hilo
typedef struct {
    Corral *corral; // Corral de animales
    Cola *cola;     // Cola de animales
    FILE *archivo;  // Archivo de salida
} Hilo;

// Definir la estructura de un registro de animales
typedef struct {
    Registro registros[MAX_REGISTROS]; // Arreglo de registros
    int numRegistros;                  // Numero de registros
} RegistroAnimales;



// Inicializar una cola
void inicializarCola(Cola *cola) {
    cola->frente = 0;
    cola->atras = 0;
}

// Verificar si la cola está vacía
bool colaVacia(Cola *cola) {
    return cola->frente == cola->atras;
}

// Verificar si la cola está llena
bool colaLlena(Cola *cola) {
    return (cola->atras + 1) % MAX_COLA == cola->frente;
}

// Encolar un animal
bool encolar(Cola *cola, Animal animal) {
    if (colaLlena(cola)) {
        return false;
    }
    cola->animales[cola->atras] = animal;
    cola->atras = (cola->atras + 1) % MAX_COLA;
    return true;
}

// Desencolar un animal
bool desencolar(Cola *cola, Animal *animal) {
    if (colaVacia(cola)) {
        return false;
    }
    *animal = cola->animales[cola->frente];
    cola->frente = (cola->frente + 1) % MAX_COLA;
    return true;
}

// Generar un peso aleatorio para un animal
float generarPeso(TipoAnimal tipo) {
    switch (tipo) {
        case POLLO:
            return ((float)rand() / RAND_MAX) * (3.00 - 2.00) + 2.00;
        case PUERCO:
            return ((float)rand() / RAND_MAX) * (120.00 - 100.00) + 100.00;
        case VACA:
            return ((float)rand() / RAND_MAX) * (500.00 - 450.00) + 450.00;
        default:
            return 0.0;
    }
}

// Clasificar un animal
void clasificarAnimal(Animal *animal) {
    switch (animal->tipo) {
        case POLLO:
            if (animal->peso >= 2.50 && animal->peso <= 3.00) {
                strcpy(animal->etiqueta, "Listo para venta");
            } else {
                strcpy(animal->etiqueta, "Regresar a engorda");
            }
            break;
        case PUERCO:
            if (animal->peso >= 110.00 && animal->peso <= 120.00) {
                strcpy(animal->etiqueta, "Listo para venta");
            } else {
                strcpy(animal->etiqueta, "Regresar a engorda");
            }
            break;
        case VACA:
            if (animal->peso >= 475.00 && animal->peso <= 500.00) {
                strcpy(animal->etiqueta, "Listo para venta");
            } else {
                strcpy(animal->etiqueta, "Regresar a engorda");
            }
            break;
    }
}

// Declarar mutex globalmente
pthread_mutex_t mutexPesaje = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexClasificacion = PTHREAD_MUTEX_INITIALIZER;

// Función para procesar animales en la estación de pesaje
void *estacionPesaje(void *arg) {
    Hilo *hilo = (Hilo *)arg;
    Animal animal;

    while (true) {
        pthread_mutex_lock(&mutexPesaje);
        if (!desencolar(hilo->cola, &animal)) {
            pthread_mutex_unlock(&mutexPesaje);
            break;
        }
        pthread_mutex_unlock(&mutexPesaje);

        animal.peso = generarPeso(animal.tipo);
        printf("Animal ID %d pesado: %.2f\n", animal.id, animal.peso);

        pthread_mutex_lock(&mutexClasificacion);
        encolar(hilo->cola, animal);
        pthread_mutex_unlock(&mutexClasificacion);
    }

    return NULL;
}

// Función para procesar animales en la estación de clasificación
void *estacionClasificacion(void *arg) {
    Hilo *hilo = (Hilo *)arg;
    Animal animal;

    while (true) {
        pthread_mutex_lock(&mutexClasificacion);
        if (!desencolar(hilo->cola, &animal)) {
            pthread_mutex_unlock(&mutexClasificacion);
            break;
        }
        pthread_mutex_unlock(&mutexClasificacion);

        clasificarAnimal(&animal);
        printf("Animal ID %d clasificado: %s\n", animal.id, animal.etiqueta);
        fprintf(hilo->archivo, "%c %d %.2f %s\n",
                (animal.tipo == POLLO ? 'P' : (animal.tipo == PUERCO ? 'C' : 'V')),
                animal.id, animal.peso, animal.etiqueta);
    }

    return NULL;
}

// Función principal
int main() {
    srand(time(NULL));

    // Inicializar estructuras
    Corral corralPollos = { .numAnimales = 0 };
    Corral corralPuercos = { .numAnimales = 0 };
    Corral corralVacas = { .numAnimales = 0 };

    Cola colaPesaje, colaClasificacion;
    inicializarCola(&colaPesaje);
    FILE *archivoSalida = fopen("animales_procesados.txt", "w");
    if (!archivoSalida) {
        perror("Error al abrir el archivo de salida");
        return 1;
    }

    pthread_mutex_destroy(&mutexPesaje);
    pthread_mutex_destroy(&mutexClasificacion);

    return 0;

    // Crear hilos
    pthread_t hiloPesaje, hiloClasificacion;
    Hilo datosPesaje = { .corral = NULL, .cola = &colaPesaje, .archivo = NULL };
    Hilo datosClasificacion = { .corral = NULL, .cola = &colaClasificacion, .archivo = archivoSalida };

    pthread_create(&hiloPesaje, NULL, estacionPesaje, &datosPesaje);
    pthread_create(&hiloClasificacion, NULL, estacionClasificacion, &datosClasificacion);

    // Esperar a que los hilos terminen
    pthread_join(hiloPesaje, NULL);
    pthread_join(hiloClasificacion, NULL);

    fclose(archivoSalida);
    return 0;
}