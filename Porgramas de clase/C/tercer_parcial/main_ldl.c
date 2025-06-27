#include <stdio.h>
#include <stdlib.h>
#include "lista_doble.h"

int main() {
    ListaDoble lista;
    inicializarLista(&lista);

    // Insertar 15 elementos al final
    for (int i = 1; i <= 15; i++) {
        insertarFinal(&lista, i * 5);
    }

    printf("Lista inicial con 15 elementos:\n");
    imprimirLista(&lista);

    // Insertar al inicio
    insertarInicio(&lista, -5);
    insertarInicio(&lista, -2);
    insertarInicio(&lista, 3);

    printf("\nDespues de insertar 3 elementos al inicio:\n");
    imprimirLista(&lista);

    // Insertar al final
    insertarFinal(&lista, 200);
    insertarFinal(&lista, 210);
    insertarFinal(&lista, 220);
    insertarFinal(&lista, 230);
    insertarFinal(&lista, 240);

    printf("\nDespues de insertar 5 elementos al final:\n");
    imprimirLista(&lista);

    // Insertar después de ciertos valores
    insertarDespuesDe(&lista, 30, 31);
    insertarDespuesDe(&lista, 60, 61);
    insertarDespuesDe(&lista, 90, 91);

    printf("\nDespues de insertar 3 elementos despues de ciertos valores:\n");
    imprimirLista(&lista);

    // Insertar antes de ciertos valores
    insertarAntesDe(&lista, 200, 199);
    insertarAntesDe(&lista, 220, 219);
    insertarAntesDe(&lista, 240, 239);

    printf("\nDespues de insertar 3 elementos antes de ciertos valores:\n");
    imprimirLista(&lista);

    // Buscar valores
    int buscar[] = {91, 5, 220, 180, 3};
    for (int i = 0; i < 5; i++) {
        NodoDoble* nodo = buscarNodo(&lista, buscar[i]);
        if (nodo) {
            printf("Valor %d encontrado.\n", nodo->valor);
        } else {
            printf("Valor %d no encontrado.\n", buscar[i]);
        }
    }

    // Eliminar al inicio
    eliminarInicio(&lista);
    eliminarInicio(&lista);
    eliminarInicio(&lista);

    printf("\nDespues de eliminar 3 elementos del inicio:\n");
    imprimirLista(&lista);

    // Eliminar al final
    eliminarFinal(&lista);
    eliminarFinal(&lista);
    eliminarFinal(&lista);

    printf("\nDespues de eliminar 3 elementos del final:\n");
    imprimirLista(&lista);

    // Eliminar después de ciertos valores
    eliminarDespuesDe(&lista, 199);
    eliminarDespuesDe(&lista, 219);
    eliminarDespuesDe(&lista, 239);

    printf("\nDespues de eliminar 3 nodos ubicados despues de ciertos valores:\n");
    imprimirLista(&lista);

    // Eliminar antes de ciertos valores
    eliminarAntesDe(&lista, 10);
    eliminarAntesDe(&lista, 15);
    eliminarAntesDe(&lista, 25);

    printf("\nDespues de eliminar 3 nodos ubicados antes de ciertos valores:\n");
    imprimirLista(&lista);

    // Verificar si la lista está vacía
    printf("\n¿La lista esta vacia?: %s\n", estaVacia(&lista) ? "Si" : "No");

    // Obtener cantidad de elementos
    printf("Cantidad de elementos en la lista: %d\n", obtenerCantidad(&lista));

    // Liberar lista
    liberarLista(&lista);
    printf("\nDespues de liberar la lista:\n");
    imprimirLista(&lista);
    printf("Cantidad de elementos tras liberar: %d\n", obtenerCantidad(&lista));

    return 0;
}
