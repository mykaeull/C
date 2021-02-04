#include <stdio.h>

int main(void) {
    int cont = 1;
    int cont1 = 1;
    int finish = 0;

    while (finish == 0) {
        if ((cont % 2 != 0) && (cont % 3 != 0) && (cont % 7 != 0)) {
            printf("%d\n", cont);      
            cont1 += 1;    
        }
        cont += 1;
        if (cont1 == 1000) {
            finish = 1;
        }
    }

    return 0;
}