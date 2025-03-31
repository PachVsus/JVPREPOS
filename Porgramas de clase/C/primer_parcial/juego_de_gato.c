#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILAS 3
#define COLUMNAS 3

void inicializarTablero(char tablero[FILAS][COLUMNAS]);
void imprimirTablero(char tablero[FILAS][COLUMNAS]);
int verificarGanador(char tablero[FILAS][COLUMNAS], char jugador);
int verificarEmpate(char tablero[FILAS][COLUMNAS]);
int verificarMovimiento(char tablero[FILAS][COLUMNAS], int fila, int columna);
void realizarMovimiento(char tablero[FILAS][COLUMNAS], int fila, int columna, char jugador);


int main() {
    char tablero[FILAS][COLUMNAS];
    char jugador = 'X';
    int fila, columna;
    int ganador = 0;
    int empate = 0;

    srand(time(NULL));

    inicializarTablero(tablero);
    imprimirTablero(tablero);

    while (1) {
        printf("Turno del jugador %c\n", jugador);
        printf("Ingrese la fila (0-2): ");
        scanf("%d", &fila);
        printf("Ingrese la columna (0-2): ");
        scanf("%d", &columna);

        if (verificarMovimiento(tablero, fila, columna)) {
            realizarMovimiento(tablero, fila, columna, jugador);
            imprimirTablero(tablero);

            ganador = verificarGanador(tablero, jugador);
            if (ganador) {
                printf("El jugador %c ha ganado!\n", jugador);
                break;
            }

            empate = verificarEmpate(tablero);
            if (empate) {
                printf("Empate!\n");
                break;
            }

            jugador = (jugador == 'X') ? 'O' : 'X';
        } else {
            printf("Movimiento inválido. Intente de nuevo.\n");
        }
    }

    return 0;
}

void inicializarTablero(char tablero[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = ' ';
        }
    }
}

void imprimirTablero(char tablero[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%c", tablero[i][j]);
            if (j < COLUMNAS - 1) printf("|");
        }
        printf("\n");
        if (i < FILAS - 1) printf("-----\n");
    }
}

int verificarGanador(char tablero[FILAS][COLUMNAS], char jugador) {
    for (int i = 0; i < FILAS; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) return 1;
    }
    for (int j = 0; j < COLUMNAS; j++) {
        if (tablero[0][j] == jugador && tablero[1][j] == jugador && tablero[2][j] == jugador) return 1;
    }
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) return 1;
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) return 1;
    return 0;
}

int verificarEmpate(char tablero[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (tablero[i][j] == ' ') return 0;
        }
    }
    return 1;
}

int verificarMovimiento(char tablero[FILAS][COLUMNAS], int fila, int columna) {
    if (fila < 0 || fila >= FILAS || columna < 0 || columna >= COLUMNAS) return 0;
    if (tablero[fila][columna] != ' ') return 0;
    return 1;
}

void realizarMovimiento(char tablero[FILAS][COLUMNAS], int fila, int columna, char jugador) {
    tablero[fila][columna] = jugador;
}
