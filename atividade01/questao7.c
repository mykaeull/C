#include <stdio.h>

int main(void) {
    int n;
    int cont1 = 2;
    int cont2 = 2;
    int primo = 0;

    printf("entre com n: ");
    scanf("%d", &n);

    while (cont1 <= n) {
        while (cont2 <= cont1 ) {
            if (cont1 % cont2 == 0) {
                primo += 1;
            }
            cont2 += 1;
        }
        if (primo == 1) {
            printf("n: %d\n", cont1);
            primo = 0;
            cont2 = 2;
        }
        cont1 += 1;
        primo = 0;
        cont2 = 2;
    }

    return 0;
}