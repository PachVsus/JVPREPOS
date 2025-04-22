#include <stdio.h>
#include <string.h>

// clientData structure definition
struct clientData {
    int account;
    char lastName[15];
    char firstName[10];
    char email[30];
    char phoneNumber[15];
    char accountType[10]; // "savings" or "checking"
    double balance;
    double transactionHistory[5]; // Store last 5 transactions
};

// prototypes
int enterChoice(void);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);
void viewTransactionHistory(FILE *fPtr);
void transferFunds(FILE *fPtr);
void applyInterest(FILE *fPtr);

int main(void) {
    FILE *cfPtr = NULL; // accounts.dat file pointer
    if ((cfPtr = fopen("accounts.dat", "rb+")) == NULL) {
        puts("File could not be opened.");
    } else {
        int choice = 0;
        while ((choice = enterChoice()) != 7) {
            switch (choice) {
                case 1:
                    textFile(cfPtr);
                    break;
                case 2:
                    updateRecord(cfPtr);
                    break;
                case 3:
                    newRecord(cfPtr);
                    break;
                case 4:
                    deleteRecord(cfPtr);
                    break;
                case 5:
                    viewTransactionHistory(cfPtr);
                    break;
                case 6:
                    transferFunds(cfPtr);
                    break;
                case 7:
                    applyInterest(cfPtr);
                    break;
                default:
                    puts("Incorrect choice");
                    break;
            }
        }
        fclose(cfPtr);
    }
}

// Add new functions below

// View transaction history
void viewTransactionHistory(FILE *fPtr) {
    int account = 0;
    printf("Enter account number to view transaction history (1 - 100): ");
    scanf("%d", &account);

    fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
    struct clientData client = {0, "", "", "", "", "", 0.0, {0}};
    fread(&client, sizeof(struct clientData), 1, fPtr);

    if (client.account == 0) {
        printf("Account #%d does not exist.\n", account);
    } else {
        printf("Transaction history for account #%d:\n", account);
        for (int i = 0; i < 5; ++i) {
            if (client.transactionHistory[i] != 0) {
                printf("Transaction %d: %.2f\n", i + 1, client.transactionHistory[i]);
            }
        }
    }
}

// Transfer funds between accounts
void transferFunds(FILE *fPtr) {
    int fromAccount = 0, toAccount = 0;
    double amount = 0.0;

    printf("Enter source account number (1 - 100): ");
    scanf("%d", &fromAccount);
    printf("Enter destination account number (1 - 100): ");
    scanf("%d", &toAccount);
    printf("Enter amount to transfer: ");
    scanf("%lf", &amount);

    struct clientData fromClient = {0, "", "", "", "", "", 0.0, {0}};
    struct clientData toClient = {0, "", "", "", "", "", 0.0, {0}};

    fseek(fPtr, (fromAccount - 1) * sizeof(struct clientData), SEEK_SET);
    fread(&fromClient, sizeof(struct clientData), 1, fPtr);

    fseek(fPtr, (toAccount - 1) * sizeof(struct clientData), SEEK_SET);
    fread(&toClient, sizeof(struct clientData), 1, fPtr);

    if (fromClient.account == 0 || toClient.account == 0) {
        puts("One or both accounts do not exist.");
    } else if (fromClient.balance < amount) {
        puts("Insufficient funds in source account.");
    } else {
        fromClient.balance -= amount;
        toClient.balance += amount;

        // Update transaction history
        memmove(&fromClient.transactionHistory[1], &fromClient.transactionHistory[0], 4 * sizeof(double));
        fromClient.transactionHistory[0] = -amount;

        memmove(&toClient.transactionHistory[1], &toClient.transactionHistory[0], 4 * sizeof(double));
        toClient.transactionHistory[0] = amount;

        fseek(fPtr, (fromAccount - 1) * sizeof(struct clientData), SEEK_SET);
        fwrite(&fromClient, sizeof(struct clientData), 1, fPtr);

        fseek(fPtr, (toAccount - 1) * sizeof(struct clientData), SEEK_SET);
        fwrite(&toClient, sizeof(struct clientData), 1, fPtr);

        puts("Transfer completed successfully.");
    }
}

// Apply interest to savings accounts
void applyInterest(FILE *fPtr) {
    rewind(fPtr);
    struct clientData client = {0, "", "", "", "", "", 0.0, {0}};

    while (fread(&client, sizeof(struct clientData), 1, fPtr)) {
        if (strcmp(client.accountType, "savings") == 0 && client.account != 0) {
            client.balance *= 1.02; // Apply 2% interest
            fseek(fPtr, -sizeof(struct clientData), SEEK_CUR);
            fwrite(&client, sizeof(struct clientData), 1, fPtr);
        }
    }
    puts("Interest applied to all savings accounts.");
}

// Modify `newRecord` to include new fields
void newRecord(FILE *fPtr) {
    printf("Enter new account number (1 - 100): ");
    int account = 0;
    scanf("%d", &account);

    fseek(fPtr, (account - 1) * sizeof(struct clientData), SEEK_SET);
    struct clientData client = {0, "", "", "", "", "", 0.0, {0}};
    fread(&client, sizeof(struct clientData), 1, fPtr);

    if (client.account != 0) {
        printf("Account #%d already contains information.\n", client.account);
    } else {
        printf("Enter lastname, firstname, email, phone number, account type (savings/checking), balance\n? ");
        scanf("%14s%9s%29s%14s%9s%lf", client.lastName, client.firstName, client.email, client.phoneNumber, client.accountType, &client.balance);

        client.account = account;

        fseek(fPtr, (client.account - 1) * sizeof(struct clientData), SEEK_SET);
        fwrite(&client, sizeof(struct clientData), 1, fPtr);
    }
}

// Update `enterChoice` to include new options
int enterChoice(void) {
    int menuChoice = 0;
    printf("\nEnter your choice\n"
           "1 - store a formatted text file of accounts called \"accounts.txt\" for printing\n"
           "2 - update an account\n"
           "3 - add a new account\n"
           "4 - delete an account\n"
           "5 - view transaction history\n"
           "6 - transfer funds between accounts\n"
           "7 - apply interest to savings accounts\n"
           "8 - end program\n? ");
    scanf("%d", &menuChoice);
    return menuChoice;
}