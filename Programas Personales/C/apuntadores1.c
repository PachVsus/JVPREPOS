#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

// Enum for Career options
typedef enum {
    PHYSICS,
    MATHEMATICS,
    COMPUTER_ENGINEERING,
    ELECTRONICS_ENGINEERING,
    MECHANICAL_ENGINEERING
} Career;

// Struct to store student data
typedef struct {
    int id;
    char name[32];
    char lastName[32];
    int age;
    int semester;
    Career career;
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
void displayStudentInfo(WINDOW *win, Student student, int y, int x) {
    mvwprintw(win, y, x, "Memory location of this student data (1st byte): %p", &student);
    mvwprintw(win, y + 1, x, "At %p => Student ID: %d", &(student.id), student.id);
    mvwprintw(win, y + 2, x, "At %p and %p => Name: %s %s", &(student.name), &(student.lastName), student.name, student.lastName);
    mvwprintw(win, y + 3, x, "At %p => Age: %d", &(student.age), student.age);
    mvwprintw(win, y + 4, x, "At %p => Semester: %d", &(student.semester), student.semester);
    mvwprintw(win, y + 5, x, "At %p => Career: %s", &(student.career), getCareerName(student.career));
}

// Function to capture career choice
Career getCareerChoice(WINDOW *win, int y, int x) {
    int choice;
    mvwprintw(win, y, x, "Choose Career (Enter the number):");
    mvwprintw(win, y + 1, x, "1. Physics");
    mvwprintw(win, y + 2, x, "2. Mathematics");
    mvwprintw(win, y + 3, x, "3. Computer Engineering");
    mvwprintw(win, y + 4, x, "4. Electronics Engineering");
    mvwprintw(win, y + 5, x, "5. Mechanical Engineering");
    mvwprintw(win, y + 6, x, "Your choice: ");
    wrefresh(win);
    wscanw(win, "%d", &choice);

    switch(choice) {
        case 1: return PHYSICS;
        case 2: return MATHEMATICS;
        case 3: return COMPUTER_ENGINEERING;
        case 4: return ELECTRONICS_ENGINEERING;
        case 5: return MECHANICAL_ENGINEERING;
        default: mvwprintw(win, y + 7, x, "Invalid choice, defaulting to Physics."); wrefresh(win); return PHYSICS;
    }
}

int main(void) {
    int numStudents;
    initscr();
    cbreak();
    noecho();
    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    curs_set(0);

    // Get the number of students from the user
    mvprintw(0, 0, "Enter the number of students: ");
    refresh();
    scanw("%d", &numStudents);

    // Dynamically allocate memory for the students
    Student* students = (Student*)malloc(numStudents * sizeof(Student));

    // Capture details for each student
    for (int i = 0; i < numStudents; i++) {
        clear();
        mvprintw(0, 0, "Enter details for student %d", i + 1);
        mvprintw(1, 0, "First Name: ");
        refresh();
        scanw("%s", students[i].name);
        mvprintw(2, 0, "Last Name: ");
        refresh();
        scanw("%s", students[i].lastName);
        mvprintw(3, 0, "Age: ");
        refresh();
        scanw("%d", &students[i].age);
        mvprintw(4, 0, "Semester: ");
        refresh();
        scanw("%d", &students[i].semester);
        students[i].career = getCareerChoice(stdscr, 5, 0);
    }

    // Display the information of all students
    clear();
    mvprintw(0, 0, "--- Student Information ---");
    for (int i = 0; i < numStudents; i++) {
        displayStudentInfo(stdscr, students[i], i * 7 + 1, 0);
    }
    refresh();
    getch();

    // Free the allocated memory
    free(students);
    endwin();
    return 0;
}
