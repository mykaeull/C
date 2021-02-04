#include <stdio.h>

void bubble_sort(int *v, int tam) {
    int i, j, aux;

    for (j = 1; j < tam; j++) {
        for (i = 0; i < (tam - 1); i++) {
            if (v[i] > v[i+1]) {
            aux = v[i+1];
            v[i+1] = v[i];
            v[i] = aux;
            }
        }
    }
    

    for (i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
}

int main() {
    int tam, i;
    
    printf("entre o tamanho do vetor: ");
    scanf("%d", &tam);

    int vetor[tam];

    printf("\nentre os valores do vetor\n");
    for (i = 0; i < tam; i++) {
        scanf("%d", &vetor[i]);
    }

    bubble_sort(vetor, tam);

    return 0;
}