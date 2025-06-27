#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializarLista(Lista* lista) {
    lista->start = NULL;
    lista->cantidad_nodos = 0;
}

int estaVacia(Lista* lista) {
    return lista->start == NULL;
}

int obtenerCantidad(Lista* lista) {
    return lista->cantidad_nodos;
}

void insertarInicio(Lista* lista, int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->valor = valor;
    nuevo->siguiente = lista->start;
    lista->start = nuevo;
    lista->cantidad_nodos++;
}

void insertarFinal(Lista* lista, int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->valor = valor;
    nuevo->siguiente = NULL;

    if (lista->start == NULL) {
        lista->start = nuevo;
    } else {
        Nodo* temp = lista->start;
        while (temp->siguiente != NULL)
            temp = temp->siguiente;
        temp->siguiente = nuevo;
    }
    lista->cantidad_nodos++;
}

int insertarDespuesDe(Lista* lista, int valorObjetivo, int nuevoValor) {
    Nodo* temp = lista->start;
    while (temp != NULL && temp->valor != valorObjetivo)
        temp = temp->siguiente;
    if (temp == NULL) return 0;

    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->valor = nuevoValor;
    nuevo->siguiente = temp->siguiente;
    temp->siguiente = nuevo;
    lista->cantidad_nodos++;
    return 1;
}

int insertarAntesDe(Lista* lista, int valorObjetivo, int nuevoValor) {
    if (lista->start == NULL) return 0;

    if (lista->start->valor == valorObjetivo) {
        insertarInicio(lista, nuevoValor);
        return 1;
    }

    Nodo* anterior = NULL;
    Nodo* actual = lista->start;
    while (actual != NULL && actual->valor != valorObjetivo) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) return 0;

    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->valor = nuevoValor;
    nuevo->siguiente = actual;
    anterior->siguiente = nuevo;
    lista->cantidad_nodos++;
    return 1;
}

Nodo* buscarNodo(Lista* lista, int valor) {
    Nodo* temp = lista->start;
    while (temp != NULL) {
        if (temp->valor == valor)
            return temp;
        temp = temp->siguiente;
    }
    return NULL;
}

int eliminarInicio(Lista* lista) {
    if (lista->start == NULL) return 0;
    Nodo* temp = lista->start;
    lista->start = temp->siguiente;
    free(temp);
    lista->cantidad_nodos--;
    return 1;
}

int eliminarFinal(Lista* lista) {
    if (lista->start == NULL) return 0;

    Nodo* actual = lista->start;
    Nodo* anterior = NULL;

    while (actual->siguiente != NULL) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (anterior == NULL) {
        free(lista->start);
        lista->start = NULL;
    } else {
        anterior->siguiente = NULL;
        free(actual);
    }

    lista->cantidad_nodos--;
    return 1;
}

int eliminarDespuesDe(Lista* lista, int valorObjetivo) {
    Nodo* temp = buscarNodo(lista, valorObjetivo);
    if (temp == NULL || temp->siguiente == NULL) return 0;

    Nodo* eliminar = temp->siguiente;
    temp->siguiente = eliminar->siguiente;
    free(eliminar);
    lista->cantidad_nodos--;
    return 1;
}

int eliminarAntesDe(Lista* lista, int valorObjetivo) {
    if (lista->start == NULL || lista->start->siguiente == NULL) return 0;

    // Caso especial: eliminar el nodo justo antes del segundo nodo (start->siguiente) si es el objetivo
    if (lista->start->siguiente->valor == valorObjetivo) {
        return eliminarInicio(lista);
    }

    Nodo* prev = lista->start;
    Nodo* curr = lista->start->siguiente;
    Nodo* next = curr->siguiente;

    while (next != NULL && next->valor != valorObjetivo) {
        prev = curr;
        curr = next;
        next = next->siguiente;
    }

    if (next == NULL) return 0; // No se encontró valorObjetivo

    // Eliminar curr (que está justo antes de next)
    prev->siguiente = next;
    free(curr);
    lista->cantidad_nodos--;
    return 1;
}

void imprimirLista(Lista* lista) {
    Nodo* temp = lista->start;
    while (temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

void liberarLista(Lista* lista) {
    Nodo* actual = lista->start;
    while (actual != NULL) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    lista->start = NULL;
    lista->cantidad_nodos = 0;
}

