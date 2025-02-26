#include <stdio.h>
#include <stdlib.h>
int main(int arg, char* argv[])
{
    struct data
    {
        int i;
        char c;
        int j;
    };
    struct data *sptr = (struct data*)malloc(sizeof(struct data)); // pointer variable of type struct data
    struct data svar;  // normal variable of type struct data
    printf("%c\n", sptr->c = 'c');
    printf("%d\n", sptr->i = 10);
    printf("%d\n", sptr->j = 20);
    printf("%c\n", (*sptr).c = 'd');
    printf("%d\n", (*sptr).i = 30);
    printf("%d\n", (*sptr).j = 40);
    printf("%d\n", (*sptr).j = 40);
    svar.i = 1;
    svar.i = 1;
    svar.j = 2;

    (&svar)->c = 'c';
    (&svar)->i = 3;
    (&svar)->j = 4;
    return 0;
}

// this program is not complete, it is just a snippet. A snippet is a small piece of code that is not complete, but it is enough to show a concept.