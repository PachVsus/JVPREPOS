.text
    addi s0, zero, 5 # int a = 5;
    addi s1, zero, 2 # int b = 2;
    addi s2, zero, 0 # int c = 0;

main:   addi t0, zero, 1
        beq s2, t0, if-label
        sub s2
        jal zero, exit
if-lablel:  add s2, s0, s1
exit: nop

addi t0
bne s2, t0, else-label
add s2
jal zero, exit
sub s2, s0, s1
else-label: addi t0, zero, 1
beq s2, t0, if-label
