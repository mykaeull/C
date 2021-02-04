#include <stdio.h>

int main() {
    int n, i, num, r;
    int v[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        while (num) {
            r = num % 10;
            num = num / 10;
            if (r == 0) {
                v[0] += 1;
            } else if (r == 1) {
                v[1] += 1;
            } else if (r == 2) {
                v[2] += 1;
            } else if (r == 3) {
                v[3] += 1;
            } else if (r == 4) {
                v[4] += 1;
            } else if (r == 5) {
                v[5] += 1;
            } else if (r == 6) {
                v[6] += 1;
            } else if (r == 7) {
                v[7] += 1;
            } else if (r == 8) {
                v[8] += 1;
            } else {
                v[9] += 1;
            }
        }
    }

    for (i = 0; i < 10; i++) {
        printf("%d - %d\n", i, v[i]);
    }

    return 0;
}