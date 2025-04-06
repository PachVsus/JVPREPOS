# Implementa en RARS un algoritmo que permita sumar dos matrices de tamaño n x n. Almacena en el segmento de memoria el resultado de la suma mediante una matriz R de tamaño n x n. El algoritmo deberá funcionar para cualquier tamaño de n.

.data
n: .word 3  # Tamaño de la matriz (n x n)

# Matriz A (3x3)
MatrizA: .word 2, 0, 1, 
               3, 0, 0, 
               5, 1, 1

# Matriz B (3x3)
MatrizB: .word 1, 0, 1, 
               1, 2, 1, 
               1, 1, 0

# Espacio para MatrizResultado (400 para que sea compatible con cualquier numero de n que permita la memoria.
MatrizResultado: .space 400

.text
.globl main

main:
    # Cargar n y calcular n*n
    la t0, n
    lw t1, 0(t0)       # t1 = n
    mul t2, t1, t1     # t2 = total de elementos (n * n)

    li t3, 0           # contador i = 0

    # Cargar direcciones base
    la t4, MatrizA
    la t5, MatrizB
    la t6, MatrizResultado

loop:
    bge t3, t2, end    # while i < n*n

    lw s0, 0(t4)       # s0 = A[i]
    lw s1, 0(t5)       # s1 = B[i]
    add s2, s0, s1     # s2 = A[i] + B[i]
    sw s2, 0(t6)       # Resultado[i] = s2

    # Avanzar punteros
    addi t4, t4, 4     # A++
    addi t5, t5, 4     # B++
    addi t6, t6, 4     # Resultado++
    addi t3, t3, 1     # i++
    j loop

end:
    li a7, 10
    ecall
