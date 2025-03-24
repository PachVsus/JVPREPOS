// Jesus Vargas Pacheco

#include <stdio.h>
#include <stdlib.h>

int func1(int n) {  // Función que recibe un entero y regresa el doble más uno
    return 2*n+1;   // Regresa el doble más uno del entero
}

int func2(int n) {      // Función que recibe un entero y regresa el triple
    return 3*n;         // Regresa el triple del entero
}                    // Fin de la función

typedef int (*Op) (int);        // Definimos un tipo de dato Op que es un apuntador a una función que recibe un entero y regresa un entero

void callFunc(Op func, int n) {    // Función que recibe un apuntador a una función y un entero
    printf("f(%d) = %d\n", n, func(n)); // Imprime el valor de la función en el entero
}

int main() {        // Función principal
    Op Op;        // Declaramos un apuntador a una función

    for (int i = 0; i < 10; i++) {  // Iteramos sobre los números del 0 al 9
        if (i % 3 == 0) {        // Si el número es divisible entre 3
            Op = func1;     // Asignamos la función func1 al apuntador
        } else {        // Si no
            Op = func2;     // Asignamos la función func2 al apuntador
        }        // Fin del if
        callFunc(Op, i);        // Llamamos a la función callFunc con el apuntador y el número
    }
}