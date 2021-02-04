#include <stdio.h>

int main(void) {
    float n1, n2;

    printf("entre n1: ");
    scanf("%f", &n1);
    printf("entre n2: ");
    scanf("%f", &n2);

    if (n2 == 0) {
        printf("resultado da divisao: invalido");
    } else {
        printf("resultado da divisao: %.2f", n1 / n2);
    }

    return 0;
}