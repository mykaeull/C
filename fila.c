#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct fila Fila1;

struct no {
    int num;
    struct no *anterior;
    struct no *proximo;
};

struct fila {
    struct no *primeiro;
    struct no *ultimo;
};

No* criar_no(int n) {
    No *novo = (No*)malloc(sizeof(No));
    novo->num = n;
    return novo;
}

Fila1 criar_fila() {
    Fila1 fila;
    fila.primeiro = NULL;
    fila.ultimo = NULL;
    return fila;
}

void inserir_no(Fila1 *F, int n) {
    No *no = criar_no(n);
    no->proximo = NULL;
    if (F->primeiro == NULL && F->ultimo == NULL) { 
        no->anterior = NULL;
        F->primeiro = F->ultimo = no;
    } else {
        no->anterior = F->ultimo;
        F->ultimo->proximo = no;
        F->ultimo = no;
    }
}

void remover_no(Fila1 *F, int n) {
    No *aux = F->primeiro;
    int entrou = 0;
    while (aux != NULL) {
        if (n == aux->num) {
            entrou = 1;
            break;
        }
        aux = aux->proximo;
    }
    if (entrou && aux == F->primeiro) {
        F->primeiro = aux->proximo;
        F->primeiro->anterior = NULL;
        free(aux);
    } else if (entrou && aux == F->ultimo) {
        F->ultimo = aux->anterior;
        F->ultimo->proximo = NULL;
        free(aux);
    }else if(entrou){
        aux->anterior->proximo = aux->proximo;
        aux->proximo->anterior = aux->anterior;
        free(aux);
    }
}

void mostrarFila(Fila1 *F){
    No *aux = F->primeiro;
    while(aux != NULL){ 
        printf("%d ", aux->num);
        aux = aux->proximo;
    }
    printf("\n");
}

int main() {
    int x, y, i;
    Fila1 F = criar_fila();

    scanf("%d", &x);

    for (i = 0; i < x; i++) {
        scanf("%d", &y);
        inserir_no(&F, y);
    }

    scanf("%d", &x);
    for(int i = 0; i < x; i++){
        scanf("%d", &y);
        remover_no(&F, y);
    }
    mostrarFila(&F);
    return 0;
    //MYKAEULL 
}