
// Including necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enum for Career options
typedef enum {
    PHYSICS,                  // Represents Physics career
    MATHEMATICS,              // Represents Mathematics career
    COMPUTER_ENGINEERING,     // Represents Computer Engineering career
    ELECTRONICS_ENGINEERING,  // Represents Electronics Engineering career
    MECHANICAL_ENGINEERING    // Represents Mechanical Engineering career
} Career;

// Struct to store student data
// explanation: https://www.geeksforgeeks.org/structures-c/
typedef struct {
    int id;                   // Student ID
    char name[32];            // Student's first name
    char lastName[32];        // Student's last name
    int age;                  // Student's age
    int semester;             // Student's current semester
    Career career;            // Student's career choice
} Student;

// Function to get the string representation of the career
const char* getCareerName(Career career) {
    switch(career) {
        case PHYSICS: return "Physics";
        case MATHEMATICS: return "Mathematics";
        case COMPUTER_ENGINEERING: return "Computer Engineering";
        case ELECTRONICS_ENGINEERING: return "Electronics Engineering";
        case MECHANICAL_ENGINEERING: return "Mechanical Engineering";
        default: return "Unknown";
    }
}

// Function to display student information
void displayStudentInfo(Student student) {
    printf("Memory location of this student data (1st byte): %p\n", &student);
    printf("\nAt %p => Student ID: %d\n", &(student.id), student.id);
    printf("At %p and %p => Name: %s %s\n", &(student.name), &(student.lastName), student.name, student.lastName);
    printf("At %p => Age: %d\n", &(student.age), student.age);
    printf("At %p => Semester: %d\n", &(student.semester), student.semester);
    printf("At %p => Career: %s\n", &(student.career), getCareerName(student.career));
}

// Function to capture career choice
Career getCareerChoice() {
    int choice;
    printf("Choose Career (Enter the number):\n");
    printf("1. Physics\n");
    printf("2. Mathematics\n");
    printf("3. Computer Engineering\n");
    printf("4. Electronics Engineering\n");
    printf("5. Mechanical Engineering\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: return PHYSICS;
        case 2: return MATHEMATICS;
        case 3: return COMPUTER_ENGINEERING;
        case 4: return ELECTRONICS_ENGINEERING;
        case 5: return MECHANICAL_ENGINEERING;
        default: printf("Invalid choice, defaulting to Physics.\n"); return PHYSICS;
    }
}

int main(void) {
    int numStudents;
    // Get the number of students from the user
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    // Dynamically allocate memory for the students
    Student* students = (Student*)malloc(numStudents * sizeof(Student));
    // Capture details for each student
    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter details for student %d\n", i + 1);
        students[i].id = i + 1;  // Assign ID automatically
        printf("First Name: ");
        scanf("%s", students[i].name);
        printf("Last Name: ");
        scanf("%s", students[i].lastName);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Semester: ");
        scanf("%d", &students[i].semester);
        students[i].career = getCareerChoice();
    }
    // Display the information of all students
    printf("\n--- Student Information ---\n");
    for (int i = 0; i < numStudents; i++) {
        //displayStudentInfo(students[i]);
        printf("Memory location of this student data (1st byte): %p\n", &students[i]);
        printf("At %p => Student ID: %d\n", &(students[i].id), students[i].id);
        printf("At %p and %p => Name: %s %s\n", &(students[i].name), &(students[i].lastName), students[i].name, students[i].lastName);
        printf("At %p => Age: %d\n", &(students[i].age), students[i].age);
        printf("At %p => Semester: %d\n", &(students[i].semester), students[i].semester);
        printf("At %p => Career: %s\n", &(students[i].career), getCareerName(students[i].career));
    }
    // Free the allocated memory
    free(students);
    return 0;
}
