#include <stdio.h>
#include <stdlib.h>
#include "lista_polimorfica.h"

int main() {
    List *list;
    int flag = 1;
    int option;

    init(&list);

    while(flag) {
        printf("[1] Para inserior inteiro\n");
        printf("[2] Para inserir float\n");
        printf("[3] Para inserir string\n");
        printf("[4] Para inserir caractere\n");
        printf("[5] Obter tipo por chave\n");
        printf("[6] Obter tipo inteiro por chave\n");
        printf("[7] Obter tipo flutuante por chave\n");
        printf("[8] Obter tipo string por chave\n");
        printf("[9] Obter tipo caractere por chave\n");
        printf("[10] Obter lista com todos os valores em ordem\n");
        printf("[0] Para sair\n");
        scanf("%d", &option);
        if (option == 0) {
            flag = 0;
        } else {
            send_option(option, &list);
        }
    }
    
    return 0;
}