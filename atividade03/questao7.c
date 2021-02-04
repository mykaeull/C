#include <stdio.h>

int fibo(int n) {
    
    if (n < 4) {
        return 0;
    } else if (n == 4) {
        return 1;
    } 
    return fibo(n-1)+fibo(n-2)+fibo(n-3)+fibo(n-4);
}

int main() {
    int x;

    x = fibo(12);
    printf("%d", x);

    return 0;
}