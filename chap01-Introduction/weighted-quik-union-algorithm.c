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
    int i, j, p, q, id[N], sz[N];
    for (i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }

    while (scanf("%d %d\n", &p, &q) == 2) {
        printf("> %d %d", p, q);
        for (i = p; i != id[i]; i = id[i]);
        for (j = q; j != id[j]; j = id[j]);
        if (i == j) {
            printf("       ");
            printarr(id, N);
            continue;
        }
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
        printf(" >> %d %d", p, q);
        printarr(id, N);
    }

    return 0;
}
