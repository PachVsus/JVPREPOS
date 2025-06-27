#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H

// Estructura del nodo
typedef struct NodoDoble {
    int valor;
    struct NodoDoble* anterior;
    struct NodoDoble* siguiente;
} NodoDoble;

// Estructura de la lista doblemente ligada
typedef struct {
    NodoDoble* start;
    int cantidad;
} ListaDoble;

// Prototipos de funciones
void inicializarLista(ListaDoble* lista);
int estaVacia(ListaDoble* lista);
int obtenerCantidad(ListaDoble* lista);

void insertarInicio(ListaDoble* lista, int valor);
void insertarFinal(ListaDoble* lista, int valor);
int insertarDespuesDe(ListaDoble* lista, int valorObjetivo, int nuevoValor);
int insertarAntesDe(ListaDoble* lista, int valorObjetivo, int nuevoValor);

NodoDoble* buscarNodo(ListaDoble* lista, int valor);

int eliminarInicio(ListaDoble* lista);
int eliminarFinal(ListaDoble* lista);
int eliminarDespuesDe(ListaDoble* lista, int valorObjetivo);
int eliminarAntesDe(ListaDoble* lista, int valorObjetivo);

void imprimirLista(ListaDoble* lista);
void liberarLista(ListaDoble* lista);

#endif
