#include <stdio.h>
#include <stdlib.h>
#include "./dinamica.h"

int main() {
    void *vetor;
    void *matriz;

    vetor = criar_vetor(16);
	atribuir_vetor(vetor, 8, 456.0);
	printf("A pos. 8 do vetor contem: %f.\n", obter_vetor(vetor, 8));
	liberar_vetor(vetor);

	matriz = criar_matriz(10, 10);
	atribuir_matriz(matriz, 5, 4, 12.0);
	printf("A pos. (5,4) da matriz contem: %f.\n", obter_matriz(matriz, 5, 4));
	liberar_matriz(matriz);
    
    /* ===== CÓDIGO PARA TESTE DA API =====
    vetor = criar_vetor(4);
    printf("%d\n", atribuir_vetor(vetor, 0, 1.0)); // caso 0: falha na operação | caso 1: sucesso na operação
    printf("%d\n", atribuir_vetor(vetor, 1, 2.0)); // caso 0: falha na operação | caso 1: sucesso na operação
    printf("%d\n", atribuir_vetor(vetor, 2, 3.0)); // caso 0: falha na operação | caso 1: sucesso na operação
    printf("%d\n", atribuir_vetor(vetor, 3, 4.0)); // caso 0: falha na operação | caso 1: sucesso na operação
    printf("%lf\n", obter_vetor(vetor, 0)); // caso 0: falha na operação
    printf("%lf\n", obter_vetor(vetor, 1)); // caso 0: falha na operação
    printf("%lf\n", obter_vetor(vetor, 2)); // caso 0: falha na operação
    printf("%lf\n", obter_vetor(vetor, 3)); // caso 0: falha na operação
    liberar_vetor(vetor);

    matriz = criar_matriz(3, 2);
    printf("%d\n", atribuir_matriz(matriz, 0, 0, 1.0)); // caso 0: falha na operação | caso 1: sucesso na operação
    printf("%d\n", atribuir_matriz(matriz, 0, 1, 2.0)); // caso 0: falha na operação | caso 1: sucesso na operação
    printf("%d\n", atribuir_matriz(matriz, 1, 0, 3.0)); // caso 0: falha na operação | caso 1: sucesso na operação
    printf("%d\n", atribuir_matriz(matriz, 1, 1, 4.0)); // caso 0: falha na operação | caso 1: sucesso na operação
    printf("%d\n", atribuir_matriz(matriz, 2, 0, 5.0)); // caso 0: falha na operação | caso 1: sucesso na operação
    printf("%d\n", atribuir_matriz(matriz, 2, 1, 6.0)); // caso 0: falha na operação | caso 1: sucesso na operação
    printf("%lf\n", obter_matriz(matriz, 0, 0)); // caso 0: falha na operação
    printf("%lf\n", obter_matriz(matriz, 0, 1)); // caso 0: falha na operação
    printf("%lf\n", obter_matriz(matriz, 1, 0)); // caso 0: falha na operação
    printf("%lf\n", obter_matriz(matriz, 1, 1)); // caso 0: falha na operação
    printf("%lf\n", obter_matriz(matriz, 2, 0)); // caso 0: falha na operação
    printf("%lf\n", obter_matriz(matriz, 2, 1)); // caso 0: falha na operação
    liberar_matriz(matriz);
    */

    return 0;
}