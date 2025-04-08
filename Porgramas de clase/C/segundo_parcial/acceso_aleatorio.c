#include <stdio.h>

// clientData structure definition
struct clientData {
    int account;
    char lastName[15];
    char firstName[10];
    double balance;
};

int main(void) {
    FILE *cfPtr = NULL; // accounts.dat file pointer

    // fopen opens the file; exits if file cannot be opened
    if ((cfPtr = fopen("accounts.dat", "wb")) == NULL) {
        puts("File could not be opened.");
    } else {
        // create clientData with default information
        struct clientData blankClient = {0, "", "", 0.0};

        // output 100 blank records to file
        for (int i = 1; i <= 100; ++i) {
            fwrite(&blankClient, sizeof(struct clientData), 1, cfPtr);
        }
        fclose (cfPtr); // fclose closes the file
    }
}
 