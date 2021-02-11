#include <stdio.h>
#include <string.h>
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

char* num_ext(int n) {
    int num_dig = floor(log10(n)) + 1;
    char *concat = (char*)malloc(sizeof(char)*100);
    int unidade, dezena, centena;
    
    if (num_dig == 1) {
        sprintf(concat, arr[n]);
        printf("%s", concat);
    } else if (num_dig == 2) {
        if (n > 9 && n < 20) {
            sprintf(concat, arr[n]);
            printf("%s", concat);
        } else {
            unidade = n % 10;
            dezena = n - unidade;
            sprintf(concat, "%s %s %s", arr[dezena], "e", arr[unidade]);
            printf("%s", concat);
            printf("\n%d", strlen(concat));
        }
    } else {
        if (n == 100) {
            sprintf(concat, arr[0]);
            printf("%s", concat);
        } else {                       // 113
            centena = (n / 100) * 100; // 100
            unidade = n % 10;          // 2
            dezena = (n - centena) - unidade; // 10
            if (unidade == 0) {
                sprintf(concat, "%s %s %s", arr[centena], "e", arr[dezena]);
                printf("%s", concat);
            } else if (dezena == 10) {
                sprintf(concat, "%s %s %s", arr[centena], "e", arr[dezena+unidade]);
                printf("%s", concat);
            } else {
                sprintf(concat, "%s %s %s %s %s", arr[centena], "e", arr[dezena], "e", arr[unidade]);
                printf("%s", concat);
            }
        }
    }
    return concat;
}

int main() {
    int n;
    int t = 0;
    char *c;
    scanf("%d", &n);
    preencher_arr();

    c = num_ext(n);

    while (c[t]) {
        t++;
    }
    printf("\n%d", t);

    return 0;
}