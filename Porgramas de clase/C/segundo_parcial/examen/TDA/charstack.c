// Nombre: Jesus Vargas Pacheco

#include <stdio.h>
#include <stdlib.h>
#include "charStack.h"

// Inicializa la pila con una capacidad inicial dada
void initStack(Stack *stack, int initialCapacity) {
    stack->data = (char *)malloc(initialCapacity * sizeof(char));
    if (stack->data == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria.\n");
        exit(EXIT_FAILURE);
    }
    stack->top = -1;
    stack->capacity = initialCapacity;
}

// Verifica si la pila está vacía
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Duplica la capacidad del arreglo de la pila
void resizeStack(Stack *stack) {
    int newCapacity = stack->capacity * 2;
    char *newData = (char *)realloc(stack->data, newCapacity * sizeof(char));
    if (newData == NULL) {
        fprintf(stderr, "Error: No se pudo redimensionar la pila.\n");
        exit(EXIT_FAILURE);
    }
    stack->data = newData;
    stack->capacity = newCapacity;
}

// Agrega un carácter al tope de la pila
void push(Stack *stack, char value) {
    if (stack->top == stack->capacity - 1) {
        resizeStack(stack);
    }
    stack->data[++stack->top] = value;
}

// Remueve y devuelve el carácter en el tope de la pila
char pop(Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Error: Desbordamiento de pila.\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// Devuelve el carácter en el tope sin removerlo
char peek(Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Error: La pila está vacía.\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top];
}

// Devuelve la cantidad de elementos en la pila
int size(Stack *stack) {
    return stack->top + 1;
}

// Imprime el contenido de la pila desde el fondo hasta el tope
void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Pila vacía.\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++) {
        printf("%c ", stack->data[i]);
    }
    printf("\n");
}

// Libera la memoria ocupada por la pila
void freeStack(Stack *stack) {
    free(stack->data);
    stack->data = NULL;
    stack->top = -1;
    stack->capacity = 0;
}
