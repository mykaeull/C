#include <stdio.h>

int main(void) {
    int ano;

    printf("entre com o ano: ");
    scanf("%d", &ano);

    if (ano < 1752) {
        printf("ano nao bissexto");
    } else {
        if ((ano % 4 == 0) && (ano % 100 != 0)) {
            printf("ano bissexto");
        } else if ((ano % 4 == 0) && (ano % 100 == 0)) {
            if (ano % 400 == 0) {
                printf("ano bissexto");
            } else {
                printf("ano nao bissexto");
            }
        } else {
            printf("ano nao bissexto");
        }
    }

    



    return 0;
}