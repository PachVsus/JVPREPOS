.section .data
    num1: .word 5
    num2: .word 10

.section .text
    .globl _start

_start:
    # Cargar los valores de num1 y num2 en registros
    la t0, num1
    lw t1, 0(t0)
    la t0, num2
    lw t2, 0(t0)

    # Sumar los valores
    add t3, t1, t2

    # Guardar el resultado en un registro
    mv a0, t3

    # Finalizar el programa
    li a7, 10
    ecall