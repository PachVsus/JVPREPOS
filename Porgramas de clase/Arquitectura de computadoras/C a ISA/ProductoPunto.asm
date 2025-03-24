# Programa original en C
# #include <stdio.h>
# int Vector_1[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
# int Vector_2[9] = { -1,2,-3,4,-5,6,-7,8,-9 };
# int i = 0;
# int resultado = 0;
# int Producto(int, int);
# int main(void) {
# for (i = 0; i < 9; i++)
# {
# result = result + ProductFunction(Vector_1[i], Vector_2[i]);
# }
# }
# int ProductFunction(int a, int b)
# {
# return(a*b);
# }
#

# Procedimiento de transformación a lenguaje ensamblador
# 1. Definir los vectores Vector_1 y Vector_2 con los valores dados.
# 2. Definir la variable resultado con valor inicial 0.
# 3. Definir la función ProductFunction que toma dos parámetros y devuelve su producto.
# 4. En la función principal main, inicializar i en 0 y recorrer los vectores Vector_1 y Vector_2.
# 5. En cada iteración, llamar a la función ProductFunction con los elementos actuales de los vectores y sumar el resultado al valor de resultado.
# 6. Al finalizar el bucle, mostrar el valor de resultado.



.data       
Vector_1: .word 1, 2, 3, 4, 5, 6, 7, 8, 9           # Vector 1
Vector_2: .word -1, 2, -3, 4, -5, 6, -7, 8, -9      # Vector 2
result: .word 0                                     # Resultado

    .text           # Sección de código
    .globl main     # Punto de entrada del programa

main:
    la t0, Vector_1  # Cargar dirección del primer vector   # la = load address
    la t1, Vector_2  # Cargar dirección del segundo vector  
    la t2, result    # Dirección donde almacenaremos el resultado

    li t3, 0    # i = 0
    li t4, 9    # tamaño del vector
    li t5, 0    # resultado = 0

loop:                               # Bucle principal
    bge t3, t4, end_loop        # Si i >= tamaño del vector, salir del bucle. bge = branch greater than or equal
    lw a0, 0(t0)  # Cargar Vector_1[i]  # lw = load word
    lw a1, 0(t1)  # Cargar Vector_2[i]  # lw = load word

    jal ProductFunction  # Llamada a multiplicación

    add t5, t5, a0  # resultado += ProductFunction(Vector_1[i], Vector_2[i])

    addi t0, t0, 4  # Moverse al siguiente elemento del vector 1
    addi t1, t1, 4  # Moverse al siguiente elemento del vector 2
    addi t3, t3, 1  # i++

    j loop          # Salto al inicio del bucle

end_loop:
    sw t5, 0(t2)  # Guardar resultado

    j exit      # Salto a la función exit

ProductFunction:    # Función de multiplicación
    mul a0, a0, a1  # Multiplicación de elementos del vector
    ret         # Retornar

exit:           # Función de salida
    nop         # No operation
