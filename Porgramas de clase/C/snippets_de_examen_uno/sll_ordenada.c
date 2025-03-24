// Jesús Vargas Pacheco

#include <stdio.h>
#include <stdlib.h>

// Se define la estructura nodo sin typedef:
struct Nodo {
    int data;
    struct Nodo* next;
};

// Función para insertar un nodo en la lista
void insertar(struct Nodo** head, int data) {
    struct Nodo* new_node = (struct Nodo*)malloc(sizeof(struct Nodo));  // Se crea un nuevo nodo
    struct Nodo* current = *head;  // Se crea un nodo que apunta al inicio de la lista
    struct Nodo* prev = NULL;  // Se crea un nodo que apunta al nodo anterior al actual

    new_node->data = data;  // Se asigna el dato al nuevo nodo
    new_node->next = NULL;  // Se asigna NULL al siguiente del nuevo nodo

    // Si la lista está vacía o el dato es menor al primer nodo
    if (*head == NULL || (*head)->data >= data) {
        new_node->next = *head;  // El siguiente del nuevo nodo apunta al inicio de la lista
        *head = new_node;  // El inicio de la lista apunta al nuevo nodo
    } else {
        // Se recorre la lista hasta encontrar el lugar donde se insertará el nuevo nodo
        while (current != NULL && current->data < data) {
            prev = current;  // El nodo anterior al actual apunta al actual
            current = current->next;  // El actual apunta al siguiente
        }
        new_node->next = current;  // El siguiente del nuevo nodo apunta al actual
        prev->next = new_node;  // El siguiente del nodo anterior apunta al nuevo nodo
    }
}

// Se crea una función para imprimir el contenido de la lista
void imprimir(struct Nodo* head) {
    struct Nodo* current = head;  // Se crea un nodo que apunta al inicio de la lista

    // Se recorre la lista e imprime cada nodo
    while (current != NULL) {
        printf("%d -> ", current->data);  // Se imprime el dato del nodo
        current = current->next;  // El nodo actual apunta al siguiente
    }
    printf("NULL\n");  // Se imprime NULL al final de la lista
}

int main() {
    struct Nodo* head = NULL;  // Se crea un nodo que apunta al inicio de la lista
    int n, data;

    printf("Ingrese el número de elementos: "); // Se pide al usuario que ingrese el número de elementos
    scanf("%d", &n);    // Se guarda el número de elementos

    for (int i = 0; i < n; i++) {   // Se recorre el número de elementos
        printf("Ingrese el elemento %d: ", i + 1);  // Se pide al usuario que ingrese el elemento
        scanf("%d", &data); // Se guarda el elemento
        insertar(&head, data);  // Se inserta el elemento en la lista
    }

    // Se imprime el contenido de la lista
    imprimir(head);

    return 0;
}