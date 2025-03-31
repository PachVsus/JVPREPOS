#include <stdio.h>
#define BIG_ENDIAN 0
#define LITTLE_ENDIAN 1

int endian(void) {
    short int word = 0x0001;
    char *byte = (char *) &word;

    return (byte[0] ? LITTLE_ENDIAN : BIG_ENDIAN);
}

int main(void) {
    int value = endian();

    if(value == 1)
        printf("The machine is Little Endian\n");
    else
        printf("The machine is Big Endian\n");

    return 0;
}