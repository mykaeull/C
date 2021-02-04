#include <stdio.h>

int main(void) {
    int l1, l2, l3;

    printf("entre com os 3 lados do triangulo:\n");
    scanf("%d", &l1);
    scanf("%d", &l2);
    scanf("%d", &l3);

     if ((l1 > l2) && (l1 > l3)) {
         if ((l1*l1) == ((l2*l2) + (l3*l3))) {
            printf("triangulo retangulo");
         } else {
            printf("nao triangulo retangulo");
         }
     } else if ((l2 > l1) && (l2 > l3)) {
         if ((l2*l2) == ((l1*l1) + (l3*l3))) {
            printf("triangulo retangulo");
         } else {
            printf("nao triangulo retangulo");
         }
     } else if ((l3 > l2) && (l3 > l1)) {
         if ((l3*l3) == ((l2*l2) + (l1*l1))) {
            printf("triangulo retangulo");
         } else {
            printf("nao triangulo retangulo");
         }
     } else {
         printf("nao triangulo retangulo");
     }

    return 0;
}