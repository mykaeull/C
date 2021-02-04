#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *p;

    n = 3;
    p = &n;
    p = (int*)malloc(sizeof(int)*2);

    printf("%d\n", p);
    printf("%d\n", p+1);
    printf("%d\n", *p);

    free(p);

    printf("%d\n", p);

    return 0;
}