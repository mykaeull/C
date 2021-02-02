#include <stdio.h>

int main() {
    int *p;
    int x = 5;
    int v[3] = {6, 7, 8};
    int matriz[3][3];

    p = &x;

    printf("%d", *p);

    *p = 10;

    printf("\n%d", *p);
    printf("\n%d", x);

    printf("\n%d", p);

    p = p + 1;

    printf("\n%d", p);

    p = p + 1;

    printf("\n%d", p);

    printf("\n------------------");

    printf("\n%d", v+2);

    printf("\n%d", *v);

    printf("\n%d", *v+1);

    printf("\n------------------");

    printf("\n%d", matriz+1);

    return 0;
}