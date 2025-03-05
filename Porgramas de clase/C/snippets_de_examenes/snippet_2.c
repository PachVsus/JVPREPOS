#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *arr = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        *(arr + i) = i * 3;
    }

    int *ptr = arr;
    ptr += 3;
    printf("%d", *ptr);

    free(arr);
    return 0;
}