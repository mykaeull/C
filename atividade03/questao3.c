#include <stdio.h>

int fatorialQuadruplo(int n) {

    if (n == 1) {
        return 1;
    }

    return n*fatorialQuadruplo(n-1);
    
}

int main() {
    int n = 5;
    int fat2n;
    int fatn;

    fat2n = fatorialQuadruplo(2*n);
    fatn = fatorialQuadruplo(n);
    
    printf("%d", fat2n / fatn);


    return 0;
}