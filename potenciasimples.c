#include <stdio.h>

int main() {
    float b, aux = 1;
    int i, p;

    scanf("%f %d", &b, &p);

    for (i = 0; i < p; i++) {
        aux *= b;
    }

    printf("%.4f", aux);

    return 0;
}