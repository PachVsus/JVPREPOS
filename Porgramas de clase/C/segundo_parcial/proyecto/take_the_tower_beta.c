#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4  // Tamaño del tablero
#define BOARDS 4  // Número de tableros
#define EMPTY ' '  // Espacio vacío en el tablero

// Estructura que representa a un jugador
typedef struct {
    char name[50];            // Nombre del jugador
    char symbol;              // Símbolo asignado (O o X)
    int rotations_left;       // Boletos de rotación disponibles
    int marbles_left;         // Canicas restantes
} Player;

// Estructura que representa un tablero 4x4
typedef struct {
    char cells[SIZE][SIZE];   // Matriz del tablero
} Board;

// Prototipos de funciones
void initialize_boards(Board* tower[]);  // Inicializa los tableros
void display_tower(Board* tower[]);      // Muestra los tableros
void initialize_players(Player* p1, Player* p2);  // Inicializa jugadores
int place_marble(Board* tower[], Player* player, int board_index, int row, int col);  // Coloca una canica
int rotate_board(Board* tower[], int board_index, int direction, Player* player);     // Rota un tablero
int check_win_single_board(Board* board, char symbol); // Verifica victoria en tablero individual
int is_rotation_valid(Board* tower[], int board_index, int direction, char symbol1, char symbol2);  // Verifica si una rotación causaría victoria
void game_loop(Board* tower[], Player* p1, Player* p2); // Lógica principal de turnos
void reset_game(Board* tower[], Player* p1, Player* p2); // Reinicia el juego

int main() {
    Board* tower[BOARDS];  // Arreglo de punteros a tableros
    Player p1, p2;          // Jugadores

    initialize_boards(tower);  // Reservar memoria e inicializar tableros
    printf("Bienvenido a 'Take the Tower'!\n");
    initialize_players(&p1, &p2);  // Configurar jugadores
    system("cls");  // Limpia la pantalla
    game_loop(tower, &p1, &p2);  // Ejecutar el juego principal

    for (int i = 0; i < BOARDS; i++) {
        free(tower[i]);  // Liberar memoria de cada tablero
    }
    return 0;
}

