#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
};

void addnode(struct node** n1) {
    *n1 = (struct node*)malloc(sizeof(struct node));
    (*n1)->data = 9;
}

int main(void) {
    struct node *n1 = NULL;
    addnode(&n1);
    printf("%d\n", n1->data);

    return 0;
}