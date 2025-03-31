// Recibe del usuario una cadena de caracteres e imprimirla al reves

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    char cadena[100];
    char *pCadena;
    int i = 0;

    pCadena = cadena;

    printf("Introduce una cadena de caracteres: ");
    scanf("%s", cadena);

    while (*pCadena != '\0') {
        pCadena++;
        i++;
    }

    for (i = i - 1; i >= 0; i--) {
        printf("%c", cadena[i]);
    }

    printf("\n");

    return 0;
}