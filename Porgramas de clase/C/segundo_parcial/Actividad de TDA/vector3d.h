#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <stdio.h>
#include <math.h>

#define EPSILON 1e-9

typedef struct {
    double x, y, z;
} Vector3D;

// Prototipos de funciones
Vector3D crear_vector(double x, double y, double z);
Vector3D sumar_vectores(Vector3D a, Vector3D b);
Vector3D multiplicar_por_escalar(Vector3D v, double escalar);
double producto_punto(Vector3D a, Vector3D b);
Vector3D producto_cruz(Vector3D a, Vector3D b);
double modulo(Vector3D v);
double angulo_theta(Vector3D v);
double angulo_phi(Vector3D v);
void cosenos_directores(Vector3D v, double *cx, double *cy, double *cz);
void a_esfericas(Vector3D v, double *r, double *theta, double *phi);
void imprimir_vector(Vector3D v);
void imprimir_vector_esferico(Vector3D v);
int es_vector_nulo(Vector3D v);

#endif
