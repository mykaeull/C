#include <stdio.h>

void convertBin(int n) {

    if (n <= 1) {
        printf("%d ", n);
        return ;
    }
    convertBin(n/2);
    printf("%d ", n % 2);
}

int main() {
    convertBin(10);


    return 0;
}