/*Crea un programa en C que haga lo siguiente:

Pida al usuario la cantidad de estudiantes que quiere registrar.
Reserve memoria dinámicamente para almacenar las calificaciones de cada estudiante.
Permita al usuario ingresar las calificaciones de los estudiantes.
Calcule e imprima:
El promedio de las calificaciones.
La calificación más alta.
La calificación más baja.
Libere la memoria asignada dinámicamente antes de salir.
📌 Restricciones y Reglas
Usa malloc o calloc para asignar memoria.
Usa free al final para liberar la memoria.
Utiliza apuntadores para manipular los datos.
🔹 Extra: Si quieres hacer el ejercicio más desafiante, permite que el usuario pueda modificar alguna calificación antes de calcular el promedio.
Ingrese el número de estudiantes: 4
Ingrese la calificación del estudiante 1: 78
Ingrese la calificación del estudiante 2: 85
Ingrese la calificación del estudiante 3: 90
Ingrese la calificación del estudiante 4: 73

Promedio: 81.50
Nota más alta: 90
Nota más baja: 73

*/


#include <stdio.h>
#include <stdlib.h>

int main(void) {
    struct Alumno {
        float calificacion;
    };

    int num_estudiantes;
    float promedio = 0;
    float calificacion_mas_alta = 0;
    float calificacion_mas_baja = 100;

    printf("Ingrese el número de estudiantes: ");
    scanf("%d", &num_estudiantes);

    struct Alumno *estudiantes = (struct Alumno *)malloc(num_estudiantes * sizeof(struct Alumno)); // Reservar memoria dinámicamente con malloc

    for (int i = 0; i < num_estudiantes; i++) {
        printf("Ingrese la calificación del estudiante %d: ", i + 1);
        scanf("%f", &estudiantes[i].calificacion);
        promedio += estudiantes[i].calificacion;

        if (estudiantes[i].calificacion > calificacion_mas_alta) {
            calificacion_mas_alta = estudiantes[i].calificacion;
        }

        if (estudiantes[i].calificacion < calificacion_mas_baja) {
            calificacion_mas_baja = estudiantes[i].calificacion;
        }
    }

    promedio /= num_estudiantes;

    printf("\nPromedio: %.2f\n", promedio);
    printf("Nota más alta: %.0f\n", calificacion_mas_alta);
    printf("Nota más baja: %.0f\n", calificacion_mas_baja);

    free(estudiantes);

    return 0;


}