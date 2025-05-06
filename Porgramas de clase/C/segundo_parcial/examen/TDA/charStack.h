// Nombre: Jesus Vargas Pacheco

#ifndef CHARSTACK_H
#define CHARSTACK_H

#include <stdbool.h>


// Primero se define el TDA, en este caso es una pila de caracteres
// Se define la estructura de la pila
typedef struct {
    char *data; // Arreglo de caracteres que representa la pila
    int top;    // Indice del tope de la pila
    int capacity;   // Capacidad actual de la pila
} Stack;    // Pila

// Prototipos de funciones
void initStack(Stack *stack, int initialCapacity);  // Inicializa la pila con una capacidad inicial dada
bool isEmpty(Stack *stack); // Verifica si la pila está vacía
void resizeStack(Stack *stack); // Duplica la capacidad del arreglo de la pila
void push(Stack *stack, char value);    // Agrega un carácter al tope de la pila
char pop(Stack *stack);   // Remueve y devuelve el carácter en el tope de la pila
char peek(Stack *stack);    // Devuelve el carácter en el tope sin removerlo
int size(Stack *stack);     // Devuelve la cantidad de elementos en la pila
void printStack(Stack *stack);  // Imprime el contenido de la pila
void freeStack(Stack *stack);   // Libera la memoria ocupada por la pila

#endif  // Sirve para evitar la inclusion multiple de este archivo
