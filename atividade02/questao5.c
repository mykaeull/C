#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double pot(double x, int k) {
    int base = x;

    k = k - 1;

    if (k == 0) {
        return x;
    }
    return (base * pot(x, k));
}

int main() {
    double resultado1, resultado2;
    double x = 2;
    int k = 5;

    resultado1 = pot(x, k);
    resultado2 = pow(x, k);

    printf("Minha funcao: %lf\n", resultado1);
    printf("Funcao pow: %lf\n", resultado2);


    return 0;
}