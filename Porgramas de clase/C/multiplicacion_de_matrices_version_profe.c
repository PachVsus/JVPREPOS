#include <stdio.h>
#include <stdlib.h>

void imprimir(float **, int, int, const char *);

int main(void) {
    float **a, **b, **c;
    int N, M, P;

    printf("Este programa multiplica dos matrices.\n");
    printf("Coloca el número de filas N de la matriz A: ");
    scanf("%d", &N);
    printf("Coloca el número de columnas M de la matriz A (que tambien seran las filas N de la matriz B): ");
    scanf("%d", &M);
    printf("Coloca el número de columnas M de la matriz B: ");
    scanf("%d", &P);

    a = (float **)malloc(N * sizeof(float *));
    if (a == NULL) {
        printf("No se pudo reservar memoria.\n");
        return -1;
    }
    for (int i = 0; i < N; i++) {
        a[i] = (float *)malloc(M * sizeof(float));
        if (a[i] == NULL) {
            printf("No se pudo reservar memoria.\n");
            return -2;
        }
    }

    b = (float **)malloc(M * sizeof(float *));
    if (b == NULL) {
        printf("No se pudo reservar memoria.\n");
        return -1;
    }
    for (int i = 0; i < M; i++) {
        b[i] = (float *)malloc(P * sizeof(float));
        if (b[i] == NULL) {
            printf("No se pudo reservar memoria.\n");
            return -2;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("Coloca el valor del elemento a[%d][%d]: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            printf("Coloca el valor del elemento b[%d][%d]: ", i, j);
            scanf("%f", &b[i][j]);
        }
    }

    c = (float **)malloc(N * sizeof(float *));
    if (c == NULL) {
        printf("No se pudo reservar memoria.\n");
        return -1;
    }
    for (int i = 0; i < N; i++) {
        c[i] = (float *)malloc(P * sizeof(float));
        if (c[i] == NULL) {
            printf("No se pudo reservar memoria.\n");
            return -2;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            c[i][j] = 0;
            for (int k = 0; k < M; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("%.2f ", c[i][j]);
        }
        printf("\n");
    }

    imprimir(a, N, M, "Matriz a: \n");
    imprimir(b, M, P, "Matriz b: \n");
    imprimir(c, N, P, "Matriz a * b = c: \n");

    for (int i = 0; i < N; i++) {
        free(a[i]);
    }
    for (int i = 0; i < M; i++) {
        free(b[i]);
    }
    for (int i = 0; i < N; i++) {
        free(c[i]);
    }

    free(a);
    free(b);
    free(c);

    return 0;
}

void imprimir(float **matriz, int filas, int columnas, const char *msj) {
    printf("%s", msj);
    for (int i = 0; i < filas; i++) {
        printf("[ ");
        for (int j = 0; j < columnas; j++) {
            printf("%.4f ", matriz[i][j]);
        }
        printf(" ]\n");
    }
}
