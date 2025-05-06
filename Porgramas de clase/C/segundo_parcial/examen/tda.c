/*Diseña un Tipo de Dato Absracto (TDA) en lenguaje C que implante una pila de caracteres utilizando un arreglo autocreciente) es decir, que cuando se acerque al límite de capacidad
del arreglo, el rprgrama haga lo necesario para que el arreglo aumente su capacidad -puedes usar el criterio de duplicarla o incrementarla un orden de magnitud-). Las operaciones
básicas que el TDA debe implantar son: colocar un elemento en la pila, remover un elemento de la pila, consultar el valor al que apunta el Top de la pila, devolver la cantidad de elementos presentes en la pila,
imprimir el contenido de la pila e indicar si la pila esta vacia.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Primero se define el TDA, en este caso es una pila de caracteres
// Se define la estructura de la pila
typedef struct {
    char *data;
    int top;
    int capacity;
} Stack;    // Pila

// Funcion para inicializar la pila
// Se le asigna un tamaño inicial al arreglo de caracteres
void initStack(Stack *stack, int initialCapacity) {
    stack->data = (char *)malloc(initialCapacity * sizeof(char));
    if (stack->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = -1;
    stack->capacity = initialCapacity;
}

// Funcion para verificar si la pila esta vacia
// Se verifica si el tope de la pila es -1, lo que indica que no hay elementos en la pila
// Se devuelve true si la pila esta vacia, false en caso contrario
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Funcion para verificar si la pila esta llena
// Se verifica si el tope de la pila es igual a la capacidad - 1, lo que indica que no hay espacio para agregar mas elementos
void resizeStack(Stack *stack) {
    int newCapacity = stack->capacity * 2;
    char *newData = (char *)realloc(stack->data, newCapacity * sizeof(char));
    if (newData == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->data = newData;
    stack->capacity = newCapacity;
}

// Funcion para agregar un elemento a la pila
// Se verifica si la pila esta llena, en caso afirmativo se llama a la funcion resizeStack para aumentar la capacidad del arreglo
void push(Stack *stack, char value) {
    if (stack->top == stack->capacity - 1) {
        resizeStack(stack);
    }
    stack->data[++stack->top] = value;
}

// Funcion para eliminar un elemento de la pila
// Se verifica si la pila esta vacia, en caso afirmativo se imprime un mensaje de error y se termina el programa
char pop(Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// Funcion para obtener el elemento en la parte superior de la pila sin eliminarlo
// Se verifica si la pila esta vacia, en caso afirmativo se imprime un mensaje de error y se termina el programa
char peek(Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top];
}

// Funcion para obtener la cantidad de elementos en la pila
// Se devuelve el tope de la pila + 1, ya que el tope comienza en -1
int size(Stack *stack) {
    return stack->top + 1;
}

// Funcion para imprimir el contenido de la pila
// Se verifica si la pila esta vacia, en caso afirmativo se imprime un mensaje de error y se termina el programa
// Se imprime cada elemento de la pila desde el tope hasta el fondo
void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++) {
        printf("%c ", stack->data[i]);
    }
    printf("\n");
}

// Funcion para liberar la memoria ocupada por la pila
// Se libera la memoria ocupada por el arreglo de caracteres y se reinician los valores de la pila
void freeStack(Stack *stack) {
    free(stack->data);
    stack->data = NULL;
    stack->top = -1;
    stack->capacity = 0;
}

int main() {
    Stack stack;
    initStack(&stack, 2); // Capacidad inicial de 2
    // Se inicializa la pila con una capacidad de 2 elementos

    push(&stack, 'A');
    push(&stack, 'B');
    push(&stack, 'C'); // Esto provocara un aumento de la capacidad del arreglo
    // Se agregan 3 elementos a la pila, el tercer elemento provocara un aumento de la capacidad del arreglo

    printf("Contenido de la pila: ");
    printStack(&stack);

    printf("Top elemento: %c\n", peek(&stack));
    printf("Tamaño de la pila: %d\n", size(&stack));

    pop(&stack);
    printf("Despues de hacer pop en los elementos: ");
    printStack(&stack);

    freeStack(&stack);
    return 0;
}