#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetores(long long int *vetor1, long long int *vetor2, long long int *vetor3, long long int *vetor4, int n) {
    for(int i = 0; i < n; i++) {
	      long long int a = rand()%((n*100)+1);
        vetor1[i] = a;
        vetor2[i] = a;
        vetor3[i] = a;
        vetor4[i] = a;
    }
}

long double bubble_sort(long long int *vetor, int n) {
    int i, j, aux;
    time_t tempo_inicio, tempo_fim;
    long double tempo_total;

    tempo_inicio = clock();
    for (i = 0; i < n; i++) {
        for (j = 0; j < (n-1); j++) {
            aux = vetor[j+1];
            if (aux < vetor[j]) {
                vetor[j+1] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    tempo_fim = clock();
    tempo_total = (long double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;

    return tempo_total;
}

long double insertion_sort(long long int *vetor, int n) {
    int i, j, aux;
    time_t tempo_inicio, tempo_fim;
    long double tempo_total;

    tempo_inicio = clock();
    for (int j = 1; j <= n; j++) {
        aux = vetor[j];
        i = j-1;
        while ((i >= 0) && (vetor[i] > aux)) {
            vetor[i+1] = vetor[i];
            i = i - 1;
        }
        vetor[i+1] = aux;
    }
    tempo_fim = clock();
    tempo_total = (long double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
    
    return tempo_total;
}

long double selection_sort(long long int *vetor, int n) {
    int i, j, aux;
    time_t tempo_inicio, tempo_fim;
    long double tempo_total;

    tempo_inicio = clock();
    for (i = 0; i < n; i++) {
        aux = vetor[i];
        for (j = (i+1); j < (n-1); j++) {
            if (vetor[j] < aux) {
                aux = vetor[j];
                vetor[j] = vetor[i];
            }
        }
        vetor[i] = aux;
    }
    tempo_fim = clock();
    tempo_total = (long double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;

    return tempo_total;
}

long double comb_sort(long long int *vetor, int n) {
    int gap = n; 
    int swapped = 1;
    time_t tempo_inicio, tempo_fim;
    long double tempo_total; 

    tempo_inicio = clock();
    while (gap != 1 || swapped == 1) {
        gap = gap * 10 / 13;

        if(gap < 1)
            gap = 1;

        swapped = 0; 

        for (int i=0; i<n-gap; i++) { 
            if (vetor[i] > vetor[i+gap]) {
                int temp = vetor[i];
                vetor[i] = vetor[i+gap];
                vetor[i+gap] = temp; 
                swapped = 1; 
            } 
        } 
    } 
    tempo_fim = clock();
    tempo_total = (long double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;

    return tempo_total;
}

int main() {
    int n = 10000, i, k = 5, j;
    long double tempo_bubble = 0.0, tempo_insertion = 0.0, tempo_selection = 0.0, tempo_comb = 0.0;
    long long int vetor1[n], vetor2[n], vetor3[n], vetor4[n];

    srand(time(NULL));

    printf("n: %d\n", n);
    printf("k: %d\n", k);

    for (j = 0; j < k; j++) {
        preencherVetores(vetor1, vetor2, vetor3, vetor4, n);
        tempo_bubble += bubble_sort(vetor1, n);

        tempo_insertion += insertion_sort(vetor2, n);

        tempo_selection += selection_sort(vetor3, n);

        tempo_comb += comb_sort(vetor4, n);
    }
    printf("\n");
    printf("------------------------------------\n");
    printf("bubble: %Lf segundos\n", tempo_bubble);
    printf("insertion: %Lf segundos\n", tempo_insertion);
    printf("selection: %Lf segundos\n", tempo_selection);
    printf("comb: %Lf segundos\n", tempo_comb);
    printf("------------------------------------\n");
    
    return 0;
}