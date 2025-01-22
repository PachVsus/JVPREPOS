#include <stdio.h>
#include <stdlib.h>

int main(void) {

struct Alumno {
    int ID;
    char Nombre[20];
    char Apellido[20];
    int Semestre;
    struct Tablas {
        char Materias[20];
        float Calificacion;
    } Tablas[6];
};

struct Alumno Alumno1;
struct Alumno *pAlumno;

scanf("%d", &Alumno1.ID);
scanf("%s", Alumno1.Nombre);
scanf("%s", Alumno1.Apellido);
scanf("%d", &Alumno1.Semestre);

printf("ID: %d\n", Alumno1.ID);
printf("Nombre: %s\n", Alumno1.Nombre);
printf("Apellido: %s\n", Alumno1.Apellido);
printf("Semestre: %d\n", Alumno1.Semestre);
