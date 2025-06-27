#include <stdio.h>
#include <stdlib.h>
#include "lista_doble.h"

void inicializarLista(ListaDoble* lista) {
    lista->start = NULL;
    lista->cantidad = 0;
}

int estaVacia(ListaDoble* lista) {
    return lista->start == NULL;
}

int obtenerCantidad(ListaDoble* lista) {
    return lista->cantidad;
}

void insertarInicio(ListaDoble* lista, int valor) {
    NodoDoble* nuevo = malloc(sizeof(NodoDoble));
    nuevo->valor = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = lista->start;

    if (lista->start != NULL)
        lista->start->anterior = nuevo;

    lista->start = nuevo;
    lista->cantidad++;
}

void insertarFinal(ListaDoble* lista, int valor) {
    NodoDoble* nuevo = malloc(sizeof(NodoDoble));
    nuevo->valor = valor;
    nuevo->siguiente = NULL;

    if (lista->start == NULL) {
        nuevo->anterior = NULL;
        lista->start = nuevo;
    } else {
        NodoDoble* temp = lista->start;
        while (temp->siguiente != NULL)
            temp = temp->siguiente;
        temp->siguiente = nuevo;
        nuevo->anterior = temp;
    }

    lista->cantidad++;
}

int insertarDespuesDe(ListaDoble* lista, int valorObjetivo, int nuevoValor) {
    NodoDoble* temp = buscarNodo(lista, valorObjetivo);
    if (!temp) return 0;

    NodoDoble* nuevo = malloc(sizeof(NodoDoble));
    nuevo->valor = nuevoValor;
    nuevo->anterior = temp;
    nuevo->siguiente = temp->siguiente;

    if (temp->siguiente)
        temp->siguiente->anterior = nuevo;

    temp->siguiente = nuevo;
    lista->cantidad++;
    return 1;
}

int insertarAntesDe(ListaDoble* lista, int valorObjetivo, int nuevoValor) {
    NodoDoble* temp = buscarNodo(lista, valorObjetivo);
    if (!temp) return 0;

    if (temp == lista->start) {
        insertarInicio(lista, nuevoValor);
        return 1;
    }

    NodoDoble* nuevo = malloc(sizeof(NodoDoble));
    nuevo->valor = nuevoValor;
    nuevo->siguiente = temp;
    nuevo->anterior = temp->anterior;

    temp->anterior->siguiente = nuevo;
    temp->anterior = nuevo;
    lista->cantidad++;
    return 1;
}

NodoDoble* buscarNodo(ListaDoble* lista, int valor) {
    NodoDoble* temp = lista->start;
    while (temp) {
        if (temp->valor == valor)
            return temp;
        temp = temp->siguiente;
    }
    return NULL;
}

int eliminarInicio(ListaDoble* lista) {
    if (lista->start == NULL) return 0;

    NodoDoble* temp = lista->start;
    lista->start = temp->siguiente;

    if (lista->start)
        lista->start->anterior = NULL;

    free(temp);
    lista->cantidad--;
    return 1;
}

int eliminarFinal(ListaDoble* lista) {
    if (lista->start == NULL) return 0;

    NodoDoble* temp = lista->start;
    while (temp->siguiente)
        temp = temp->siguiente;

    if (temp->anterior)
        temp->anterior->siguiente = NULL;
    else
        lista->start = NULL;

    free(temp);
    lista->cantidad--;
    return 1;
}

int eliminarDespuesDe(ListaDoble* lista, int valorObjetivo) {
    NodoDoble* temp = buscarNodo(lista, valorObjetivo);
    if (!temp || !temp->siguiente) return 0;

    NodoDoble* eliminar = temp->siguiente;
    temp->siguiente = eliminar->siguiente;

    if (eliminar->siguiente)
        eliminar->siguiente->anterior = temp;

    free(eliminar);
    lista->cantidad--;
    return 1;
}

int eliminarAntesDe(ListaDoble* lista, int valorObjetivo) {
    NodoDoble* temp = buscarNodo(lista, valorObjetivo);
    if (!temp || !temp->anterior) return 0;

    NodoDoble* eliminar = temp->anterior;

    if (eliminar->anterior)
        eliminar->anterior->siguiente = temp;
    else
        lista->start = temp;

    temp->anterior = eliminar->anterior;
    free(eliminar);
    lista->cantidad--;
    return 1;
}

void imprimirLista(ListaDoble* lista) {
    NodoDoble* temp = lista->start;
    while (temp) {
        printf("%d <-> ", temp->valor);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

void liberarLista(ListaDoble* lista) {
    NodoDoble* actual = lista->start;
    while (actual) {
        NodoDoble* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    lista->start = NULL;
    lista->cantidad = 0;
}
