#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    // (*) se usa para declarar un apuntador y para acceder a la direccion de memoria de una variable
    // (&) se usa para acceder a la direccion de memoria de una variable
    // Pasos para aplicar apuntadores
    // 1. Declarar una variable, ejemplo: int a;
    // 2. Declarar un apuntador, ejemplo: int *p;
    // 3. Asignar la direccion de memoria de la variable a un apuntador, ejemplo: p = &a;
    // 4. Acceder al valor de la variable a traves del apuntador, ejemplo: *p = 10;

    struct Alumno { // Definicion de la estructura
        int ID; // Campos de la estructura
        char Nombre[20];   // Campos de la estructura
        char Apellido[20];
        int Semestre;
        struct Tablas {
            char Materias[20];
            float Calificacion;
        } Tablas[6];
    };

    struct Alumno Alumno1;
    struct Alumno *Alumno;      // Declaracion de un apuntador a la estructura

    scanf("%d", &Alumno1.ID);
    scanf("%s", Alumno1.Nombre);
    scanf("%s", Alumno1.Apellido);
    scanf("%d", &Alumno1.Semestre);

    printf("ID: %d\n", Alumno1.ID);
    printf("Nombre: %s\n", Alumno1.Nombre);
    printf("Apellido: %s\n", Alumno1.Apellido);
    printf("Semestre: %d\n", Alumno1.Semestre);

    return 0;
}

