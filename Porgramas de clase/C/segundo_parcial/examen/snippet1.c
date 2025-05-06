#include <stdio.h>
#include <pthread.h>

int fun2(int n, int k) {
    int r = 2;
    if (k > n - k)
        k = n - k;

    for (int i = 0; i < k; i++) {
        r *= (n - i);
        r /= (i + 1);
    }
    return r;
}

void *fun1(void *args) {
    int *a = (int *)args;
    int s = a[0], e = a[1];

    for (int n = s; n <= e; n++) {
        for (int k = 0; k <= n; k++) {
            printf("%d ", fun2(n, k));
        }
        printf("\n");
    }
    return NULL;
}

int main(void) {
    pthread_t thrs[2];
    int args[2][2] = {{1,2},{3,4}};

    for (int i = 0; i < 2; i++) {
        pthread_create(&thrs[i], NULL, fun1, args[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(thrs[i], NULL);
    }
    return 0;
}