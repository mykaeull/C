#include <stdio.h>

int pot(int n, int k) {
    if (k == 0) {
        return 1;
    }
    return n*pot(n, k-1);
}

int fatExpo(int n) {
    if (n == 1) {
        return 1;
    }
    return pot(n, fatExpo(n-1));
}

int main() {
    int x;

    x = fatExpo(4); 
    printf("%d", x);

    return 0;
}