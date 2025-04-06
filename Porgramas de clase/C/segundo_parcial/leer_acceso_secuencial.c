#include <stdio.h>

int main(void) {
    FILE *cfPtr = NULL; // Declarar puntero de archivo para clientes.txt
    // fopen abre el archivo; sale del programa si no se puede abrir el archivo
    if ((cfPtr = fopen("clientes.txt", "r")) == NULL) { // "r" significa "lectura"
        // Si no se puede abrir el archivo, imprime un mensaje de error
        puts("File could not be opened");
    }
    else { // lee el archivo si se abre correctamente
        puts("Contents of clientes.txt are:"); // puts significa "imprimir cadena"
        // lee el archivo y muestra su contenido
        int account = 0; // numero de cuenta
        // Se declara un arreglo de caracteres para el nombre y se inicializa en vacío
        char name[30] = ""; // nombre de cuenta
        // Se declara una variable de tipo double para el saldo y se inicializa en 0.0
        double balance = 0.0; // saldo de cuenta
        // Se imprime el encabezado de la tabla
        printf("%-10s%-13s%s\n", "Account", "Name", "Balance"); // %s significa "cadena de caracteres"
        // Se imprime el encabezado de la tabla
        fscanf(cfPtr, "%d%29s%lf", &account, name, &balance); // fscanf lee el archivo

        // lee el archivo hasta el final
        // y muestra el contenido en formato tabular
        while (!feof(cfPtr)) {
            printf("%-10d%-13s%7.2f\n", account, name, balance);
            fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);
        }
        fclose(cfPtr); // cierra el archivo
    }
}