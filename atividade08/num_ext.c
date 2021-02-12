#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char *arr[901]; // global

void preencher_arr() {
    arr[1] = "um";
	arr[2] = "dois";
	arr[3] = "tres";
	arr[4] = "quatro";
	arr[5] = "cinco";
	arr[6] = "seis";
	arr[7] = "sete";
	arr[8] = "oito";
	arr[9] = "nove";
	arr[10] = "dez";
	arr[11] = "onze";
	arr[12] = "doze";
	arr[13] = "treze";
	arr[14] = "catorze";
	arr[15] = "quinze";
	arr[16] = "dezesseis";
	arr[17] = "dezessete";
	arr[18] = "dezoito";
	arr[19] = "dezenove";
	arr[20] = "vinte";
	arr[30] = "trinta";
	arr[40] = "quarenta";
	arr[50] = "cinquenta";
	arr[60] = "sessenta";
	arr[70] = "setenta";
	arr[80] = "oitenta";
	arr[90] = "noventa";
	arr[0] = "cem";
	arr[100] = "cento";
	arr[200] = "duzentos";
	arr[300] = "trezentos";
	arr[400] = "quatrocentos";
	arr[500] = "quinhentos";
	arr[600] = "seicentos";
	arr[700] = "setecentos";
	arr[800] = "oitocentos";
	arr[900] = "novecentos";
}

int str_tamanho(char *s) {
    int tam = 0;
    while(s[tam]) {
        tam ++;
    }
    return tam;
}

void str_copia(char *s, char *d) {
    int i = 0;
    while(s[i] != '\0') { 
        d[i] = s[i]; 
        i++;
    }
    d[i] = '\0';
}

void str_concatena(char *s, char *d) {
    int i = 0, j = 0;
    while(d[i] != '\0') {
        i++; 
    }
    while(s[j] != '\0') { 
        d[i] = s[j]; 
        i++;
        j++;
    }
    d[i] = '\0';
}

char* num_ext(int n) {
    int num_dig = floor(log10(n)) + 1;
    char *concat = (char*)malloc(sizeof(char)*100);
    int unidade, dezena, centena;
    
    if (n == 0) {
        printf("-1");
    } else {
        if (num_dig == 1) {
            sprintf(concat, arr[n]);
        } else if (num_dig == 2) {
            if (n > 9 && n < 20) {
                sprintf(concat, arr[n]);
            } else {
                unidade = n % 10;
                dezena = n - unidade;
                if (unidade == 0){
                    sprintf(concat, arr[dezena]);
                } else {
                    sprintf(concat, "%s %s %s", arr[dezena], "e", arr[unidade]);
                }
            }
        } else {
            if (n == 100) {
                sprintf(concat, arr[0]);
            } else {                       
                centena = (n / 100) * 100; 
                unidade = n % 10;          
                dezena = (n - centena) - unidade; 
                if (unidade == 0) {
                    sprintf(concat, "%s %s %s", arr[centena], "e", arr[dezena]);
                } else if (dezena == 10) {
                    sprintf(concat, "%s %s %s", arr[centena], "e", arr[dezena+unidade]);
                } else {
                    sprintf(concat, "%s %s %s %s %s", arr[centena], "e", arr[dezena], "e", arr[unidade]);
                }
            }
        }
    }
    return concat;
}

int main(int argc, char *argv[]) {
    int n, x, primeiro = 0;
    char *c;
    char numextenso[1024];
    int tam;

    preencher_arr();

    if (argc == 1) {
        printf("entre um numero entre 1 e 999: ");
        scanf("%d", &n);

        c = num_ext(n);
        tam = str_tamanho(c);
        str_copia(c, numextenso);
        printf("%s\n", numextenso);
        printf("tamanho da string: %d", tam);

        // printf("\ntamanho da string: %d", tam);
    } else {
        FILE *arq;
        char num[1000];
        arq = fopen(argv[1], "r");
        if (arq == NULL) {
            printf("nao foi possivel encontrar o arquivo.");
            return EXIT_FAILURE;
        }
        while(fgets(num, 5, arq) != NULL) {
            x = atoi(num); 
            c = num_ext(x); 
            printf("%d\n", x);

            if (primeiro == 0) {
                str_copia(c, numextenso);
                printf("%s\n", c);
                printf("tamanho da string: %d\n", str_tamanho(c));
                printf("strings concatenadas: %s\n", numextenso);
            } else {
                printf("%s\n", c);
                printf("tamanho da string: %d\n", str_tamanho(c));
                str_concatena("| ", numextenso);
                str_concatena(c, numextenso);
                printf("strings concatenadas: %s\n", numextenso);
            }
            primeiro = 1;
            printf("\n");
        }
        fclose(arq);
    }

    return 0;
}