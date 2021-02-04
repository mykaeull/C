#include <stdio.h>

void selection_sort(int *v, int tam) {
    int i, j, aux, menor;

    for (i = 0; i < (tam-1); i++) {
        menor = i;
        for (j = (i+1); j < tam; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        if (menor != i) {
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
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

    selection_sort(vetor, tam);

    return 0;
}