# d = a & 0xf0;
# e = b | 0x02;
# c = d & e;
#
#
#
#
#
#
#
#


.text
	addi s0, zero, 0xdf # int a = 0;
	addi s1, zero, 0xd0 # int b = 1;
	addi s2, zero, 0 # int c = 2;
	addi s3, zero, 0 # int d = 3;
	addi s4, zero, 0 # int e = 4;
	
main:	andi s3, s0, 0xf0 # d = a & 0xf0;
    ori s4, s1, 0x02 # e = b | 0x02;
    and s2, s3, s4 # c = d & e;
    
    li a0, 1
    li a7, 10
    ecall