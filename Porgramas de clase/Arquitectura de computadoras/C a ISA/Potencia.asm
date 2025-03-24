# Programa original en C
# #include <stdio.h>
# int Potencia(int m, int n);
# int main(void) {
# int potencia;
# potencia = Potencia(6, 6);
# return 0 ;
# }
# int Potencia(int m,int n){
# if (n < 1){
# return(1);
# }
# else {
# return(m*Potencia(m,n - 1));
# }

# Procedimiento de transformación a lenguaje ensamblador
# 1. Definir las variables m y n con valores iniciales arbitrarios.
# 2. Definir la variable result con valor inicial arbitrario 0.
# 3. Definir la función Potencia que toma dos parámetros y devuelve la potencia de m elevado a n.
# 4. En la función principal main, llamar a la función Potencia con los valores iniciales de m y n.
# 5. Almacenar el resultado en la variable result.
# 6. Salir del programa.



.data           # Sección de datos
m:  .word 6         # Variables m y n con valores iniciales arbitrarios 6 y 3
n:  .word 6         
result: .word 0     # Variable result con valor inicial arbitrario 0

    .text           # Sección de código
    .globl main     # Punto de entrada del programa

main:               # Función principal
    la t0, m        # Carga la dirección de memoria de la variable m en t0
    la t1, n        # Carga la dirección de memoria de la variable n en t1
    lw a0, 0(t0)    # Carga 'm' en a0
    lw a1, 0(t1)    # Carga 'n' en a1

    jal Potencia    # Llamada a la función recursiva

    la t2, result   # Carga la dirección de memoria de la variable result en t2
    sw a0, 0(t2)    # Guarda el resultado en result

    j exit          # Salta a la función exit

Potencia:           # Función recursiva para calcular la potencia
    li t3, 1        # Carga el valor 1 en t3
    bge a1, t3, recurse  # Si n >= 1, continuar recursión
    li a0, 1            # Si n < 1, devolver 1
    ret                 # Retornar

recurse:                # Continuar recursión
    addi sp, sp, -8     # Reservar espacio en la pila
    sw ra, 4(sp)        # Guardar la dirección de retorno en la pila
    sw a1, 0(sp)        # Guardar el valor de n en la pila

    addi a1, a1, -1     # Decrementar n
    jal Potencia  # Llamado recursivo

    lw a1, 0(sp)    # Cargar el valor de n desde la pila
    lw ra, 4(sp)    # Cargar la dirección de retorno desde la pila
    addi sp, sp, 8  # Liberar espacio en la pila

    mul a0, a0, a1      # Calcular la potencia
    ret                 # Retornar

exit:                   # Función exit
    nop                 # No operation
