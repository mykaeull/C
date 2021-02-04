#include <stdio.h>

int main() {
    long long n, aux, reverse = 0;
    int r;

    scanf("%lld", &n);

    aux = n;

    while(n) {
        r = n % 10;
        n = n / 10;
        reverse = (reverse * 10) + r;
    }

    if (reverse == aux) {
        printf("o numero eh um polindromo");
    } else {
        printf("o numero nao eh um polindromo");
    }

    return 0;
}