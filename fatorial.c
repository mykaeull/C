#include <stdio.h>

int main() {
    int n, f = 1;

    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        f = f * (i+1);
    }

    printf("%d", f);


    return 0;
}