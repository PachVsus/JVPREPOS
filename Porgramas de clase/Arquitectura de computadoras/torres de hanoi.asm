# Torres de Hanoi - RISC-V
# Integrantes:
# Jesús Vargas Pacheco - 750962
# Nestor Eduardo Perez Avalos - 753844

.text
main:
            addi s0, zero, 8              # N (s0) = x
            lui  s1, 0x10010              # Base de torre A
            addi t0, zero, 0x20                 # Tama�o de disco (32)
            mul  t0, s0, t0               # t0 = N * 32
            add  s1, s1, t0               # Torre A = base + N * 32
            addi s2, s1, 4                # Torre B   abajo de la base
            addi s3, s2, 4                # Torre C
            addi s4, zero,0               # contador
            add  t0, zero, s0             # t0 = N (contador de discos)

for:
            beq  t0, zero, hanoi          # si t0 == 0, ir a hanoi
            addi  s1, s1, -32              # direcci�n = s1 + desplazamiento hacia arriba
            sw   t0, 0(s1)                # guarda disco en torre A
            addi t5, t5, -32              # pr�ximo desplazamiento
            addi t0, t0, -1               # siguiente disco
            j    for

hanoi:      addi t0, zero, 1              # t0 = 1

if:         bne s0, t0, else              # Si s0 != 1, ir a else caso base
            sw zero, 0x0(s1)              # Borrar disco de A
            addi s1, s1, 0x20             # Mover A -> A + 32, para desplazar hacia abajo
            addi s3, s3, -0x20            # Mover C -> C - 32, para desplazar hacia arriba
            sw s0, 0(s3)                  # Agregar disco a C  
            addi s4, s4, 1                # contador = contador + 1, para visualizar el # de movimientos
            jalr ra                       # Retornar de la recursi�n

else:       addi sp, sp, -4               # Espacio en el stack
            sw ra, 0x0(sp)                # Guardar ra
            addi sp, sp, -4
            sw s0, 0x0(sp)                # Guardar s0
            addi s0, s0, -1               # n = n - 1

            # Intercambiar B y C para la llamada recursiva
            add t1, s2, zero              # B -> TEMP
            add s2, s3, zero              # B = C
            add s3, t1, zero              # C = B (anterior)

            jal ra, hanoi                 # hanoi(n-1, A, B, C)

            # Restaurar B y C para la siguiente llamada recursiva
            add t1, s2, zero              # B -> TEMP
            add s2, s3, zero              # B = C
            add s3, t1, zero              # C = B (anterior)

            # Restaurar s0 y ra despu�s de la primera llamada recursiva
            lw s0, 0x0(sp)                # Recuperar s0
            addi sp, sp, 4
            lw ra, 0x0(sp)                # Recuperar ra
            addi sp, sp, 4

            sw zero, 0x0(s1)              # Borrar disco de A
            addi s1, s1, 0x20             # Mover A -> A + 32
            addi s3, s3, -0x20            # Mover C -> C - 32
            sw s0, 0x0(s3)                # Agregar disco a C

            addi s4, s4, 1                # contador++

            # Guardar ra y s0 en el stack antes de la segunda llamada recursiva
            addi sp, sp, -4
            sw ra, 0x0(sp)                # Guardar ra
            addi sp, sp, -4
            sw s0, 0x0(sp)                # Guardar s0

            addi s0, s0, -1               # n = n - 1

            # Intercambiar A y B para la segunda llamada recursiva
            add t1, s1, zero              # A -> TEMP
            add s1, s2, zero              # A = B
            add s2, t1, zero              # B = A (anterior)
            jal ra, hanoi                 # hanoi(n-1, B, C, A)

            # Restaurar A y B
            add t1, s1, zero              # A -> TEMP
            add s1, s2, zero              # A = B
            add s2, t1, zero              # B = A (anterior)

            lw s0, 0x0(sp)                # Recuperar s0
            addi sp, sp, 4
            lw ra, 0x0(sp)                # Recuperar ra
            addi sp, sp, 4

            jalr ra                       # Retornar

exit:       j exit
