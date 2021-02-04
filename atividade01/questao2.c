#include <stdio.h>

int main(void) {
    int n1, n2, d, r;

    printf("entre n1: ");
    scanf("%d", &n1);
    printf("entre n2: ");
    scanf("%d", &n2);

    if (n1 > n2) {
        d = (n1 / n2);
        r = n1 - (d*n2);
    } else if (n1 < n2) {
        r = n1;
        d = 0;
    } else {
        r = 0;
        d = (n1 / n2);
    }

    printf("resultado inteiro da divisao: %d\n", d);
    printf("resto da divisao: %d", r);

    return 0;
}