# Programa original en C
##include <stdio.h>
#int suma(int a, int b);
#int resta(int a, int b);
#int multiplica(int a, int b);
#int andBitwise(int a, int b);
#int main(void) {
#int selector = 0; //registro s0
#int a = 5; // registro s1
#int b = 3; // registro s2
#int c = 0; // registro s3
#switch (selector)
#{
#case 1:
#c = suma(a,b);
#break;
#case 2:
#c = resta(a,b);
#break;
#case 3:
#c = multiplica(a, b);
#break;
#default:
#c = andBitwise(a,b);
#break;
#}
#}
#int suma(int a, int b)
#{
#int c = 0;
#c = a + b;
#return c;
#}
#int resta(int a, int b)
#{
#int c = 0;
#c = a - b;
#return c;
#}
#int multiplica(int a, int b)
#{
#int c = 0;
#c = a * b;
#return c;
#}
#int andBitwise(int a, int b)
#{ 
#int c = 0;
# c = a & b;

# Procedimiento de transformación a lenguaje ensamblador
# 1. Definir las variables a, b, c y selector con valores iniciales arbitrarios.
# 2. Definir las funciones suma, resta, multiplica y andBitwise que toman dos parámetros y devuelven el resultado de la operación correspondiente.
# 3. En la función principal main, utilizar un switch-case para determinar la operación a realizar según el valor de selector.
# 4. Llamar a la función correspondiente y almacenar el resultado en la variable c.
# 5. Salir del programa.

.data           # Sección de datos
a:  .word 5         # Variables a, b y c con valores iniciales arbitrarios 5, 3 y 0
b:  .word 3         
c:  .word 0
selector: .word 1  # Variable selector con valor inicial arbitrario 1

    .text           # Sección de código
    .globl main         # Punto de entrada del programa

main:                       # Función principal
    la t0, selector
    lw a0, 0(t0)        # Carga el valor de selector en a0

    la t1, a            # Carga la dirección de memoria de la variable a en t1
    la t2, b            # Carga la dirección de memoria de la variable b en t2
    lw a1, 0(t1)        # Carga 'a' en a1
    lw a2, 0(t2)        # Carga 'b' en a2

    beq a0, zero, default_case   # Si selector == 0, ir a caso default
    li t3, 1                    # Si selector == 1, ir a suma
    beq a0, t3, call_suma               # Si selector == 2, ir a resta
    li t3, 2                            # Si selector == 3, ir a multiplicación
    beq a0, t3, call_resta              # Si selector == 4, ir a operación AND
    li t3, 3                            # Si selector == 5, ir a operación OR
    beq a0, t3, call_multiplica         # Si selector == 6, ir a operación XOR
    j default_case                      # Si selector no es ninguno de los anteriores, ir a caso default

call_suma:                              # Llama a la función suma
    jal suma                            # Salta y guarda la dirección de retorno en ra
    j store_result                      # Establece la dirección de retorno en store_result

call_resta:                             # Llama a la función resta
    jal resta                           # Salta y guarda la dirección de retorno en ra
    j store_result                      # Establece la dirección de retorno en store_result

call_multiplica:                        # Llama a la función multiplica                     
    jal multiplica                      # Salta y guarda la dirección de retorno en ra
    j store_result                      # Establece la dirección de retorno en store_result

default_case:                           # Caso default
    jal andBitwise                      # Llama a la función andBitwise

store_result:                           # Almacena el resultado en la variable c
    la t3, c                            # Carga la dirección de memoria de la variable c en t3
    sw a0, 0(t3)                        # Guarda el resultado en c
    j exit                              # Salta a la función exit

suma:                                   # Función suma         
    add a0, a1, a2  # c = a + b
    ret                    # Retorna a la dirección de retorno

resta:                    # Función resta
    sub a0, a1, a2  # c = a - b
    ret             # Retorna a la dirección de retorno

multiplica:         # Función multiplica
    mul a0, a1, a2  # c = a * b
    ret                 # Retorna a la dirección de retorno

andBitwise:         # Función andBitwise
    and a0, a1, a2  # c = a & b
    ret             # Retorna a la dirección de retorno

exit:               # Función exit
    nop             # No operation
