#include <stdio.h>

int main() {
    int v_escolhidos[10];
    int v_sorteados[6];
    int i, j, cont = 0;

    for (i = 0; i < 10; i++) {
        scanf("%d", &v_escolhidos[i]);
    }

    for (i = 0; i < 6; i++) {
        scanf("%d", &v_sorteados[i]);
    }

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 10; j++) {
            if (v_escolhidos[j] == v_sorteados[i]) {
                cont += 1;
            }
        }
    }
    // 13 11 59 2 36 4 5 7 3 1 - escolhidos
    // 11 4 5 3 22 14 - sorteados
    printf("%d", cont);
    return 0;
}