#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;
    int data[4][4];
    
    int count = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            data[i][j] = count++;
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    return 0;
}