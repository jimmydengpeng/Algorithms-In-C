#include <stdio.h>
#define N 10

void printarr(int* arr, int len) {
    printf("   ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int rt;
    int i, p, q, t, id[N];
    for (i = 0; i < N; i++) id[i] = i;

    while (scanf("%d %d\n", &p, &q) == 2) {
        printf("> %d %d", p, q);
        if (id[p] == id[q]) {
            printf(" >> already connected, continue\n");
            continue;
        }
        for (t = id[p], i = 0; i < N; i++)
            if (id[i] == t) id[i] = id[q];
        printf(" >> %d %d", p, q);
        printarr(id, N);
    }

    return 0;
}
