#include <stdio.h>
#include <stdlib.h>
#define N 26

typedef struct node *link;
struct node {
    char item;
    link next;
};

link reverse(link x) {
    link t, y = x, r = NULL;
    while (y != NULL) {
        t = y->next;
        y->next = r;
        r = y;
        y = t;
    }
    return r;
}

void traverse(link x) {
    for (; x != NULL; x = x->next)
        printf("%c ", x->item);
    printf("\n");
}

int main() {
    int i;
    link a = malloc(sizeof *a), x = a;
    a->item = 'a';
    a->next = NULL;
    for (i = 1; i < N; i++) {
        x = (x->next = malloc(sizeof *x));
        x->item = 'a' + i;
        x->next = NULL;
    }
    
    traverse(a);
    traverse(reverse(a));

    return 0;
}
