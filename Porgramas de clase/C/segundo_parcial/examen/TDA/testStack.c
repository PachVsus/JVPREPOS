// Nombre: Jesus Vargas Pacheco

#include <stdio.h>
#include "charStack.h"

int main() {
    Stack stack;
    initStack(&stack, 2); // Capacidad inicial de 2

    // Insertar elementos
    push(&stack, 'A');
    push(&stack, 'B');
    push(&stack, 'C'); // Provocará crecimiento

    printf("Contenido de la pila: ");
    printStack(&stack);

    printf("Elemento en el tope: %c\n", peek(&stack));
    printf("Cantidad de elementos: %d\n", size(&stack));

    // Remover elemento
    pop(&stack);
    printf("Después del pop: ");
    printStack(&stack);

    // Verificar si la pila está vacía
    if (isEmpty(&stack))
        printf("La pila está vacía.\n");
    else
        printf("La pila NO está vacía.\n");

    freeStack(&stack);
    return 0;
}
