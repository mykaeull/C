#include <stdio.h>

int main(void) {
    long long n;
    long long reverse = 0;
    int r;

    printf("entre n: ");
    scanf("%lld", &n);

    while(n) {
        r = n % 10;
        n = n / 10;
        reverse = (reverse * 10) + r;
    }
    printf("n invertido: %lld", reverse);

    return 0;
}