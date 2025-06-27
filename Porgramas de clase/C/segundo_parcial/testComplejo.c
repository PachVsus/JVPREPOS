#include <stdio.h>
#include <stdlib.h>
#include "complejo.h"

int main(void) {
    Complejo* c1 = crearComplejo(3.0, 4.0);
    Complejo* c2 = crearComplejo(1.0, 2.0);

    Complejo* suma = sumar(c1, c2);
    Complejo* producto = multiplicar(c1, c2);
    Complejo* division = dividir(c1, c2);
    Complejo* raiz = raizCuadrada(c1);

    char* c1Str = complejoToString(c1);
    char* sumaStr = complejoToString(suma);
    char* prodStr = complejoToString(producto);
    char* divStr = complejoToString(division);
    char* raizStr = complejoToString(raiz);

    printf("C1: %s\n", c1Str);
    printf("C2: %s\n", complejoToString(c2));
    printf("Suma: %s\n", sumaStr);
    printf("Producto: %s\n", prodStr);
    printf("División: %s\n", divStr);
    printf("Raíz cuadrada de C1: %s\n", raizStr);

    liberarComplejo(c1);
    liberarComplejo(c2);
    liberarComplejo(suma);
    liberarComplejo(producto);
    liberarComplejo(division);
    liberarComplejo(raiz);

    free(c1Str);
    free(sumaStr);
    free(prodStr);
    free(divStr);
    free(raizStr);

    return 0;
}

