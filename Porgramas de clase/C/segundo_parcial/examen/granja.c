// Nombre: Jesus Vargas Pacheco
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#define MAX_COLA 100
#define MAX_LINEA 100
#define MAX_ETIQUETA 30

typedef enum {
    POLLO,
    PUERCO,
    VACA
} TipoAnimal;

typedef struct {
    TipoAnimal tipo;
    int id;
    float peso;
    char etiqueta[MAX_ETIQUETA];
} Animal;

typedef struct {
    Animal animales[MAX_COLA];
    int frente;
    int atras;
} Cola;

typedef struct {
    Cola *colaEntrada;
    Cola *colaSalida;
} DatosPesaje;

typedef struct {
    Cola *colaEntrada;
    FILE *archivoSalida;
} DatosClasificacion;

// Mutex globales
pthread_mutex_t mutexPesaje = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutexClasificacion = PTHREAD_MUTEX_INITIALIZER;

// Cola funciones
void inicializarCola(Cola *cola) {
    cola->frente = 0;
    cola->atras = 0;
}

bool colaVacia(Cola *cola) {
    return cola->frente == cola->atras;
}

bool colaLlena(Cola *cola) {
    return (cola->atras + 1) % MAX_COLA == cola->frente;
}

bool encolar(Cola *cola, Animal animal) {
    if (colaLlena(cola)) return false;
    cola->animales[cola->atras] = animal;
    cola->atras = (cola->atras + 1) % MAX_COLA;
    return true;
}

bool desencolar(Cola *cola, Animal *animal) {
    if (colaVacia(cola)) return false;
    *animal = cola->animales[cola->frente];
    cola->frente = (cola->frente + 1) % MAX_COLA;
    return true;
}

// Generar peso aleatorio
float generarPeso(TipoAnimal tipo) {
    switch (tipo) {
        case POLLO: return ((float)rand() / RAND_MAX) * (3.0 - 2.0) + 2.0;
        case PUERCO: return ((float)rand() / RAND_MAX) * (120.0 - 100.0) + 100.0;
        case VACA: return ((float)rand() / RAND_MAX) * (500.0 - 450.0) + 450.0;
        default: return 0.0;
    }
}

// Clasificación
void clasificarAnimal(Animal *animal) {
    switch (animal->tipo) {
        case POLLO:
            strcpy(animal->etiqueta, (animal->peso >= 2.5 && animal->peso <= 3.0) ? "Listo para venta" : "Regresar a engorda");
            break;
        case PUERCO:
            strcpy(animal->etiqueta, (animal->peso >= 110.0 && animal->peso <= 120.0) ? "Listo para venta" : "Regresar a engorda");
            break;
        case VACA:
            strcpy(animal->etiqueta, (animal->peso >= 475.0 && animal->peso <= 500.0) ? "Listo para venta" : "Regresar a engorda");
            break;
    }
}

// Leer animales desde archivo
void cargarAnimalesDesdeArchivo(const char *archivoNombre, Cola *cola, TipoAnimal tipo) {
    FILE *archivo = fopen(archivoNombre, "r");
    if (!archivo) {
        perror("Error al abrir archivo");
        return;
    }

    char linea[MAX_LINEA];
    while (fgets(linea, sizeof(linea), archivo)) {
        int id;
        char tipoChar;
        if (sscanf(linea, "%c %d", &tipoChar, &id) == 2) {
            Animal a;
            a.tipo = tipo;
            a.id = id;
            a.peso = 0.0;
            strcpy(a.etiqueta, "");
            encolar(cola, a);
        }
    }

    fclose(archivo);
}

// Estación de pesaje
void *estacionPesaje(void *arg) {
    DatosPesaje *datos = (DatosPesaje *)arg;
    Animal animal;

    while (true) {
        pthread_mutex_lock(&mutexPesaje);
        bool tieneAnimal = desencolar(datos->colaEntrada, &animal);
        pthread_mutex_unlock(&mutexPesaje);

        if (!tieneAnimal) break;

        animal.peso = generarPeso(animal.tipo);
        printf("Pesado ID %d: %.2f\n", animal.id, animal.peso);

        pthread_mutex_lock(&mutexClasificacion);
        encolar(datos->colaSalida, animal);
        pthread_mutex_unlock(&mutexClasificacion);
    }

    return NULL;
}

// Estación de clasificación
void *estacionClasificacion(void *arg) {
    DatosClasificacion *datos = (DatosClasificacion *)arg;
    Animal animal;

    while (true) {
        pthread_mutex_lock(&mutexClasificacion);
        bool tieneAnimal = desencolar(datos->colaEntrada, &animal);
        pthread_mutex_unlock(&mutexClasificacion);

        if (!tieneAnimal) break;

        clasificarAnimal(&animal);
        printf("Clasificado ID %d: %s\n", animal.id, animal.etiqueta);

        char letra = animal.tipo == POLLO ? 'P' : (animal.tipo == PUERCO ? 'C' : 'V');
        fprintf(datos->archivoSalida, "%c %d %.2f %s\n", letra, animal.id, animal.peso, animal.etiqueta);
    }

    return NULL;
}

// Main
int main() {
    srand(time(NULL));

    Cola colaPesaje, colaClasificacion;
    inicializarCola(&colaPesaje);
    inicializarCola(&colaClasificacion);

    // Cargar animales desde archivos
    cargarAnimalesDesdeArchivo("pollos.txt", &colaPesaje, POLLO);
    cargarAnimalesDesdeArchivo("puercos.txt", &colaPesaje, PUERCO);
    cargarAnimalesDesdeArchivo("vacas.txt", &colaPesaje, VACA);

    FILE *archivoSalida = fopen("animales_procesados.txt", "w");
    if (!archivoSalida) {
        perror("No se pudo crear archivo de salida");
        return 1;
    }

    pthread_t hiloPesaje, hiloClasificacion;

    DatosPesaje datosPesaje = { .colaEntrada = &colaPesaje, .colaSalida = &colaClasificacion };
    DatosClasificacion datosClasificacion = { .colaEntrada = &colaClasificacion, .archivoSalida = archivoSalida };

    pthread_create(&hiloPesaje, NULL, estacionPesaje, &datosPesaje);
    pthread_create(&hiloClasificacion, NULL, estacionClasificacion, &datosClasificacion);

    pthread_join(hiloPesaje, NULL);
    pthread_join(hiloClasificacion, NULL);

    fclose(archivoSalida);
    pthread_mutex_destroy(&mutexPesaje);
    pthread_mutex_destroy(&mutexClasificacion);

    return 0;
}
