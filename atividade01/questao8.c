#include <stdio.h>

int main(void) {
    int fibo1 = 1;
    int fibo2 = 1;
    int n;

    printf("entre n: ");
    scanf("%d", &n);

    while (fibo2 < n) {
        printf("%d\n", fibo1);
        printf("%d\n", fibo2);
        fibo1 = fibo1 + fibo2;
        fibo2 = fibo1 + fibo2;
    }


    return 0;
}