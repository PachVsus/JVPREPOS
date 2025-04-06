#include <stdbool.h>
#include <stdio.h>

enum Options {ZERO_BALANCE = 1, CREDIT_BALANCE, DEBIT_BALANCE, END};

// determine whether to display a record
bool shouldDisplay(enum Options option, double balance) {   // checar el saldo
    // check if the balance is zero, credit or debit
    if ((option == ZERO_BALANCE) && (balance == 0)) {   // checar el saldo cero
        return true;    // si el saldo es cero, devuelve verdadero
    }
    if ((option == CREDIT_BALANCE) && (balance < 0)) {  // checar el saldo de credito
        return true;    // si el saldo es negativo, devuelve verdadero
    }
    if ((option == DEBIT_BALANCE) && (balance > 0)) {   // checar el saldo de debito
        return true;    // si el saldo es positivo, devuelve verdadero
    }
    return false;
}

int main(void) {
    FILE *cfPtr = NULL; // apuntador de archivo para clientes.txt
    // fopen abre el archivo; sale del programa si no se puede abrir el archivo

    // fopen abre el archivo; sale del programa si no se puede abrir el archivo
    // "r" significa "lectura"
    if ((cfPtr = fopen("clients.txt", "r")) == NULL) {  // abrir el archivo en modo lectura
        // Si no se puede abrir el archivo, imprime un mensaje de error
        puts("File could not be opened");   // imprimir mensaje de error
    } else {
        // Desplega las opciones de la lista
        printf("%s", "Enter request\n"
            " 1 - List accounts with zero balances\n"
            " 2 - List accounts with credit balances\n"
            " 3 - List accounts with debit balances\n"
            " 4 - End of run\n? ");

        int request = 0;    
        scanf("%d", &request);
        // display records
        while (request != END) {
            switch (request) {
                case ZERO_BALANCE:
                    puts("\nAccounts with zero balances:");
                    break;
                case CREDIT_BALANCE:
                    puts("\nAccounts with credit balances:");
                    break;
                case DEBIT_BALANCE:
                    puts("\nAccounts with debit balances:");
                    break;
            }
            int account = 0;
            char name[30] = "";
            double balance = 0.0;

            // read account, name and balance from file
            fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);

            // read file contents (until eof)
            while (!feof(cfPtr)) {
                // output only if balance is 0
                if (shouldDisplay(request, balance)) {
                    printf("%-10d%-13s%7.2f\n", account, name, balance);
                }
                // read account, name and balance from file
                fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);
            }
            rewind(cfPtr); // return cfPtr to beginning of file
            printf("%s", "\n? ");
            scanf("%d", &request);
        }
        puts("End of run.");
        fclose(cfPtr); // close the file
    }
}
 