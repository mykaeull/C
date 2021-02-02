#include <stdio.h>

int main() {
    int v[10];
    int i, n;
    int cont = 0;

    for (i = 0; i < 10; i++) {
        scanf("%d", &v[i]);
    }

    scanf("%d", &n);

    for (i = 0; i < 10; i++) {
        if (v[i] == n) {
            cont += 1;
        }
    }

    if (cont == 0) {
        printf("Mia x");
    } else {
        printf("%d\n", cont);
        for (i = 0; i < 10; i++) {
            if (v[i] == n) {
                printf("%d ", i);
            }
        }
    }

    return 0;
}