#include <stdio.h>
#include "lista.h"

int main() {
    Lista miLista;
    inicializarLista(&miLista);

    // Insertar 15 elementos al final
    for (int i = 1; i <= 15; i++) {
        insertarFinal(&miLista, i * 10);  // 10, 20, ..., 150
    }

    printf("Lista inicial con 15 elementos:\n");
    imprimirLista(&miLista);

    // Insertar al inicio
    insertarInicio(&miLista, 5);
    insertarInicio(&miLista, 3);
    insertarInicio(&miLista, 1);

    printf("\nDespues de insertar 3 elementos al inicio:\n");
    imprimirLista(&miLista);

    // Insertar al final
    insertarFinal(&miLista, 160);
    insertarFinal(&miLista, 170);
    insertarFinal(&miLista, 180);

    printf("\nDespues de insertar 3 elementos al final:\n");
    imprimirLista(&miLista);

    // Insertar despues de un valor
    insertarDespuesDe(&miLista, 30, 35);  // después de 30
    insertarDespuesDe(&miLista, 60, 65);  // después de 60
    insertarDespuesDe(&miLista, 90, 95);  // después de 90

    printf("\nDespues de insertar 3 elementos despues de ciertos valores:\n");
    imprimirLista(&miLista);

    // Insertar antes de un valor
    insertarAntesDe(&miLista, 100, 95);   // antes de 100
    insertarAntesDe(&miLista, 130, 125);  // antes de 130
    insertarAntesDe(&miLista, 10, 8);     // antes de 10

    printf("\nDespues de insertar 3 elementos antes de ciertos valores:\n");
    imprimirLista(&miLista);

    // Buscar nodos
    int valoresABuscar[] = {60, 125, 170, 190, -3};
    for (int i = 0; i < 5; i++) {
        Nodo* encontrado = buscarNodo(&miLista, valoresABuscar[i]);
        if (encontrado) {
            printf("\nValor %d encontrado.\n", encontrado->valor);
        } else {
            printf("\nValor %d no encontrado.\n", valoresABuscar[i]);
        }
    }

    // Eliminar al inicio
    eliminarInicio(&miLista);
    eliminarInicio(&miLista);
    eliminarInicio(&miLista);

    printf("\nDespues de eliminar 3 elementos del inicio:\n");
    imprimirLista(&miLista);

    // Eliminar al final
    eliminarFinal(&miLista);
    eliminarFinal(&miLista);
    eliminarFinal(&miLista);

    printf("\nDespues de eliminar 3 elementos del final:\n");
    imprimirLista(&miLista);

    // Eliminar después de cierto valor
    eliminarDespuesDe(&miLista, 35);   // elimina 40
    eliminarDespuesDe(&miLista, 70);   // elimina 80
    eliminarDespuesDe(&miLista, 125);  // elimina 130

    printf("\nDespues de eliminar 3 elementos ubicados despues de ciertos valores:\n");
    imprimirLista(&miLista);

    // Eliminar antes de cierto valor
    eliminarAntesDe(&miLista, 95);    // Elimina 90
    eliminarAntesDe(&miLista, 100);    // Elimina 95
    eliminarAntesDe(&miLista, 160);   // No existe

    printf("\nDespues de eliminar 3 elementos ubicados antes de ciertos valores:\n");
    imprimirLista(&miLista);

    // Consultar si está vacía
    printf("\n¿La lista esta vacia?: %s\n", estaVacia(&miLista) ? "Si" : "No");

    // Cantidad actual de elementos
    printf("Cantidad de elementos en la lista: %d\n", obtenerCantidad(&miLista));

    // Liberar lista
    liberarLista(&miLista);
    printf("\nDespues de liberar la lista:\n");
    imprimirLista(&miLista);
    printf("Cantidad de elementos tras liberar: %d\n", obtenerCantidad(&miLista));

    return 0;
}
