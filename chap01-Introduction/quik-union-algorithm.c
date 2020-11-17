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
    int i, j, p, q, t, id[N];
    for (i = 0; i < N; i++) id[i] = i;

    while (scanf("%d %d\n", &p, &q) == 2) {
        printf("> %d %d", p, q);
        for (i = p; i != id[i]; i = id[i]);
        for (j = q; j != id[j]; j = id[j]);
        if (i == j) {printf("\n"); continue;}
        id[i] = j;
        printf(" >> %d %d", p, q);
        printarr(id, N);
    }

    return 0;
}
