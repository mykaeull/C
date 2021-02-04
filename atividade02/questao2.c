#include <stdio.h>

void primo(int n) { // item a
    int cont1 = 2;
    int cont2 = 0;
    
    while (cont1 <= n) {
        if (n % cont1 == 0) {
            cont2 += 1;
        }
        cont1 += 1; 
    } 
    if (cont2 == 1) {
        printf("%d eh primo\n", n);
    } else {
        printf("%d nao eh primo\n", n);
    }
}

void primosMenores(int n) { // item b
    int cont1 = 2;
    int cont2 = 2;
    int cont3 = 0;

    while (cont1 < n) {
        while (cont2 <= cont1) {
            if (cont1 % cont2 == 0) {
                cont3 += 1;
            }
            cont2 += 1;
        }
        if (cont3 == 1) {
            printf("%d\n", cont1);
        }
        cont1 += 1;
        cont2 = 2;
        cont3 = 0;
    }

}

void primeirosPrimos(int n) { // item c
    int cont1 = 2;
    int cont2 = 2;
    int cont3 = 0;
    int cont4 = 1;

    while (cont4 <= n) {
        while (cont2 <= cont1) {
            if (cont1 % cont2 == 0) {
                cont3 += 1;
            }
            cont2 += 1;
        }
        if (cont3 == 1) {
            printf("%d\n", cont1);
            cont4 += 1;
        }
        cont1 += 1;
        cont2 = 2;
        cont3 = 0;
    }

}

int main() {
    int n, m;
    primo(9); // item a

    printf("entre n: ");
    scanf("%d", &n);
    primosMenores(n); // item b

    printf("entre m: ");
    scanf("%d", &m);
    primeirosPrimos(m);
    
    return 0;
}