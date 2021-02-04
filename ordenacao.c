#include <stdio.h>

int main() {
    int n, i, x, num, j;

    scanf("%d", &n);

    int v[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        v[i] = num;
    }

    for (i = 1; i <= n; i++) {
        x = v[i];
        j = i - 1;
        while ((j >= 0) && (v[j] > x)) {
            v[j+1] = v[j];
            j -= 1;
        }
        v[j+1] = x;
    }

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}