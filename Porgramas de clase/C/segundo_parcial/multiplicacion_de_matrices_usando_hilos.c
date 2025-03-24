#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Definir la estructura sin typedef:
struct thread_data {
    int rowA;
    int colA_rowB;
    int colB;
    double **A;
    double **B;
    double **C;
};

// Función que realiza la multiplicación de una fila de la matriz A por la matriz B
void* multiply_row(void* arg) {
    struct thread_data* data = (struct thread_data*) arg;
    for (int j = 0; j < data->colB; j++) {
        double sum = 0.0;
        for (int k = 0; k < data->colA_rowB; k++) {
            sum += data->A[data->rowA][k] * data->B[k][j];
        }
        data->C[data->rowA][j] = sum;
    }

    // Imprimir mensaje de finalización del hilo
    printf("Thread launched for rowA %d -> Completed\n", data->rowA);
    pthread_exit(NULL);
}

// Funcion para alocar memoria para una matriz
double** allocate_matrix(int rows, int cols) {
    double** matrix = (double**)malloc(rows * sizeof(double*));
    if (matrix) {
        for (int i = 0; i < rows; i++) {
            matrix[i] = (double*)malloc(cols * sizeof(double));
        }
    } else {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return matrix;
}

// Funcion para liberar memoria de una matriz
void free_matrix(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Función para ingresar y mostrar cada elemento de la matriz uno por uno
void input_and_display_matrix(double** matrix, int rows, int cols) {
    printf("Enter elements for matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
    printf("Matrix (%d x %d) is:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function para mostrar una matriz
void display_matrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rowA, colA, rowB, colB;

    printf("Enter the number of rows for matrix A: ");
    scanf("%d", &rowA);
    printf("Enter the number of columns for matrix A: ");
    scanf("%d", &colA);
    printf("Enter the number of rows for matrix B: ");
    scanf("%d", &rowB);
    printf("Enter the number of columns for matrix B: ");
    scanf("%d", &colB);

    if (colA != rowB) {
        printf("Matrices are not conformable for multiplication.\n");
        return 1;
    }

    double** A = allocate_matrix(rowA, colA);
    double** B = allocate_matrix(rowB, colB);
    double** C = allocate_matrix(rowA, colB);

    input_and_display_matrix(A, rowA, colA);
    input_and_display_matrix(B, rowB, colB);

    pthread_t threads[rowA];
    struct thread_data data[rowA];

    for (int i = 0; i < rowA; i++) {
        data[i].rowA = i;
        data[i].colA_rowB = colA;
        data[i].colB = colB;
        data[i].A = A;
        data[i].B = B;
        data[i].C = C;

        printf("Launching thread for row %d\n", i);
        pthread_create(&threads[i], NULL, multiply_row, (void*)&data[i]);
    }

    for (int i = 0; i < rowA; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Resultant matrix C:\n");
    display_matrix(C, rowA, colB);

    free_matrix(A, rowA);
    free_matrix(B, rowB);
    free_matrix(C, rowA);

    return 0;
}