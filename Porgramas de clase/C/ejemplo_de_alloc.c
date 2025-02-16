#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Realizar un programa que lea una cadena. La asignacion de la cadena debe ser de forma dinamica.

#define LONGITUD 30

void main(void) {
    char *szCadena;

    /*Realiza la asignación*/
    szCadena = (char *)malloc(sizeof(char) * LONGITUD);

    /*Verifica si la asignación fue correcta*/
    if (szCadena == NULL) {
        printf("Error en la asignación de memoria\n");
        return;
    }
    else {
        printf("\n Digite una cadena: ");
        gets(szCadena);
        printf("\n La cadena es: %s\n", szCadena);
        free(szCadena);
    }
    printf("\n");
}