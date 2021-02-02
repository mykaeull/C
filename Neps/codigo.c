#include <stdio.h>

int main() {
    int n;
    int cont = 0;
    int aux1 = 0, aux2 = 0, aux3 = 0;
    int i, num;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &num);

        if (num == 1) {
            aux1 = 1;
            aux2 = 0;
        } else if (aux1 == 1 && num == 0) {
            aux1 = 0;
            aux2 = 1;
        } else if (aux1 == 0 && aux2 == 1 && num == 0) {
            aux3 = 1;
            aux1 = 1;
        }

        if (aux1 == 1 && aux2 == 1 && aux3 == 1) {
            cont += 1;
            aux1 = 0;
            aux2 = 0;
            aux3 = 0;
        }

    }

    printf("%d", cont);

    return 0;
}