/*
Nombre: Jesus Vargas Pacheco
Expediente: 750962
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ESTUDIANTES 100 // Definimos el maximo de estudiantes

void limpiar_buffer() { // Funcion para limpiar el buffer de entrada
    int c;  // Variable para almacenar el caracter leido
    while ((c = getchar()) != '\n' && c != EOF);    // Se lee el buffer hasta encontrar un salto de linea o el fin de archivo
    // Se utiliza getchar() para leer un caracter a la vez y se almacena en c
}

typedef struct {    // Definimos la estructura de un estudiante
    // Se definen los campos de la estructura
    int expediente;
    char nombre[50];
    char apellido_paterno[50];
    char apellido_materno[50];
    char carrera[50];
    int duracion_carrera;
    int anio_ingreso;
    float promedio;
    int activo;
} Estudiante;   // Definimos la estructura de un estudiante

// Funcion de mostrar el menu
// Se imprime el menu de opciones para el usuario
void mostrar_menu() {
    printf("\nMenu:\n");
    printf("1. Dar de alta el registro de un estudiante\n");    // Se imprime la opcion 1 para ALTA
    printf("2. Borrar el registro de un estudiante\n");         // Se imprime la opcion 2 para BAJA
    printf("3. Consultar los datos de un estudiante\n");        // Se imprime la opcion 3 para CONSULTA
    printf("4. Modificar los datos de un registro de estudiante\n");    // Se imprime la opcion 4 para MODIFICACION
    printf("5. Filtrar y mostrar estudiantes por carrera\n");           // Se imprime la opcion 5 para FILTRAR_CARRERA
    printf("6. Filtrar y mostrar estudiantes por promedio\n");      // Se imprime la opcion 6 para FILTRAR_PROMEDIO
    printf("7. Filtrar y mostrar estudiantes por años restantes\n");    // Se imprime la opcion 7 para FILTRAR_ANIOS_RESTANTES
    printf("8. Salir\n");         // Se imprime la opcion 8 para SALIR
}

// Prototipos de funciones de manejo de estudiantes
// Se declaran las funciones que se utilizaran en el programa
void dar_alta(Estudiante estudiantes[], int *num_estudiantes);
void borrar_registro(Estudiante estudiantes[], int num_estudiantes);
void consultar_estudiante(Estudiante estudiantes[], int num_estudiantes);
void modificar_registro(Estudiante estudiantes[], int num_estudiantes);
void filtrar_por_carrera(Estudiante estudiantes[], int num_estudiantes);
void filtrar_por_promedio(Estudiante estudiantes[], int num_estudiantes);
void filtrar_por_anios_restantes(Estudiante estudiantes[], int num_estudiantes);

// Funcion de dar de alta un estudiante: ALTA
// Se le pide al usuario que ingrese los datos del estudiante y se almacenan en la estructura
void dar_alta(Estudiante estudiantes[], int *num_estudiantes) {
    if (*num_estudiantes >= MAX_ESTUDIANTES) {  // Se verifica si el maximo de estudiantes ha sido alcanzado
        printf("No se pueden agregar más estudiantes.\n");  // Se notifica al usuario que no se pueden agregar mas estudiantes
        return;
    }

    Estudiante nuevo_estudiante;    // Se declara una variable de tipo Estudiante para almacenar los datos del nuevo estudiante
    printf("Ingrese el numero de expediente: ");    // Se le pide al usuario que ingrese el numero de expediente
    if (scanf("%d", &nuevo_estudiante.expediente) != 1) {   // Se verifica si la entrada es valida
        printf("Entrada invalida.\n");  // Si la entrada no es valida, se imprime un mensaje de error
        limpiar_buffer(); return;   // Si la entrada no es valida, se limpia el buffer y se sale de la funcion
    }

    for (int i = 0; i < *num_estudiantes; i++) {    // Se recorre el arreglo de estudiantes para verificar si el expediente ya existe
        if (estudiantes[i].expediente == nuevo_estudiante.expediente && estudiantes[i].activo) {    // Si el expediente ya existe y el estudiante esta activo
            printf("Ya existe un estudiante con ese numero de expediente.\n");  // Se imprime un mensaje de error
            return;
        }
    }

    limpiar_buffer();
    printf("Ingrese el nombre: ");  // Se le pide al usuario que ingrese el nombre del estudiante
    // Se utiliza fgets para leer una cadena de caracteres con espacios
    fgets(nuevo_estudiante.nombre, sizeof(nuevo_estudiante.nombre), stdin);     // Se lee el nombre del estudiante
    // Se utiliza strcspn para eliminar el salto de linea al final de la cadena
    nuevo_estudiante.nombre[strcspn(nuevo_estudiante.nombre, "\n")] = '\0'; // Se elimina el salto de linea al final de la cadena
    // Se utiliza strcspn para eliminar el salto de linea al final de la cadena

    printf("Ingrese el apellido paterno: ");    // Se le pide al usuario que ingrese el apellido paterno
    // Se utiliza fgets para leer una cadena de caracteres con espacios
    fgets(nuevo_estudiante.apellido_paterno, sizeof(nuevo_estudiante.apellido_paterno), stdin);   // Se lee el apellido paterno del estudiante
    nuevo_estudiante.apellido_paterno[strcspn(nuevo_estudiante.apellido_paterno, "\n")] = '\0'; // Se elimina el salto de linea al final de la cadena
    // Se utiliza strcspn para eliminar el salto de linea al final de la cadena

    printf("Ingrese el apellido materno: ");    // Se le pide al usuario que ingrese el apellido materno
    // Se utiliza fgets para leer una cadena de caracteres con espacios
    fgets(nuevo_estudiante.apellido_materno, sizeof(nuevo_estudiante.apellido_materno), stdin);  // Se lee el apellido materno del estudiante
    nuevo_estudiante.apellido_materno[strcspn(nuevo_estudiante.apellido_materno, "\n")] = '\0'; // Se elimina el salto de linea al final de la cadena
    
    // Se utiliza strcspn para eliminar el salto de linea al final de la cadena
    printf("Ingrese la carrera: ");
    fgets(nuevo_estudiante.carrera, sizeof(nuevo_estudiante.carrera), stdin);
    nuevo_estudiante.carrera[strcspn(nuevo_estudiante.carrera, "\n")] = '\0';

    // Se utiliza strcspn para eliminar el salto de linea al final de la cadena
    printf("Ingrese la duracion de la carrera (en años): ");
    if (scanf("%d", &nuevo_estudiante.duracion_carrera) != 1 || nuevo_estudiante.duracion_carrera <= 0) {
        printf("Duracion invalida.\n"); limpiar_buffer(); return;
    }

    // Se verifica si la duracion de la carrera es valida, en caso contrario se imprime un mensaje de error y se sale de la funcion
    printf("Ingrese el año de ingreso: ");
    if (scanf("%d", &nuevo_estudiante.anio_ingreso) != 1) {
        printf("Año invalido.\n"); limpiar_buffer(); return;
    }

    // Se verifica si el año de ingreso es valido, en caso contrario se imprime un mensaje de error y se sale de la funcion
    printf("Ingrese el promedio: ");
    if (scanf("%f", &nuevo_estudiante.promedio) != 1 || nuevo_estudiante.promedio < 0 || nuevo_estudiante.promedio > 10) {
        printf("Promedio invalido.\n"); limpiar_buffer(); return;
    }

    // Se verifica si el promedio es valido, en caso contrario se imprime un mensaje de error y se sale de la funcion
    // Se inicializa el campo activo en 1 (activo)
    nuevo_estudiante.activo = 1;
    estudiantes[*num_estudiantes] = nuevo_estudiante;
    (*num_estudiantes)++;
}

// Funcion de borrar un registro de estudiante: BAJA
// Se le pide al usuario que ingrese el numero de expediente del estudiante a borrar
void borrar_registro(Estudiante estudiantes[], int num_estudiantes) {
    int expediente; // Variable para almacenar el numero de expediente del estudiante a borrar
    printf("Ingrese el numero de expediente del estudiante a borrar: ");    // Se le pide al usuario que ingrese el numero de expediente
    if (scanf("%d", &expediente) != 1) { limpiar_buffer(); return; }    // Se verifica si la entrada es valida
    // Si la entrada no es valida, se imprime un mensaje de error y se sale de la funcion

    for (int i = 0; i < num_estudiantes; i++) {   // Se recorre el arreglo de estudiantes para buscar el expediente
        if (estudiantes[i].expediente == expediente && estudiantes[i].activo) {   // Si se encuentra el expediente y el estudiante esta activo
            estudiantes[i].activo = 0;  // Se marca el estudiante como inactivo
            printf("Registro borrado.\n");  // Se imprime un mensaje de confirmacion
            return; // Se sale de la funcion
        }
    }
    printf("Estudiante no encontrado.\n");  // Si no se encuentra el expediente, se imprime un mensaje de error
    // Se imprime un mensaje de error
}

void consultar_estudiante(Estudiante estudiantes[], int num_estudiantes) {  // Funcion de consultar un estudiante: CONSULTA
    int expediente; // Variable para almacenar el numero de expediente del estudiante a consultar
    printf("Ingrese el numero de expediente: ");    // Se le pide al usuario que ingrese el numero de expediente
    if (scanf("%d", &expediente) != 1) { limpiar_buffer(); return; }    // Se verifica si la entrada es valida
    // Si la entrada no es valida, se imprime un mensaje de error y se sale de la funcion

    for (int i = 0; i < num_estudiantes; i++) {  // Se recorre el arreglo de estudiantes para buscar el expediente
        if (estudiantes[i].expediente == expediente && estudiantes[i].activo) {  // Si se encuentra el expediente y el estudiante esta activo
            printf("\nExpediente: %d\nNombre: %s\nApellido Paterno: %s\nApellido Materno: %s\nCarrera: %s\nDuracion: %d\nIngreso: %d\nPromedio: %.2f\n",    // Se imprimen los datos del estudiante
                   estudiantes[i].expediente, estudiantes[i].nombre, estudiantes[i].apellido_paterno,   
                   estudiantes[i].apellido_materno, estudiantes[i].carrera,
                   estudiantes[i].duracion_carrera, estudiantes[i].anio_ingreso, estudiantes[i].promedio);
            return;
        }
    }
    printf("Estudiante no encontrado.\n");  // Si no se encuentra el expediente, se imprime un mensaje de error
}

// Funcion de modificar un registro de estudiante: MODIFICACION
// Se le pide al usuario que ingrese el numero de expediente del estudiante a modificar
void modificar_registro(Estudiante estudiantes[], int num_estudiantes) {
    int expediente;
    printf("Ingrese el numero de expediente del estudiante a modificar: ");
    if (scanf("%d", &expediente) != 1) { limpiar_buffer(); return; }
    limpiar_buffer();

    for (int i = 0; i < num_estudiantes; i++) { // Se recorre el arreglo de estudiantes para buscar el expediente
        if (estudiantes[i].expediente == expediente && estudiantes[i].activo) { // Si se encuentra el expediente y el estudiante esta activo
            printf("Ingrese el nuevo nombre: ");    // Se le pide al usuario que ingrese el nuevo nombre
            fgets(estudiantes[i].nombre, sizeof(estudiantes[i].nombre), stdin);   // Se lee el nuevo nombre del estudiante
            estudiantes[i].nombre[strcspn(estudiantes[i].nombre, "\n")] = '\0'; // Se elimina el salto de linea al final de la cadena

            printf("Ingrese el nuevo apellido paterno: ");  // Se le pide al usuario que ingrese el nuevo apellido paterno
            fgets(estudiantes[i].apellido_paterno, sizeof(estudiantes[i].apellido_paterno), stdin); // Se lee el nuevo apellido paterno del estudiante
            estudiantes[i].apellido_paterno[strcspn(estudiantes[i].apellido_paterno, "\n")] = '\0'; // Se elimina el salto de linea al final de la cadena
            // Se utiliza strcspn para eliminar el salto de linea al final de la cadena

            printf("Ingrese el nuevo apellido materno: ");  // Se le pide al usuario que ingrese el nuevo apellido materno
            fgets(estudiantes[i].apellido_materno, sizeof(estudiantes[i].apellido_materno), stdin); // Se lee el nuevo apellido materno del estudiante
            estudiantes[i].apellido_materno[strcspn(estudiantes[i].apellido_materno, "\n")] = '\0'; // Se elimina el salto de linea al final de la cadena
            // Se utiliza strcspn para eliminar el salto de linea al final de la cadena

            printf("Ingrese la nueva carrera: ");   // Se le pide al usuario que ingrese la nueva carrera
            fgets(estudiantes[i].carrera, sizeof(estudiantes[i].carrera), stdin);   // Se lee la nueva carrera del estudiante
            estudiantes[i].carrera[strcspn(estudiantes[i].carrera, "\n")] = '\0';   // Se elimina el salto de linea al final de la cadena
            // Se utiliza strcspn para eliminar el salto de linea al final de la cadena

            printf("Ingrese la nueva duracion de la carrera: ");    // Se le pide al usuario que ingrese la nueva duracion de la carrera
            scanf("%d", &estudiantes[i].duracion_carrera);  // Se lee la nueva duracion de la carrera del estudiante
            printf("Ingrese el nuevo año de ingreso: ");    // Se le pide al usuario que ingrese el nuevo año de ingreso
            scanf("%d", &estudiantes[i].anio_ingreso);  // Se lee el nuevo año de ingreso del estudiante
            printf("Ingrese el nuevo promedio: ");  // Se le pide al usuario que ingrese el nuevo promedio
            scanf("%f", &estudiantes[i].promedio);  // Se lee el nuevo promedio del estudiante
            // Se verifica si el promedio es valido, en caso contrario se imprime un mensaje de error y se sale de la funcion
            printf("Registro modificado.\n");   // Se imprime un mensaje de confirmacion
            return;
        }
    }
    printf("Estudiante no encontrado.\n");  // Si no se encuentra el expediente, se imprime un mensaje de error
}

// Funcion de filtrar estudiantes por carrera: FILTRAR_CARRERA
// Se le pide al usuario que ingrese la carrera por la que se desea filtrar
void filtrar_por_carrera(Estudiante estudiantes[], int num_estudiantes) {
    char carrera[50];   // Variable para almacenar la carrera por la que se desea filtrar
    printf("Ingrese la carrera: "); // Se le pide al usuario que ingrese la carrera por la que se desea filtrar
    limpiar_buffer();   // Se limpia el buffer de entrada
    fgets(carrera, sizeof(carrera), stdin); // Se lee la carrera por la que se desea filtrar
    carrera[strcspn(carrera, "\n")] = '\0'; // Se elimina el salto de linea al final de la cadena

    printf("Estudiantes en la carrera %s:\n", carrera); // Se imprime la carrera por la que se desea filtrar
    for (int i = 0; i < num_estudiantes; i++) { // Se recorre el arreglo de estudiantes para buscar la carrera
        if (estudiantes[i].activo && strcmp(estudiantes[i].carrera, carrera) == 0) {    // Si se encuentra la carrera y el estudiante esta activo
            printf("Expediente: %d | %s %s %s | Promedio: %.2f\n", estudiantes[i].expediente,   // Se imprimen los datos del estudiante
                   estudiantes[i].nombre, estudiantes[i].apellido_paterno, estudiantes[i].apellido_materno, 
                   estudiantes[i].promedio);
        }
    }
}

// Funcion de filtrar estudiantes por promedio: FILTRAR_PROMEDIO
// Se le pide al usuario que ingrese el promedio por el que se desea filtrar
void filtrar_por_promedio(Estudiante estudiantes[], int num_estudiantes) {
    float promedio_minimo;  // Variable para almacenar el promedio por el que se desea filtrar
    printf("Ingrese el promedio minimo: "); // Se le pide al usuario que ingrese el promedio por el que se desea filtrar
    if (scanf("%f", &promedio_minimo) != 1) { limpiar_buffer(); return; }   // Se verifica si la entrada es valida

    printf("Estudiantes con promedio mayor o igual a %.2f:\n", promedio_minimo);    // Se imprime el promedio por el que se desea filtrar
    for (int i = 0; i < num_estudiantes; i++) { // Se recorre el arreglo de estudiantes para buscar el promedio
        if (estudiantes[i].activo && estudiantes[i].promedio >= promedio_minimo) {  // Si se encuentra el promedio y el estudiante esta activo
            printf("Expediente: %d | %s %s %s | Promedio: %.2f\n", estudiantes[i].expediente,   // Se imprimen los datos del estudiante
                   estudiantes[i].nombre, estudiantes[i].apellido_paterno, estudiantes[i].apellido_materno, 
                   estudiantes[i].promedio);
        }
    }
}

// Funcion de filtrar estudiantes por años restantes: FILTRAR_ANIOS_RESTANTES
// Se le pide al usuario que ingrese el numero de años restantes por los que se desea filtrar
void filtrar_por_anios_restantes(Estudiante estudiantes[], int num_estudiantes) {
    int anios_restantes;    // Variable para almacenar el numero de años restantes por los que se desea filtrar
    printf("Ingrese el numero de años restantes: ");    // Se le pide al usuario que ingrese el numero de años restantes por los que se desea filtrar
    scanf("%d", &anios_restantes);  // Se lee el numero de años restantes por los que se desea filtrar
    // Se verifica si la entrada es valida, en caso contrario se imprime un mensaje de error y se sale de la funcion

    time_t t = time(NULL);  // Se obtiene el tiempo actual
    struct tm tm = *localtime(&t);  // Se convierte el tiempo actual a una estructura tm
    int anio_actual = tm.tm_year + 1900;    // Se obtiene el año actual sumando 1900 al campo tm_year de la estructura tm
    // Se obtiene el año actual sumando 1900 al campo tm_year de la estructura tm

    printf("Estudiantes con %d años restantes:\n", anios_restantes);    // Se imprime el numero de años restantes por los que se desea filtrar
    // Se imprime el numero de años restantes por los que se desea filtrar
    for (int i = 0; i < num_estudiantes; i++) { // Se recorre el arreglo de estudiantes para buscar los años restantes
        if (!estudiantes[i].activo) continue;   // Si el estudiante no esta activo, se salta al siguiente estudiante
        int cursados = anio_actual - estudiantes[i].anio_ingreso;   // Se calcula el numero de años cursados por el estudiante
        int restantes = estudiantes[i].duracion_carrera - cursados; // Se calcula el numero de años restantes por el estudiante
        if (restantes == anios_restantes && restantes >= 0) {   // Si el numero de años restantes es igual al numero de años restantes por los que se desea filtrar
            printf("Expediente: %d | %s %s %s | Restantes: %d\n", estudiantes[i].expediente,    // Se imprimen los datos del estudiante
                   estudiantes[i].nombre, estudiantes[i].apellido_paterno, estudiantes[i].apellido_materno,
                   restantes);
        }
    }
}

// Funcion principal: MAIN
// Se inicializan los estudiantes y se muestra el menu de opciones
int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];    // Se declara un arreglo de estudiantes con el maximo de estudiantes
    int num_estudiantes = 0, opcion;    // Se inicializa el numero de estudiantes en 0 y la opcion en 0
    // Se inicializa el numero de estudiantes en 0 y la opcion en 0
    do {
        mostrar_menu(); // Se llama a la funcion de mostrar el menu
        printf("Seleccione una opcion: ");
        if (scanf("%d", &opcion) != 1) { limpiar_buffer(); opcion = 0; }    // Se verifica si la entrada es valida
        // Si la entrada no es valida, se imprime un mensaje de error y se sale de la funcion
        switch (opcion) {   // Se utiliza un switch para seleccionar la opcion del menu
            case 1: dar_alta(estudiantes, &num_estudiantes); break;
            case 2: borrar_registro(estudiantes, num_estudiantes); break;
            case 3: consultar_estudiante(estudiantes, num_estudiantes); break;
            case 4: modificar_registro(estudiantes, num_estudiantes); break;
            case 5: filtrar_por_carrera(estudiantes, num_estudiantes); break;
            case 6: filtrar_por_promedio(estudiantes, num_estudiantes); break;
            case 7: filtrar_por_anios_restantes(estudiantes, num_estudiantes); break;
            case 8: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while (opcion != 8);  // Se repite el menu hasta que el usuario seleccione la opcion de salir
    // Se repite el menu hasta que el usuario seleccione la opcion de salir

    return 0;
}
