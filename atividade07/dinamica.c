#include "dinamica.h"
#include <stdlib.h>

void* criar_vetor(int tam) {
    double *vetor = (double*)malloc((tam+1)*sizeof(double));
    ((int*)vetor)[0] = tam; // guarda o tamanho do vetor para futuras operações
    return vetor;
}

double obter_vetor(void *vetor, int x) {
    int tam = ((int*)vetor)[0];
    int p = x + 1;
    if (x < 0 || x >= tam) {
        return -1; // posição inválida
    } else {
        return ((double*)vetor)[p];
    }
}

int atribuir_vetor(void *vetor, int x, double val) {
    int tam = ((int*)vetor)[0];
    int p = x + 1; // como a posição 0 do vetor ja possui um elemento, todo novo elemento será armazenado no próximo endereço de memória
    if (x < 0 || x >= tam) {
        return 0; // posição inválida
    } else {
        ((double*)vetor)[p] = val;
        return 1; // posição válida
    }
}

void liberar_vetor(void *vetor) {
    free(vetor);
}

void* criar_matriz(int l, int c) {
    double *matriz = (double*)malloc(((l*c)+2)*sizeof(double)); 
    ((int*)matriz)[0] = l; // guarda o número de linhas da matriz para futuras operações
    ((int*)matriz)[1] = c; // guarda o número de colunas da matriz para futuras operações
    return matriz; 
}

double obter_matriz(void *matriz, int l, int c) {
    int num_l = ((int*)matriz)[0];
    int num_c = ((int*)matriz)[1];
    if ((l < 0 || l >= num_l) || (c < 0 || c >= num_c)) {
        return -1; // posição inválida
    } else {
        return *(((double*)matriz+2) + l * (num_l - 1) + c);
    }
}

int atribuir_matriz(void *matriz, int l, int c, double val) {
    int num_l = ((int*)matriz)[0];
    int num_c = ((int*)matriz)[1];
    if ((l < 0 || l >= num_l) || (c < 0 || c >= num_c)) {
        return 0; // posição inválida
    } else {
        *(((double*)matriz+2) + l * (num_l - 1) + c) = val;
        return 1; // posição válida
    }
}

void liberar_matriz(void *matriz) {
    free(matriz);
}
