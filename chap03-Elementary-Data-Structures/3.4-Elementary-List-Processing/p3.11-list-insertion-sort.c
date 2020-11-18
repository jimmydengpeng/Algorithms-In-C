#include <stdio.h>
#include <stdlib.h>
#include "../../show_bytes.c"
#define N 10

typedef struct node* link;
struct node {
    int item;
    link next;
};

void traverse(link x) {
    int single = 1;
    for (; x != NULL; x = x->next)
        if (single) {
            printf("%d", x->item); single = 0;
        } else 
            printf(" -> %d", x->item);
    printf("\n");
}

int main() {
    struct node heada, headb;
    link t, u, x, a = &heada, b;

    t = a;
    for (int i = 0; i < N; i++) {
        t->next = malloc(sizeof *t);
        t = t->next;
        t->next = NULL;
        t->item = rand() % 1000; //0~999
    }
    traverse(a->next);

    b = &headb;
    b->next = NULL;
    for (t = a->next; t != NULL; t = u) {
        u = t->next;
        for (x = b; x->next != NULL; x = x->next)
            if (x->next->item > t->item)
                break;
        t->next = x->next;
        x->next = t;
    }
    traverse(b->next);

    return 0;
}
