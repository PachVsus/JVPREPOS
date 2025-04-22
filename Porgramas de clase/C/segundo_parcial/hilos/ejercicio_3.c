// Jesus Vargas Pacheco

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_CADENA 256  // Definición del tamaño máximo de la cadena

// Función para eliminar espacios y convertir a minúsculas
void limpiarCadena(const char *entrada, char *salida) { // Elimina espacios y convierte a minúsculas
    int j = 0;
    for (int i = 0; entrada[i] != '\0'; i++) {  // Recorre la cadena de entrada
        if (isalnum(entrada[i])) {  // Verifica si el carácter es alfanumérico
            salida[j++] = tolower(entrada[i]);  // Convierte a minúscula y lo agrega a la salida
        }
    }
    salida[j] = '\0';   // Agrega el terminador nulo al final de la cadena de salida
    // Elimina espacios y convierte a minúsculas
}

// Función para verificar si una cadena es un palíndromo
int esPalindromo(const char *cadena) {  // Verifica si la cadena es un palíndromo
    int inicio = 0, fin = strlen(cadena) - 1;   // Inicializa los índices de inicio y fin
    while (inicio < fin) {  // Mientras no se crucen los índices
        if (cadena[inicio] != cadena[fin]) {    // Si los caracteres no son iguales
            return 0;
        }
        inicio++;   // Avanza el índice de inicio
        fin--;  // Retrocede el índice de fin
    }
    return 1;   // Retorna 1 si es palíndromo, 0 si no lo es
}

int main() {    // Función principal
    int n;  // Variable para almacenar la cantidad de frases
    printf("Ingrese la cantidad de frases: ");      // Solicita la cantidad de frases
    scanf("%d", &n);    // Lee la cantidad de frases
    getchar(); // Limpiar el buffer de entrada

    char **frases = (char **)malloc(n * sizeof(char *));    // Reserva memoria para las frases
    // Verifica si la memoria fue asignada correctamente
    if (frases == NULL) {   // Manejo de error
        printf("Error al asignar memoria.\n");  // Si no se puede asignar memoria, muestra un mensaje de error
        return 1;
    }

    for (int i = 0; i < n; i++) {   // Recorre cada frase
        frases[i] = (char *)malloc(MAX_CADENA * sizeof(char));  // Reserva memoria para cada frase
        if (frases[i] == NULL) {    // Manejo de error
            for (int j = 0; j < i; j++) {   // Libera la memoria asignada hasta ahora
                free(frases[j]);
            }
            printf("Error al asignar memoria.\n");  // Si no se puede asignar memoria, muestra un mensaje de error
            return 1;
        }
        printf("Ingrese la frase %d: ", i + 1); // Solicita la frase
        fgets(frases[i], MAX_CADENA, stdin);    // Lee la frase
        // Verifica si la frase fue leída correctamente
        frases[i][strcspn(frases[i], "\n")] = '\0'; // Eliminar el salto de línea
    }

    printf("\nResultados:\n");  // Muestra los resultados
    for (int i = 0; i < n; i++) {   // Recorre cada frase
        char cadenaLimpia[MAX_CADENA];  // Variable para almacenar la cadena limpia
        limpiarCadena(frases[i], cadenaLimpia); // Limpia la cadena
        if (esPalindromo(cadenaLimpia)) {   // Verifica si es un palíndromo
            printf("La frase \"%s\" es un palíndromo.\n", frases[i]);   // Muestra que es un palíndromo
        } else {    // Si no es un palíndromo
            printf("La frase \"%s\" no es un palíndromo.\n", frases[i]);    // Muestra que no es un palíndromo
        }   
    }

    for (int i = 0; i < n; i++) {   // Libera la memoria asignada a cada frase
        free(frases[i]);    // Libera la memoria de cada frase
    }
    free(frases);   // Libera la memoria del arreglo de frases  

    return 0;
}