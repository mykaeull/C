#include <stdio.h>

int main(void) {
    int n;
    int cont1 = 2;
    int cont2 = 2;
    int primo = 0;
    int maior_primo;

    printf("entre n: ");
    scanf("%d", &n);

    while (cont1 < n) {
        while (cont2 <= cont1 ) {
            if (cont1 % cont2 == 0) {
                primo += 1;
            }
            cont2 += 1;
        }
        if (primo == 1) {
            maior_primo = cont1;
            primo = 0;
            cont2 = 2;
        }
        cont1 += 1;
        primo = 0;
        cont2 = 2;
    }
    printf("%d", maior_primo);

    return 0;
}