void initialize_boards(Board* tower[]) {
    for (int b = 0; b < BOARDS; b++) {
        tower[b] = (Board*)malloc(sizeof(Board));  // Reserva memoria
        if (tower[b] == NULL) {
            fprintf(stderr, "Error al reservar memoria para el tablero %d\n", b);
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                tower[b]->cells[i][j] = EMPTY;  // Inicializar cada celda vacía
    }
}

void display_tower(Board* tower[]) {    // Muestra el estado de los tableros
    for (int b = 0; b < BOARDS; b++) {  // Recorre cada tablero
        printf("\nTablero %d:\n", b);   // Muestra el índice del tablero
        for (int i = 0; i < SIZE; i++) {    // Recorre cada fila
            printf(" | ");  // Espacio inicial
            for (int j = 0; j < SIZE; j++) {    // Recorre cada columna
                printf(" %c ", tower[b]->cells[i][j]);  // Muestra el símbolo de la celda
            }
            printf("\n");   
        }
    }
}

void initialize_players(Player* p1, Player* p2) {   // Inicializa los jugadores
    printf("Jugador 1, introduce tu nombre: "); // Solicita el nombre del jugador 1
    fgets(p1->name, sizeof(p1->name), stdin);   // Lee el nombre
    p1->name[strcspn(p1->name, "\n")] = 0;  // Elimina el salto de línea
    p1->symbol = 'O';   // Asigna el símbolo 'O' al jugador 1
    p1->rotations_left = 4; // Asigna 4 boletos de rotación
    p1->marbles_left = 32;  // Asigna 32 canicas

    printf("Jugador 2, introduce tu nombre: "); // Solicita el nombre del jugador 2
    fgets(p2->name, sizeof(p2->name), stdin);   // Lee el nombre
    p2->name[strcspn(p2->name, "\n")] = 0;  // Elimina el salto de línea
    p2->symbol = 'X';   // Asigna el símbolo 'X' al jugador 2
    p2->rotations_left = 4; // Asigna 4 boletos de rotación
    p2->marbles_left = 32;  // Asigna 32 canicas
}

int place_marble(Board* tower[], Player* player, int board_index, int row, int col) {   // Coloca una canica en el tablero
    if (board_index < 0 || board_index >= BOARDS || row < 0 || row >= SIZE || col < 0 || col >= SIZE)   // Verifica límites
        return 0;
    if (tower[board_index]->cells[row][col] != EMPTY || player->marbles_left <= 0)  // Verifica si la celda está ocupada o si no hay canicas
        return 0;
    tower[board_index]->cells[row][col] = player->symbol;   // Coloca la canica
    player->marbles_left--; // Disminuye el número de canicas restantes
    return 1;
}

int rotate_board(Board* tower[], int board_index, int direction, Player* player) {  // Rota un tablero
    if (board_index < 0 || board_index >= BOARDS || player->rotations_left <= 0)    // Verifica límites y boletos
        return 0;
    if (!is_rotation_valid(tower, board_index, direction, 'O', 'X'))    // Verifica si la rotación causaría victoria
        return 0;

    Board* b = tower[board_index];  // Obtiene el tablero a rotar
    char temp[SIZE][SIZE];  // Matriz temporal para almacenar el tablero original
    for (int i = 0; i < SIZE; i++)      // Copia el tablero original a la matriz temporal
        for (int j = 0; j < SIZE; j++)
            temp[i][j] = b->cells[i][j];    // Copia cada celda

    if (direction == 1) {     // Rotación anti-horaria
        for (int i = 0; i < SIZE; i++)  // Recorre cada fila
            for (int j = 0; j < SIZE; j++)     // Recorre cada fila y columna
                b->cells[i][j] = temp[j][SIZE - 1 - i]; // Rotación anti-horaria
    } else if (direction == -1) {   // Rotación horaria
        for (int i = 0; i < SIZE; i++)  // Recorre cada fila
            for (int j = 0; j < SIZE; j++)      // Recorre cada columna
                b->cells[i][j] = temp[SIZE - 1 - j][i]; // Rotación horaria
    } else return 0;    // Dirección inválida

    player->rotations_left--;   // Disminuye el número de boletos restantes
    return 1;   // Retorna 1 si la rotación fue exitosa
}

int check_win_single_board(Board* board, char symbol) { // Verifica si hay victoria en un tablero individual
    for (int i = 0; i < SIZE; i++) {
        int row = 0, col = 0;   // Contadores para filas y columnas
        for (int j = 0; j < SIZE; j++) {
            if (board->cells[i][j] == symbol) row++;    // Verifica filas
            if (board->cells[j][i] == symbol) col++;    // Verifica columnas
        }
        if (row == 4 || col == 4) return 1;   // Retorna 1 si hay victoria
    }
    int d1 = 0, d2 = 0; // Contadores para diagonales
    for (int i = 0; i < SIZE; i++) {    // Recorre cada celda
        if (board->cells[i][i] == symbol) d1++;   // Verifica diagonal principal
        if (board->cells[i][SIZE - 1 - i] == symbol) d2++;  // Verifica diagonal secundaria
    }
    return (d1 == 4 || d2 == 4);    // Retorna 1 si hay victoria
}

int is_rotation_valid(Board* tower[], int board_index, int direction, char symbol1, char symbol2) { // Verifica si la rotación causaría victoria
    if (board_index < 0 || board_index >= BOARDS) return 0; // Verifica límites

    Board temp; // Tablero temporal para verificar la rotación
    for (int i = 0; i < SIZE; i++)  // Copia el tablero original a la matriz temporal
        for (int j = 0; j < SIZE; j++)  // Copia cada celda
            temp.cells[i][j] = tower[board_index]->cells[i][j]; // Copia cada celda

    char rotated[SIZE][SIZE];   // Matriz para almacenar el tablero rotado
    if (direction == 1) {   // Rotación anti-horaria
        for (int i = 0; i < SIZE; i++)  // Recorre cada fila
            for (int j = 0; j < SIZE; j++)  // Recorre cada columna
                rotated[i][j] = temp.cells[j][SIZE - 1 - i];    // Rota el tablero
    } else if (direction == -1) {   // Rotación horaria
        for (int i = 0; i < SIZE; i++)  // Recorre cada fila
            for (int j = 0; j < SIZE; j++)  // Recorre cada columna
                rotated[i][j] = temp.cells[SIZE - 1 - j][i];    // Rota el tablero
    } else return 0;    // Dirección inválida

    for (int i = 0; i < SIZE; i++)  // Copia el tablero rotado a la matriz temporal
        for (int j = 0; j < SIZE; j++)  // Copia cada celda
            temp.cells[i][j] = rotated[i][j];   // Copia cada celda

    return !(check_win_single_board(&temp, symbol1) || check_win_single_board(&temp, symbol2)); // Verifica si la rotación causaría victoria
}

void reset_game(Board* tower[], Player* p1, Player* p2) {   // Reinicia el juego
    for (int b = 0; b < BOARDS; b++)    // Recorre cada tablero
        for (int i = 0; i < SIZE; i++)  // Recorre cada fila
            for (int j = 0; j < SIZE; j++)  // Recorre cada columna
                tower[b]->cells[i][j] = EMPTY;  // Reinicia cada celda a vacía
    printf("\n=== Reiniciando el juego ===\n");  // Mensaje de reinicio

    int opcion;
    printf("\n¿Quién usará las canicas blancas (O)?\n1. %s\n2. %s\nOpcion: ", p1->name, p2->name);  // Pregunta quién usará las canicas blancas
    scanf("%d", &opcion); getchar();    // Espacio antes de %d para ignorar espacios en blanco
    if (opcion == 1) {  // Si elige el jugador 1
        p1->symbol = 'O'; p2->symbol = 'X'; // Asigna el símbolo 'O' al jugador 1 y 'X' al jugador 2
    } else {    
        p1->symbol = 'X'; p2->symbol = 'O'; // Asigna el símbolo 'X' al jugador 1 y 'O' al jugador 2
    }

    p1->marbles_left = 32;  // Reinicia las canicas restantes del jugador 1
    p2->marbles_left = 32;  // Reinicia las canicas restantes del jugador 2
    p1->rotations_left = 4; // Reinicia los boletos de rotación del jugador 1
    p2->rotations_left = 4; // Reinicia los boletos de rotación del jugador 2
    printf("\n¡El juego ha sido reiniciado!\n");  // Mensaje de reinicio
    system("cls");    // Limpia la pantalla
}

void game_loop(Board* tower[], Player* p1, Player* p2) {    // Lógica principal del juego
    Player* current = p1;   // Jugador actual
    Player* other = p2; // Jugador contrario
    int turno = 1;  // Contador de turnos

    while (1) {
        printf("\n=== Turno %d ===\n", turno);  // Muestra el turno actual
        printf("%s (%c) | Canicas: %d | Boletos: %d\n", current->name, current->symbol, current->marbles_left, current->rotations_left);    // Muestra el estado del jugador actual
        display_tower(tower);   // Muestra el estado del tablero

        int choice;
        printf("\n1. Colocar canica\n2. Rotar tablero\nOpcion: ");  // Solicita la opción
        scanf("%d", &choice); getchar();    // Espacio antes de %d para ignorar espacios en blanco

        if (choice == 1) {  // Opción para colocar una canica
            int board, row, col;    // Solicita el índice del tablero, fila y columna
            printf("Tablero (0-3): "); scanf("%d", &board); getchar();  // Solicita el índice del tablero
            printf("Fila (0-3): "); scanf("%d", &row); getchar();   // Solicita la fila
            printf("Columna (0-3): "); scanf("%d", &col); getchar();    // Solicita la fila y columna

            if (place_marble(tower, current, board, row, col)) {    // Coloca la canica
                if (check_win_single_board(tower[board], current->symbol)) {    // Verifica si hay victoria
                    display_tower(tower);   // Muestra el estado del tablero
                    printf("\n¡%s ha ganado!\n", current->name);    // Mensaje de victoria
                    break;
                }
                if (p1->marbles_left == 0 && p2->marbles_left == 0) {   // Verifica si ambos jugadores se quedan sin canicas
                    printf("\nEmpate: no quedan canicas.\n");   // Manejo de empate
                    break;
                }
                Player* temp = current; current = other; other = temp; turno++; // Cambia de turno
            } else {
                printf("Jugada inválida.\n");   // Manejo de jugada inválida
            }

        } else if (choice == 2) {   // Opción para rotar un tablero
            int board, dir; // Solicita el índice del tablero y la dirección de rotación
            printf("Tablero (0-3): "); scanf("%d", &board); getchar(); // Solicita el índice del tablero
            printf("Dirección (1 = anti-horaria, -1 = horaria): "); scanf("%d", &dir); getchar();   // Solicita dirección de rotación

            if (rotate_board(tower, board, dir, current)) { // Rota el tablero
                printf("Tablero %d rotado con éxito.\n", board);    // Mensaje de éxito
                Player* temp = current; current = other; other = temp; turno++; // Cambia de turno
            } else {
                printf("Rotación inválida: podría causar victoria o no tienes boletos.\n"); // Manejo de rotación inválida
            }
        } else {    
            printf("Opción no válida.\n");  // Manejo de opción inválida
        }
    }

    char respuesta;
    printf("\n¿Deseas jugar otra partida? (s/n): ");    // Pregunta si desea jugar de nuevo
    // Se usa "getchar()" para limpiar el buffer de entrada antes de leer la respuesta
    scanf(" %c", &respuesta); getchar();    // Espacio antes de %c para ignorar espacios en blanco
    if (respuesta == 's' || respuesta == 'S') { 
        reset_game(tower, p1, p2);  // Reinicia el juego
        game_loop(tower, p1, p2);   // Llama a la función de juego nuevamente
    }
}
