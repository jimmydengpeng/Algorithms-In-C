#include <stdio.h>

int main() {
    int p, q, rs;
    while ((rs = scanf("%d %d\n", &p, &q)) == 2) {
        printf("return value: %d, input: %d %d\n", rs, p, q);
    }
    return 0;
}
