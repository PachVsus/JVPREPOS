#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int i;
    char n[30];
    char a[30];
    char c;
} P;

P q[5];
int h = 0, t = 0, k = 0;
int kc[3] = {0};

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t pr = PTHREAD_COND_INITIALIZER;
pthread_cond_t cn = PTHREAD_COND_INITIALIZER;

void