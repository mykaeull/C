#ifndef dinamica_h
#define dinamica_h

#include <stdio.h>

void* criar_vetor(int);
double obter_vetor(void *, int);
int atribuir_vetor(void *, int, double);
void liberar_vetor(void *);

void* criar_matriz(int, int);
double obter_matriz(void *, int, int);
int atribuir_matriz(void *, int, int, double);
void liberar_matriz(void *);

#endif