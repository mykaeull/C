#include <stdio.h>

int fatorial(int n) {

    if (n == 1) {
        return 1;
    }

    return n*fatorial(n-1);
}

int fatorialDoFatorial(int n) {
    if (n == 1) {
        return 1;
    }
    return fatorialDoFatorial(n-1)*fatorial(n);
}


int main() {
    int fat;

    fat = fatorialDoFatorial(4);
    printf("%d", fat);

    return 0;
}