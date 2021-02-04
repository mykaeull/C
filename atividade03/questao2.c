#include <stdio.h>

int fatorialDuplo(int n) {

    if (n == 1) {
        return 1;
    }
    return n*fatorialDuplo(n-2);
}

int main() {
    int fat;

    fat = fatorialDuplo(7);

    printf("%d", fat);


    return 0;
}