#include <stdio.h>
#include <stdlib.h>

typedef struct fila Fila;

struct fila {
    int primeiro;
    int ultimo;
    int v[10];
};

Fila criar_fila() {
    Fila fila;
    fila.primeiro = -1;
    fila.ultimo = -1;
    return fila;
}

void inserir_elemento(Fila *F, int x) {
    if (F->primeiro == -1 && F->ultimo == -1) {
        F->primeiro = 0;
        F->ultimo = 0;
        F->v[F->primeiro] = x;
        F->v[F->ultimo] = x;
    } else {
        F->ultimo += 1;
        F->v[F->ultimo] = x; 
    }
}

void remover_elemento(Fila *F) {
    if (F->primeiro == F->ultimo) {
        F->primeiro = -1;
        F->ultimo = -1;
    } else {
        F->primeiro += 1;
    }
}

void mostrarFila(Fila *F) {
    int x, y;
    x = F->primeiro;
    y = F->ultimo;
    if (F->primeiro == -1 && F->ultimo == -1) {
        printf("fila vazia");
    } else {
        for (x; x <= y; x++) {
        printf("%d ", F->v[x]);
        }
    }
    
}

int main() {
    Fila F = criar_fila();

    inserir_elemento(&F, 10);
    inserir_elemento(&F, 20);
    inserir_elemento(&F, 30);

    remover_elemento(&F);
    remover_elemento(&F);
    remover_elemento(&F);

    mostrarFila(&F);

    return 0;
}