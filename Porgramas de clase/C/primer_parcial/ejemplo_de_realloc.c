#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int *)malloc(5 * sizeof(int)); // Allocate memory for 5 integers
    if (arr == NULL) {  // Check if memory allocation was successful
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize array
    for (int i = 0; i < 5; i++)     // Se inicializa el arreglo
        arr[i] = i + 1;

    // Resize memory block
    int *temp = (int *)realloc(arr, 10 * sizeof(int));  // Reallocate memory for 10 integers
    if (temp == NULL) { // Check if memory reallocation was successful
        printf("Memory reallocation failed\n");
        free(arr);  // Free allocated memory
        return 1;
    }
    
    arr = temp; // Assign new pointer

    // Initialize new elements
    for (int i = 5; i < 10; i++)
        arr[i] = i + 1;

    // Print array
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    free(arr); // Free allocated memory
    return 0;
}

// Tips para implementar realloc en examenes a mano:
// 1. Siempre se debe de verificar si la memoria fue asignada correctamente, si no se asigno correctamente se debe de liberar la memoria
// 2. Siempre se debe de verificar si la memoria fue realocada correctamente, si no se realoco correctamente se debe de liberar la memoria
// 3. Siempre se debe de liberar la memoria al final del programa
// 4. Siempre se debe de asignar el nuevo apuntador al apuntador original
// 5. Siempre se debe de asignar el nuevo apuntador al apuntador original despues de verificar si la memoria fue realocada correctamente
// 6. Siempre se debe de liberar la memoria al final del programa despues de asignar el nuevo apuntador al apuntador original
// 7. Siempre se debe de liberar la memoria al final del programa despues de verificar si la memoria fue realocada correctamente
// 8. Siempre se debe de liberar la memoria al final del programa despues de verificar si la memoria fue asignada correctamente
// 9. Siempre se debe de liberar la memoria al final del programa despues de verificar si la memoria fue asignada correctamente y despues de verificar si la memoria fue realocada correctamente
// 10. Siempre se debe de liberar la memoria al final del programa despues de verificar si la memoria fue asignada correctamente y despues de verificar si la memoria fue realocada correctamente y despues de asignar el nuevo apuntador al apuntador original