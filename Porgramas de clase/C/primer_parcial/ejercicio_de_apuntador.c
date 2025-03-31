#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// diferencia entre (*) y (&): (*) se usa para declarar un apuntador y para acceder a la direccion de memoria de una variable, (&) se usa para acceder a la direccion de memoria de una variable, en otras palabras, para acceder al contenido de una variable se usa (*), para acceder a la direccion de memoria de una variable se usa (&)

struct Alumno { // Definicion de la estructura
    int ID;
    char Nombre[20];
    char Apellido[20];
    int Semestre;
    struct Tablas { // se puede declarar una estructura dentro de otra estructura, sirve para organizar mejor los datos
        char Materias[20];
        float Calificacion;
    } Tablas[6]; // Se declara un arreglo de estructuras, para almacenar las materias y calificaciones

};

int main(void) {
    
        struct Alumno Alumno1; // Declaracion de una variable de tipo estructura
        struct Alumno *Alumno; // Declaracion de un apuntador a la estructura, (*) ayuda a declarar un apuntador y a acceder al contenido de la direccion de memoria de una variable
    
        Alumno = &Alumno1; // Asignacion de la direccion de memoria de la variable Alumno1 al apuntador Alumno. (&) se usa para acceder a la direccion de memoria de una variable

        printf("Ingrese los datos del alumno\n");
        printf("ID: ");
        scanf("%d", &Alumno->ID); // Se accede al campo ID de la estructura a traves del apuntador
        printf("Nombre: ");
        scanf("%s", Alumno->Nombre); // Se accede al campo Nombre de la estructura a traves del apuntador
        printf("Apellido: ");
        scanf("%s", Alumno->Apellido); // Se accede al campo Apellido de la estructura a traves del apuntador
        printf("Semestre: ");
        scanf("%d", &Alumno->Semestre); // Se accede al campo Semestre de la estructura a traves del apuntador
    
        printf("ID: %d\n", Alumno->ID); // Se accede al campo ID de la estructura a traves del apuntador
        printf("Nombre: %s\n", Alumno->Nombre); // Se accede al campo Nombre de la estructura a traves del apuntador
        printf("Apellido: %s\n", Alumno->Apellido); // Se accede al campo Apellido de la estructura a traves del apuntador
        printf("Semestre: %d\n", Alumno->Semestre); // Se accede al campo Semestre de la estructura a traves del apuntador
    
        return 0;
}