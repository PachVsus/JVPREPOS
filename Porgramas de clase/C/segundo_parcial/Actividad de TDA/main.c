#include "vector3d.h"

int main() {
    Vector3D v1, v2;
    double escalar;

    printf("Ingrese el primer vector (x y z): ");
    scanf("%lf %lf %lf", &v1.x, &v1.y, &v1.z);

    printf("Ingrese el segundo vector (x y z): ");
    scanf("%lf %lf %lf", &v2.x, &v2.y, &v2.z);

    printf("\n--- Resultados ---\n");

    printf("Vector 1: ");
    imprimir_vector(v1);
    printf("Coordenadas esfericas: ");
    imprimir_vector_esferico(v1);

    printf("\nVector 2: ");
    imprimir_vector(v2);
    printf("Coordenadas esfericas: ");
    imprimir_vector_esferico(v2);

    printf("\nSuma: ");
    imprimir_vector(sumar_vectores(v1, v2));

    printf("\nIngrese un escalar para multiplicar el primer vector: ");
    scanf("%lf", &escalar);
    printf("Resultado: ");
    imprimir_vector(multiplicar_por_escalar(v1, escalar));

    printf("\nProducto punto: %.2f\n", producto_punto(v1, v2));

    printf("Producto cruz: ");
    imprimir_vector(producto_cruz(v1, v2));

    printf("\nModulo de Vector 1: %.2f\n", modulo(v1));
    printf("Theta: %.2f rad\n", angulo_theta(v1));
    printf("Phi: %.2f rad\n", angulo_phi(v1));

    double cx, cy, cz;
    cosenos_directores(v1, &cx, &cy, &cz);
    printf("Cosenos directores: cx=%.2f, cy=%.2f, cz=%.2f\n", cx, cy, cz);

    return 0;
}