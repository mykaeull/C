#include <stdio.h>

int fat(int n) {
    if (n == 0) {
        return 1;
    }

    return n*fat(n-1);
}

int main() {
    int n;
    int fatorial;

    scanf("%d", &n);

    fatorial = fat(n);

    printf("%d", fatorial);

    return 0;
}