#include <stdlib.h> // For system() function
#include <stdio.h>  // For printf and scanf functions

// Function prototypes
int enterChoice(void);

int main(void) {
    // Call the enterChoice function
    int choice = enterChoice();

    // Handle the choice (example: end program)
    if (choice == 5) {
        printf("Program ended.\n");
        return 0;
    }

    // Add further logic here if needed
    return 0;
}

// enable user to input menu choice
int enterChoice(void) {
    int menuChoice = 0; // variable to store user input

    // display available options
    printf("%s", "\nEnter your choice\n"
    "1 - store a formatted text file of accounts called \"accounts.txt\" for printing\n"
    "2 - update an account\n"
    "3 - add a new account\n"
    "4 - delete an account\n"
    "5 - end program\n? ");

    scanf("%d", &menuChoice); // receive choice from user

    // Clear the screen
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // Unix-based systems
    #endif

    // Display the selected option
    printf("You selected option %d\n\n", menuChoice);

    return menuChoice;
}
