/*Take the tower.

Objetivo. Implementar una versión del juego Take the tower (para 2 jugadores únicamente) en modo texto utilizando lenguaje C.

Elementos del juego.

2 jugadores.
Una torre formada por 4 tableros apilados de 4 x 4 posiciones.
Cada tablero que forma parte de la torre puede rotar 90 grados en sentido positivo (anti-horario) o negativo (horario).
32 canicas de color blanco.
32 canicas de color negro.
4 boletos por jugador para rotar alguno de los 4 tableros.
Reglas del juego.

Cada jugador toma un color de canica (o simbolo para el caso de modo texto).
Cada jugador toma un turno en forma alternada para hacer su jugada. Las canicas blancas inician.
Una jugada consiste en alguna de las dos acciones:
Colocar una canica en una de las 64 posiciones que ofrecen los 4 tableros que forman la torre.
O usar un boleto de rotación para rotar 90 grados en algún sentido (positivo o negativo), uno de los 4 tableros que forman la torre. Sólo puede hacer este tipo de jugada 4 veces (una por cada boleto) a lo largo del juego.
Gana el jugador que obtiene 4 canicas de su color en línea, ya sea en forma horizontal, vertical o diagonal sobre alguno de los tableros o a través de ellos.
Nota: un jugador no puede ganar la partida rotando alguno de los 4 tableros que forman la torre
Condiciones de la implantación en lenguaje C.

El programa debe estar diseñado de manera tal que cada tarea específica del juego sea realizada por una función.
Deben usarse apuntadores a apuntadores para modelar los 4 tableros que forman la torre.
Debe distinguirse a cada uno de los dos jugadores ya sea mediante su nombre o algún otro identificador.
Deben emplearse dos símbolos distinguibles que harán las veces de canicas en las jugadas hechas por cada uno de los jugadores.
De algún modo debe representarse el estado actual de los 4 tableros de la torre al inicio del juego y luego de que cada jugador haga su jugada (coloque una canica o rote alguno de los 4 tableros) y complete su turno.
Debe solicitarse a cada jugador, en su turno correspondiente, que coloque una de sus canicas en alguna de las posiciones de los 4 tableros de la torre; o si así lo prefiere el jugador, podrá hacer uso de uno de sus boletos para rotar alguno de los 4 tableros de la torre (la rotación es sólo de 90 grados y puede ser positiva o negativa).
Luego de que un jugador coloque una canica debe verificarse si alguien ha ganado la partida; si es el caso, debe declararse al ganador, terminar el juego y preguntar si se desea iniciar otra partida.
Si el jugador elije una rotación en lugar de colocar una canica, debe verificarse (antes de realizar la rotación): si con la rotación, alguno de los jugadores gana, en cuyo caso dicha rotación no debe llevarse a cabo y debe informarse al jugador que dicha jugada no es posible y solicitársele una nueva: ya sea colocar una canica o una realizar otra rotación.
Cada jugador solo tiene 4 rotaciones a lo largo de una partida.
Si los dos jugadores han agotado sus 32 canicas (simbolos) y nadie ha logrado colocar 4 en línea, se declara un empate y se pregunta si se desea iniciar otra partida.
Iniciar una nueva partida significa: limpiar la pantalla, limpiar el tablero, preguntar que jugador tendrá ahora las canicas blancas, dar a cada jugador 32 nuevas canicas y reiniciar los turnos.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4
#define EMPTY ' '

typedef struct {
    char name[50];
    char symbol;
    int rotations_left;
    int marbles_left;
} Player;

void initialize_tower(char ***tower);
void display_tower(char ***tower);
void free_tower(char ***tower);
void rotate_board(char **board, int direction);
int place_marble(char ***tower, int layer, int row, int col, char symbol);
int check_winner(char ***tower, char symbol);
void reset_game(char ***tower, Player *player1, Player *player2);

int main() {
    char ***tower = (char ***)malloc(SIZE * sizeof(char **));
    Player player1, player2;
    int current_player = 0, game_over = 0;

    initialize_tower(tower);

    printf("Enter name for Player 1 (White): ");
    scanf("%s", player1.name);
    player1.symbol = 'W';
    player1.rotations_left = 4;
    player1.marbles_left = 32;

    printf("Enter name for Player 2 (Black): ");
    scanf("%s", player2.name);
    player2.symbol = 'B';
    player2.rotations_left = 4;
    player2.marbles_left = 32;

    while (!game_over) {
        Player *current = current_player == 0 ? &player1 : &player2;
        display_tower(tower);

        printf("%s's turn (%c). Marbles left: %d, Rotations left: %d\n", 
               current->name, current->symbol, current->marbles_left, current->rotations_left);

        int choice;
        printf("Choose action: 1 to place marble, 2 to rotate board: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int layer, row, col;
            printf("Enter layer (0-3), row (0-3), and column (0-3): ");
            scanf("%d %d %d", &layer, &row, &col);

            if (place_marble(tower, layer, row, col, current->symbol)) {
                current->marbles_left--;
                if (check_winner(tower, current->symbol)) {
                    display_tower(tower);
                    printf("Congratulations %s! You win!\n", current->name);
                    game_over = 1;
                }
            } else {
                printf("Invalid move. Try again.\n");
                continue;
            }
        } else if (choice == 2 && current->rotations_left > 0) {
            int layer, direction;
            printf("Enter layer (0-3) to rotate and direction (1 for positive, -1 for negative): ");
            scanf("%d %d", &layer, &direction);

            rotate_board(tower[layer], direction);
            current->rotations_left--;
        } else {
            printf("Invalid choice or no rotations left. Try again.\n");
            continue;
        }

        if (player1.marbles_left == 0 && player2.marbles_left == 0) {
            printf("It's a draw! No more marbles left.\n");
            game_over = 1;
        }

        current_player = 1 - current_player;
    }

    free_tower(tower);
    return 0;
}

void initialize_tower(char ***tower) {
    for (int i = 0; i < SIZE; i++) {
        tower[i] = (char **)malloc(SIZE * sizeof(char *));
        for (int j = 0; j < SIZE; j++) {
            tower[i][j] = (char *)malloc(SIZE * sizeof(char));
            for (int k = 0; k < SIZE; k++) {
                tower[i][j][k] = EMPTY;
            }
        }
    }
}

void display_tower(char ***tower) {
    for (int i = 0; i < SIZE; i++) {
        printf("Layer %d:\n", i);
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                printf("%c ", tower[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void free_tower(char ***tower) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            free(tower[i][j]);
        }
        free(tower[i]);
    }
    free(tower);
}

void rotate_board(char **board, int direction) {
    char temp[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (direction == 1) {
                temp[j][SIZE - 1 - i] = board[i][j];
            } else {
                temp[SIZE - 1 - j][i] = board[i][j];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = temp[i][j];
        }
    }
}

int place_marble(char ***tower, int layer, int row, int col, char symbol) {
    if (layer < 0 || layer >= SIZE || row < 0 || row >= SIZE || col < 0 || col >= SIZE || tower[layer][row][col] != EMPTY) {
        return 0;
    }
    tower[layer][row][col] = symbol;
    return 1;
}

int check_winner(char ***tower, char symbol) {
    // Check horizontal, vertical, and diagonal lines on each layer
    for (int l = 0; l < SIZE; l++) {
        for (int i = 0; i < SIZE; i++) {
            if ((tower[l][i][0] == symbol && tower[l][i][1] == symbol && tower[l][i][2] == symbol && tower[l][i][3] == symbol) ||
                (tower[l][0][i] == symbol && tower[l][1][i] == symbol && tower[l][2][i] == symbol && tower[l][3][i] == symbol)) {
                return 1;
            }
        }
        if ((tower[l][0][0] == symbol && tower[l][1][1] == symbol && tower[l][2][2] == symbol && tower[l][3][3] == symbol) ||
            (tower[l][0][3] == symbol && tower[l][1][2] == symbol && tower[l][2][1] == symbol && tower[l][3][0] == symbol)) {
            return 1;
        }
    }

    // Check vertical lines across layers
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (tower[0][i][j] == symbol && tower[1][i][j] == symbol && tower[2][i][j] == symbol && tower[3][i][j] == symbol) {
                return 1;
            }
        }
    }

    // Check diagonal lines across layers
    if ((tower[0][0][0] == symbol && tower[1][1][1] == symbol && tower[2][2][2] == symbol && tower[3][3][3] == symbol) ||
        (tower[0][0][3] == symbol && tower[1][1][2] == symbol && tower[2][2][1] == symbol && tower[3][3][0] == symbol) ||
        (tower[0][3][0] == symbol && tower[1][2][1] == symbol && tower[2][1][2] == symbol && tower[3][0][3] == symbol) ||
        (tower[0][0][0] == symbol && tower[1][1][0] == symbol && tower[2][2][0] == symbol && tower[3][3][0] == symbol)) {
        return 1;
    }

    return 0;
}