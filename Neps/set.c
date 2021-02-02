#include <stdio.h>
#include <set>

int main() {
    int n, x, i;

    std::set<int> S;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        S.insert(x);
    }

    printf("%d", S.size());

    return 0;
}