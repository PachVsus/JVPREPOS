#ifndef LISTA_H
#define LISTA_H

// Estructura del nodo
typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} Nodo;

//Estructura de la
//Lista Simplemente Ligada
typedef struct {
    Nodo* start;
    int cantidad_nodos;
} Lista;

// Prototipos de las funciones que forman el TDA
void inicializarLista(Lista* lista);
int estaVacia(Lista* lista);
int obtenerCantidad(Lista* lista);
void insertarInicio(Lista* lista, int valor);
void insertarFinal(Lista* lista, int valor);
int insertarDespuesDe(Lista* lista, int valorObjetivo, int nuevoValor);
int insertarAntesDe(Lista* lista, int valorObjetivo, int nuevoValor);
Nodo* buscarNodo(Lista* lista, int valor);
int eliminarInicio(Lista* lista);
int eliminarFinal(Lista* lista);
int eliminarDespuesDe(Lista* lista, int valorObjetivo);
int eliminarAntesDe(Lista* lista, int valorObjetivo);
void imprimirLista(Lista* lista);
void liberarLista(Lista* lista);

#endif

