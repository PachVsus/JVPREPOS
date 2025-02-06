#include <iostream>
#include <ncurses.h>

void show_option(const std::string &option);
void show_main_menu();

void show_option(const std::string &option) {
    clear();
    mvprintw(5, 10, "You selected %s", option.c_str());
    refresh();
    getch();
    show_main_menu();
}

void show_main_menu() {
    int choice;
    initscr();
    clear();
    noecho();
    cbreak();

    WINDOW *menuwin = newwin(10, 40, 4, 4);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    keypad(menuwin, true);

    std::string choices[] = {"Option 1", "Option 2", "Option 3", "Exit"};
    int highlight = 0;

    while (true) {
        for (int i = 0; i < 4; ++i) {
            if (i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i + 1, 1, choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch (choice) {
            case KEY_UP:
                highlight = (highlight == 0) ? 3 : highlight - 1;
                break;
            case KEY_DOWN:
                highlight = (highlight == 3) ? 0 : highlight + 1;
                break;
            default:
                break;
        }
        if (choice == 10) { // Enter key
            if (highlight == 3) {
                endwin();
                exit(0);
            } else {
                show_option(choices[highlight]);
            }
        }
    }
}

int main() {
    show_main_menu();
    return 0;
}
