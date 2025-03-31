#include <stdio.h>
#include <stdlib.h>

int main() {
    int *iptr;
    int *nptr;
    int *rptr;

    iptr = (int *) malloc(5 * sizeof(int));
    if(iptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for(int i=0; i<5; i++) {
        iptr[i] = i + 1;
    }

    for(int i=0; i<5; i++) {
        printf("iptr[%d] = %d\n", i, iptr[i]);
    }

    nptr = (int *) realloc(iptr, 10 * sizeof(int));
    if(nptr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    iptr = nptr;

    for(int i=5; i<10; i++) {
        iptr[i] = i + 1;
    }

    for(int i=0; i<10; i++) {
        printf("iptr[%d] = %d\n", i, iptr[i]);
    }

    rptr = (int *) realloc(iptr, 5 * sizeof(int));
    if(rptr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    iptr = rptr;

    for(int i=0; i<5; i++) {
        printf("iptr[%d] = %d\n", i, iptr[i]);
    }

    free(iptr);

    return 0;
}