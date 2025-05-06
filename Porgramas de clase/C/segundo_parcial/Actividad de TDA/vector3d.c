#include "vector3d.h"

Vector3D crear_vector(double x, double y, double z) {
    Vector3D v = {x, y, z};
    return v;
}

Vector3D sumar_vectores(Vector3D a, Vector3D b) {
    return crear_vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector3D multiplicar_por_escalar(Vector3D v, double escalar) {
    return crear_vector(v.x * escalar, v.y * escalar, v.z * escalar);
}

double producto_punto(Vector3D a, Vector3D b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3D producto_cruz(Vector3D a, Vector3D b) {
    return crear_vector(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}

double modulo(Vector3D v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

int es_vector_nulo(Vector3D v) {
    return fabs(v.x) < EPSILON && fabs(v.y) < EPSILON && fabs(v.z) < EPSILON;
}

double angulo_theta(Vector3D v) {
    return atan2(v.y, v.x);
}

double angulo_phi(Vector3D v) {
    double r = modulo(v);
    if (r < EPSILON) return 0.0;
    return acos(v.z / r);
}

void cosenos_directores(Vector3D v, double *cx, double *cy, double *cz) {
    double r = modulo(v);
    if (r < EPSILON) {
        *cx = *cy = *cz = 0.0;
        return;
    }
    *cx = v.x / r;
    *cy = v.y / r;
    *cz = v.z / r;
}

void a_esfericas(Vector3D v, double *r, double *theta, double *phi) {
    *r = modulo(v);
    *theta = angulo_theta(v);
    *phi = angulo_phi(v);
}

void imprimir_vector(Vector3D v) {
    printf("(%.2f, %.2f, %.2f)\n", v.x, v.y, v.z);
}

void imprimir_vector_esferico(Vector3D v) {
    double r, theta, phi;
    a_esfericas(v, &r, &theta, &phi);
    printf("(r=%.2f, theta=%.2f rad, phi=%.2f rad)\n", r, theta, phi);
}