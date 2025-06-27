#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complejo.h"

Complejo* crearComplejo(double real, double imaginario) {
    Complejo* c = (Complejo*)malloc(sizeof(Complejo));
    if (c) {
        c->real = real;
        c->imaginario = imaginario;
    }
    return c;
}

void liberarComplejo(Complejo* c) {
    free(c);
}

Complejo* sumar(Complejo* c1, Complejo* c2) {
    return crearComplejo(c1->real + c2->real, c1->imaginario + c2->imaginario);
}

Complejo* restar(Complejo* c1, Complejo* c2) {
    return crearComplejo(c1->real - c2->real, c1->imaginario - c2->imaginario);
}

Complejo* multiplicar(Complejo* c1, Complejo* c2) {
    double real = c1->real * c2->real - c1->imaginario * c2->imaginario;
    double imag = c1->real * c2->imaginario + c1->imaginario * c2->real;
    return crearComplejo(real, imag);
}

Complejo* dividir(Complejo* c1, Complejo* c2) {
    double denom = c2->real * c2->real + c2->imaginario * c2->imaginario;
    double real = (c1->real * c2->real + c1->imaginario * c2->imaginario) / denom;
    double imag = (c1->imaginario * c2->real - c1->real * c2->imaginario) / denom;
    return crearComplejo(real, imag);
}

Complejo* potencia(Complejo* c, int exponente) {
    Polar p = aPolar(c);
    double magnitud = pow(p.magnitud, exponente);
    double angulo = p.angulo * exponente;
    return crearComplejo(magnitud * cos(angulo), magnitud * sin(angulo));
}

Complejo* raizCuadrada(Complejo* c) {
    Polar p = aPolar(c);
    double magnitud = sqrt(p.magnitud);
    double angulo = p.angulo / 2;
    return crearComplejo(magnitud * cos(angulo), magnitud * sin(angulo));
}

Polar aPolar(Complejo* c) {
    Polar p;
    p.magnitud = sqrt(c->real * c->real + c->imaginario * c->imaginario);
    p.angulo = atan2(c->imaginario, c->real);
    return p;
}

char* complejoToString(Complejo* c) {
    char* buffer = (char*)malloc(50 * sizeof(char));
    snprintf(buffer, 50, "(%.2f + %.2fi)", c->real, c->imaginario);
    return buffer;
}

