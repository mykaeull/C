#include "cadeia.h"
#include <stdlib.h>

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