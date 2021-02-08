#include <stdio.h>
#include <stdlib.h>
#include "./dinamica.h"

int main() {
    void *vetor;
    void *matriz;
    
    vetor = criar_vetor(4);
    printf("%d\n", atribuir_vetor(vetor, 0, 1.0));
    printf("%d\n", atribuir_vetor(vetor, 1, 2.0));
    printf("%d\n", atribuir_vetor(vetor, 2, 3.0));
    printf("%d\n", atribuir_vetor(vetor, 3, 4.0));
    printf("%lf\n", obter_vetor(vetor, 0));
    printf("%lf\n", obter_vetor(vetor, 1));
    printf("%lf\n", obter_vetor(vetor, 2));
    printf("%lf\n", obter_vetor(vetor, 3));
    liberar_vetor(vetor);

    matriz = criar_matriz(3, 2);
    printf("%d\n", atribuir_matriz(matriz, 0, 0, 1.0));
    printf("%d\n", atribuir_matriz(matriz, 0, 1, 2.0));
    printf("%d\n", atribuir_matriz(matriz, 1, 0, 3.0));
    printf("%d\n", atribuir_matriz(matriz, 1, 1, 4.0));
    printf("%d\n", atribuir_matriz(matriz, 2, 0, 5.0));
    printf("%d\n", atribuir_matriz(matriz, 2, 1, 6.0));
    printf("%lf\n", obter_matriz(matriz, 0, 0));
    printf("%lf\n", obter_matriz(matriz, 0, 1));
    printf("%lf\n", obter_matriz(matriz, 1, 0));
    printf("%lf\n", obter_matriz(matriz, 1, 1));
    printf("%lf\n", obter_matriz(matriz, 2, 0));
    printf("%lf\n", obter_matriz(matriz, 2, 1));
    liberar_matriz(matriz);

    
    
    

    /*vetor = criar_vetor(tam);
    vetor[0] = 2.0;
    atribuir_vetor(vetor, 1, 3.0);
    atribuir_vetor(vetor, 2, 4.0);
    atribuir_vetor(vetor, 3, 5.0);
    printf("%d\n", vetor);
    printf("%lf\n", vetor[0]);
    printf("%lf\n", vetor[1]);
    liberar_vetor(vetor, tam);
    printf("%d\n", vetor);
    printf("%lf\n", vetor[0]);
    printf("%lf\n", vetor[1]);
    printf("%lf\n", vetor[2]);
    printf("%lf\n", vetor[3]); */

    // printf("%d", *(vetor+1)); mostra a proxima posicao

    return 0;
}