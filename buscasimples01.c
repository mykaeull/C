#include <stdio.h>

int main() {
    int v[10];
    int i, n;

    for (i = 0; i < 10; i++) {
        scanf("%d", &v[i]);
    }

    scanf("%d", &n);

    for (i = 0; i < 10; i++) {
        if (v[i] == n) {
            printf("SIM");
            break;
        } else if (i == 9) {
            printf("NAO");
        }
    }

    return 0;
}