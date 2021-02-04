#include <stdio.h>

int mdc(int x, int y) {
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
    return y;
}

int main() {
    int mdcc;

    mdcc = mdc(9, 45);

    printf("%d", mdcc);

    return 0;
}