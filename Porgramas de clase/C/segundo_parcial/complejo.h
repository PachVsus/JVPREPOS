#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <stdbool.h>

// Estructura para un número complejo
typedef struct {
    double real;
    double imaginario;
} Complejo;

// Estructura para la representación polar
typedef struct {
    double magnitud;
    double angulo;  // En radianes
} Polar;

// Funciones del TDA
Complejo* crearComplejo(double real, double imaginario);
void liberarComplejo(Complejo* c);

Complejo* sumar(Complejo* c1, Complejo* c2);
Complejo* restar(Complejo* c1, Complejo* c2);
Complejo* multiplicar(Complejo* c1, Complejo* c2);
Complejo* dividir(Complejo* c1, Complejo* c2);
Complejo* potencia(Complejo* c, int exponente);
Complejo* raizCuadrada(Complejo* c);

Polar aPolar(Complejo* c);
char* complejoToString(Complejo* c);

#endif

