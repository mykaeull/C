#include <stdio.h>

int mdc(int x, int y, int z) {
    int r;
    int r1;
    int cont = 0;
    
    r = x % y;
    while (r != 0) {
        r1 = y % r;
        y = r;
        r = r1;
        if (r1 == 0) {
            r = 0;
        }
    }
    r = y % z;
    while (r != 0) {
        r1 = z % r;
        z = r;
        r = r1;
        if (r1 == 0) {
            r = 0;
        }
    }
    return z;
    // return y;
}

int main() {
    int x, y, z;

    printf("entre x: ");
    scanf("%d", &x);
    printf("entre y: ");
    scanf("%d", &y);
    printf("entre z: ");
    scanf("%d", &z);
    
    printf("%d", mdc(x, y, z));

    return 0;
}