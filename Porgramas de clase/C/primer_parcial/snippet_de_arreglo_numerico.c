#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *arr = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        *(arr + i) = i + 10;
    }

    int *ptr = arr + 2;
    printf("%d", *ptr + *(ptr - 1));
    free(arr);
    return 0;
}