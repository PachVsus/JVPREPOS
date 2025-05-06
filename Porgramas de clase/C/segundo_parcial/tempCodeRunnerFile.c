/*Crea un programa en C que realice las siguientes operaciones con registros de estudiantes:

Dar de alta el registro de un estudiante.
Borrar el registro de un estudiante.
Consultar los datos de un estudiante a partir de que el usuario capture su número de expediente.
Modificar los datos de un registro de estudiante.
Filtrar y mostrar en pantalla a los estudiantes de una determinada carrera.
Filtrar y mostrar en pantalla a los estudiantes que tienen un promedio superior al indicado por el usuario.
Filtrar y mostrar en pantalla a los estudiantes que aún les quedan 1 o 2 o 3 o 4 años por cursar, según lo solicite el usuario (para hacer el cálculo del tiempo que aún le queda a un estudiante debe tomarse en cuenta la fecha actual, su fecha de ingreso y la duración del plan de estudios de la carrera en la que está inscrito).
Los datos que un registro de estudiante debe tener, son:

Número de cuenta o de expediente (son números enteros que empiezan en 1).
Nombre.
Apellido paterno.
Apellido materno.
Carrera.
Duración de la carrera (en años).
Año de ingreso.
Promedio General*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ESTUDIANTES 100


typedef struct {
    int expediente;
    char nombre[50];
    char apellido_paterno[50];
    char apellido_materno[50];
    char carrera[50];
    int duracion_carrera;
    int anio_ingreso;
    float promedio;
    int activo; // 1: activo, 0: borrado
} Estudiante;   // Estructura para almacenar los datos de un estudiante

// Menú para mostrar las opciones al usuario
void mostrar_menu() {
    printf("Menu:\n");
    printf("1. Dar de alta el registro de un estudiante\n");
    printf("2. Borrar el registro de un estudiante\n");
    printf("3. Consultar los datos de un estudiante\n");
    printf("4. Modificar los datos de un registro de estudiante\n");
    printf("5. Filtrar y mostrar estudiantes por carrera\n");
    printf("6. Filtrar y mostrar estudiantes por promedio\n");
    printf("7. Filtrar y mostrar estudiantes por años restantes\n");
    printf("8. Salir\n");
}

// Función para dar de alta el registro de un estudiante: ALTA
void dar_alta(Estudiante estudiantes[], int *num_estudiantes) {
    if (*num_estudiantes >= MAX_ESTUDIANTES) {
        printf("No se pueden agregar mas estudiantes.\n");
        return;
    }

    Estudiante nuevo_estudiante;
    printf("Ingrese el numero de expediente: ");
    scanf("%d", &nuevo_estudiante.expediente);
    printf("Ingrese el nombre: ");
    while (getchar() != '\n'); // Clear input buffer
    fgets(nuevo_estudiante.nombre, sizeof(nuevo_estudiante.nombre), stdin);
    nuevo_estudiante.nombre[strcspn(nuevo_estudiante.nombre, "\n")] = '\0'; // Remove trailing newline
    printf("Ingrese el apellido paterno: ");
    while (getchar() != '\n'); // Clear input buffer
    fgets(nuevo_estudiante.apellido_paterno, sizeof(nuevo_estudiante.apellido_paterno), stdin);
    nuevo_estudiante.apellido_paterno[strcspn(nuevo_estudiante.apellido_paterno, "\n")] = '\0';
    printf("Ingrese el apellido materno: ");
    while (getchar() != '\n'); // Clear input buffer
    fgets(nuevo_estudiante.apellido_materno, sizeof(nuevo_estudiante.apellido_materno), stdin);
    nuevo_estudiante.apellido_materno[strcspn(nuevo_estudiante.apellido_materno, "\n")] = '\0';
    printf("Ingrese la carrera: ");
    while (getchar() != '\n'); // Clear input buffer
    fgets(nuevo_estudiante.carrera, sizeof(nuevo_estudiante.carrera), stdin);
    nuevo_estudiante.carrera[strcspn(nuevo_estudiante.carrera, "\n")] = '\0';
    printf("Ingrese la carrera: ");
    fgets(nuevo_estudiante.carrera, sizeof(nuevo_estudiante.carrera), stdin);
    nuevo_estudiante.carrera[strcspn(nuevo_estudiante.carrera, "\n")] = '\0';
    printf("Ingrese la duracion de la carrera (en años): ");
    scanf("%d", &nuevo_estudiante.duracion_carrera);
    printf("Ingrese el año de ingreso: ");
    scanf("%d", &nuevo_estudiante.anio_ingreso);
    printf("Ingrese el promedio: ");
    scanf("%f", &nuevo_estudiante.promedio);

    nuevo_estudiante.activo = 1; // Establecer como activo
    estudiantes[*num_estudiantes] = nuevo_estudiante;
    (*num_estudiantes)++;
}

// Función para borrar el registro de un estudiante: BAJA
void borrar_registro(Estudiante estudiantes[], int num_estudiantes) {
    int expediente;
    printf("Ingrese el numero de expediente del estudiante a borrar: ");
    scanf("%d", &expediente);

    for (int i = 0; i < num_estudiantes; i++) {
        if (estudiantes[i].expediente == expediente) {
            estudiantes[i].activo = 0; // Marcar como borrado
            printf("Registro borrado.\n");
            return;
        }
    }
    printf("Estudiante no encontrado.\n");
}

// Función para consultar los datos de un estudiante: CONSULTA
void consultar_estudiante(Estudiante estudiantes[], int num_estudiantes) {
    int expediente;
    printf("Ingrese el numero de expediente del estudiante a consultar: ");
    scanf("%d", &expediente);

    for (int i = 0; i < num_estudiantes; i++) {
        if (estudiantes[i].expediente == expediente && estudiantes[i].activo) {
            printf("Numero de expediente: %d\n", estudiantes[i].expediente);
            printf("Nombre: %s\n", estudiantes[i].nombre);
            printf("Apellido paterno: %s\n", estudiantes[i].apellido_paterno);
            printf("Apellido materno: %s\n", estudiantes[i].apellido_materno);
            printf("Carrera: %s\n", estudiantes[i].carrera);
            printf("Duracion de la carrera: %d años\n", estudiantes[i].duracion_carrera);
            printf("Anio de ingreso: %d\n", estudiantes[i].anio_ingreso);
            printf("Promedio: %.2f\n", estudiantes[i].promedio);
            return;
        }
    }
    printf("Estudiante no encontrado.\n");
}

// Función para modificar los datos de un registro de estudiante: MODIFICACION
void modificar_registro(Estudiante estudiantes[], int num_estudiantes) {
    int expediente;
    printf("Ingrese el numero de expediente del estudiante a modificar: ");
    scanf("%d", &expediente);

    for (int i = 0; i < num_estudiantes; i++) {
        if (estudiantes[i].expediente == expediente && estudiantes[i].activo) {
            printf("Ingrese el nuevo nombre: ");
            scanf("%s", estudiantes[i].nombre);
            printf("Ingrese el nuevo apellido paterno: ");
            scanf("%s", estudiantes[i].apellido_paterno);
            printf("Ingrese el nuevo apellido materno: ");
            scanf("%s", estudiantes[i].apellido_materno);
            printf("Ingrese la nueva carrera: ");
            scanf("%s", estudiantes[i].carrera);
            printf("Ingrese la nueva duracion de la carrera (en años): ");
            scanf("%d", &estudiantes[i].duracion_carrera);
            printf("Ingrese el nuevo anio de ingreso: ");
            scanf("%d", &estudiantes[i].anio_ingreso);
            printf("Ingrese el nuevo promedio: ");
            scanf("%f", &estudiantes[i].promedio);
            printf("Registro modificado.\n");
            return;
        }
    }
    printf("Estudiante no encontrado.\n");
}

// Función para filtrar y mostrar estudiantes por carrera: FILTRAR_CARRERA
void filtrar_por_carrera(Estudiante estudiantes[], int num_estudiantes) {
    char carrera[50];
    printf("Ingrese la carrera a filtrar: ");
    scanf("%s", carrera);

    printf("Estudiantes de la carrera %s:\n", carrera);
    for (int i = 0; i < num_estudiantes; i++) {
        if (strcmp(estudiantes[i].carrera, carrera) == 0 && estudiantes[i].activo) {    // Comparar cadenas
            printf("Numero de expediente: %d\n", estudiantes[i].expediente);    // Mostrar datos del estudiante
            printf("Nombre: %s\n", estudiantes[i].nombre);                      // Mostrar nombre
            printf("Apellido paterno: %s\n", estudiantes[i].apellido_paterno);  // Mostrar apellido paterno
            printf("Apellido materno: %s\n", estudiantes[i].apellido_materno);  // Mostrar apellido materno
            printf("Duracion de la carrera: %d años\n", estudiantes[i].duracion_carrera);   // Mostrar duracion de la carrera
            printf("Anio de ingreso: %d\n", estudiantes[i].anio_ingreso);   // Mostrar anio de ingreso
            printf("Promedio: %.2f\n", estudiantes[i].promedio);        // Mostrar promedio
        }
    }
}

// Función para filtrar y mostrar estudiantes por promedio: FILTRAR_PROMEDIO
void filtrar_por_promedio(Estudiante estudiantes[], int num_estudiantes) {
    float promedio;
    printf("Ingrese el promedio a filtrar: ");
    scanf("%f", &promedio);

    printf("Estudiantes con promedio superior a %.2f:\n", promedio);
    for (int i = 0; i < num_estudiantes; i++) {
        if (estudiantes[i].promedio > promedio && estudiantes[i].activo) {   // Comparar promedios
            printf("Numero de expediente: %d\n", estudiantes[i].expediente);   // Mostrar datos del estudiante
            printf("Nombre: %s\n", estudiantes[i].nombre);                     // Mostrar nombre
            printf("Apellido paterno: %s\n", estudiantes[i].apellido_paterno); // Mostrar apellido paterno
            printf("Apellido materno: %s\n", estudiantes[i].apellido_materno); // Mostrar apellido materno
            printf("Carrera: %s\n", estudiantes[i].carrera);                   // Mostrar carrera
            printf("Duracion de la carrera: %d años\n", estudiantes[i].duracion_carrera);  // Mostrar duracion de la carrera
            printf("Anio de ingreso: %d\n", estudiantes[i].anio_ingreso);   // Mostrar anio de ingreso
        }
    }
}

// Función para filtrar y mostrar estudiantes por años restantes: FILTRAR_ANIOS_RESTANTES
void filtrar_por_anios_restantes(Estudiante estudiantes[], int num_estudiantes) {
    int anios_restantes;
    printf("Ingrese el numero de años restantes: ");
    scanf("%d", &anios_restantes);

    time_t t = time(NULL); // Obtener la fecha actual
    struct tm tm = *localtime(&t); // Convertir a estructura tm
    int anio_actual = tm.tm_year + 1900; // Obtener el año actual

    printf("Estudiantes con %d años restantes:\n", anios_restantes);
    for (int i = 0; i < num_estudiantes; i++) {
        if (estudiantes[i].activo && (anio_actual - estudiantes[i].anio_ingreso) <= estudiantes[i].duracion_carrera - anios_restantes) {   // Comparar años restantes
            printf("Numero de expediente: %d\n", estudiantes[i].expediente);   // Mostrar datos del estudiante
            printf("Nombre: %s\n", estudiantes[i].nombre);                     // Mostrar nombre
            printf("Apellido paterno: %s\n", estudiantes[i].apellido_paterno); // Mostrar apellido paterno
            printf("Apellido materno: %s\n", estudiantes[i].apellido_materno); // Mostrar apellido materno
            printf("Carrera: %s\n", estudiantes[i].carrera);                   // Mostrar carrera
            printf("Duracion de la carrera: %d años\n", estudiantes[i].duracion_carrera);  // Mostrar duracion de la carrera
            printf("Anio de ingreso: %d\n", estudiantes[i].anio_ingreso);   // Mostrar anio de ingreso
        }
    }
}

// Función principal
int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES]; // Arreglo para almacenar los estudiantes
    int num_estudiantes = 0; // Contador de estudiantes

    int opcion;
    do {
        mostrar_menu(); // Mostrar el menú
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion); // Leer la opción del usuario

        switch (opcion) {
            case 1:
                dar_alta(estudiantes, &num_estudiantes); // Dar de alta un estudiante
                break;
            case 2:
                borrar_registro(estudiantes, num_estudiantes); // Borrar un registro de estudiante
                break;
            case 3:
                consultar_estudiante(estudiantes, num_estudiantes); // Consultar datos de un estudiante
                break;
            case 4:
                modificar_registro(estudiantes, num_estudiantes); // Modificar un registro de estudiante
                break;
            case 5:
                filtrar_por_carrera(estudiantes, num_estudiantes); // Filtrar estudiantes por carrera
                break;
            case 6:
                filtrar_por_promedio(estudiantes, num_estudiantes); // Filtrar estudiantes por promedio
                break;
            case 7:
                filtrar_por_anios_restantes(estudiantes, num_estudiantes); // Filtrar estudiantes por años restantes
                break;
            case 8:
                printf("Saliendo del programa...\n"); // Salir del programa
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n"); // Opción inválida
        }
    } while (opcion != 8); // Repetir hasta que el usuario elija salir

    return 0; // Fin del programa
}