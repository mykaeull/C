#include <stdio.h>

int main() {
    int n, i, cont = 0;
    float r, aux;

    scanf("%d", &n);

    int v[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (i = 0; i < n; i++) {
        if (i != (n-1)) { 
            r = v[i+1] / v[i];
            if (i == 0) {
                aux = r;
            } else {
                if (r == aux) {
                    cont += 1;
                }
            }
        }
    }

    if (cont == (n-2)) {
        printf("sequencia eh uma PG\n");
        printf("razao: %.2f", aux);
    } else {
        printf("sequencia nao eh uma PG");
    }

    return 0;
}