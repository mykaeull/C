#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agenda Agenda;
typedef struct lista Lista;

struct lista {
    struct agenda *primeiro;
    struct agenda *ultimo;
};

struct agenda {
    char nome[256];
    int matricula;
    int ddd;
    int telefone;
    char tipo;
    struct agenda *proximo;
    struct agenda *anterior;
};

Lista criar_lista() {
    Lista lista;
    lista.primeiro = NULL;
    lista.ultimo = NULL;
    return lista;
}

Agenda* criar_registro(char *nome, int matricula, int ddd, int telefone, char tipo) {
    Agenda *registro = (Agenda*)malloc(sizeof(Agenda));
    strcpy(registro->nome, nome);
    registro->matricula = matricula;
    registro->ddd = ddd;
    registro->telefone = telefone;
    registro->tipo = tipo;
    registro->proximo = NULL;
    registro->anterior = NULL;

    return registro;
}

void inserir_registro(Lista *lista, Agenda *registro) {
    char alfabeto[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
    'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int i, j;

    if (lista->primeiro == NULL) {
        lista->primeiro = registro;
        lista->ultimo = registro;
    } else {
        for (i = 0; i < 26; i++) {
            if (registro->nome[0] == alfabeto[i]) {
                break;
            }
        }
        Agenda **aux = &lista->primeiro;
        for (j = 0; j < 26; j++) {
            if ((*aux)->nome[0] == alfabeto[j]) {
                break;
            }
        }
        while((*aux)->proximo != NULL && i > j) {
            printf("\nAQUI\n");
            aux = &(*aux)->proximo;
            for (j = 0; j < 26; j++) {
                if ((*aux)->nome[0] == alfabeto[j]) {
                    break;
                }
            }
        }
        if (i > j) {
            (*aux)->proximo = registro;
            (*aux)->proximo->anterior = (*aux);
        } else {
            registro->proximo = (*aux);
            (*aux) = registro;
            registro->proximo->anterior = (*aux);
        }
        
    }
}

void inserir_inicio(Lista *lista, Agenda *registro) {
    if (lista->primeiro == NULL) {
        lista->primeiro = registro;
        lista->ultimo = registro;
    } else {
        lista->primeiro->anterior = registro;
        registro->proximo = lista->primeiro;
        registro->anterior = NULL;
        lista->primeiro = registro;
    }
}

void inserir_fim(Lista *lista, Agenda *registro) {
    if (lista->primeiro == NULL) {
        lista->primeiro = registro;
        lista->ultimo = registro;
    } else {
        lista->ultimo->proximo = registro;
        registro->anterior = lista->ultimo;
        registro->proximo = NULL;
    }
}

void remover_registro(Lista *lista, char *nome) {
    int existe = 0;

    if (lista->primeiro == NULL) {
        printf("Lista vazia");
    } else {
        Agenda *aux = lista->primeiro;
        while (aux != NULL) {
            if (strcmp(aux->nome, nome) == 0) {
                existe = 1;
                break;
            }
            aux = aux->proximo;
        }
        if (existe) {
            if (aux->anterior == NULL) {
                lista->primeiro = aux->proximo;
                lista->primeiro->anterior = NULL;
                free(aux);
            } else {
                aux->anterior->proximo = aux->proximo;
                if (aux->proximo != NULL) {
                    aux->proximo->anterior = aux->anterior;
                }
                free(aux);
            }
        } else {
            printf("registro nao existe na lista");
        }
    }
}

void ordenar_lista(Lista *lista) {
    printf("FAZER");
}

void percorrer(Lista *lista) {
    if (lista->primeiro == NULL) {
        printf("lista vazia\n");
    } else {
        Agenda *aux = lista->primeiro;
        while (aux != NULL) {
            printf("%s\n", aux->nome);
            printf("%d\n", aux->matricula);
            printf("%d\n", aux->ddd);
            printf("%d\n", aux->telefone);
            printf("%c\n", aux->tipo);
            printf("-------------------------\n");
            aux = aux->proximo;
        }
    }
}

char verificar_entrada(char *opcao) {
    while (strlen(opcao) > 2 || (opcao[0] != 'I' && opcao[0] != 'P' && opcao[0] != 'C' && opcao[0] != 'S' && opcao[0] != 'X' && opcao[0] != 'R' && opcao[0] != 'F' && opcao[0] != 'L' && opcao[0] != 'O')) {
        printf("opcao invalida\n");
        printf("Digite uma opcao: ");
        fgets(opcao, 256, stdin);
    }
    opcao[1] = '\0';
    return opcao[0];
}

void verificar_opcao(Lista *lista, char *opcao) {
    char nome[256];
    int matricula;
    int ddd;
    int telefone;
    int tipo;
    Agenda *registro;
    FILE *arq;
    char caminho[256];
    int cont = 0;

    if (opcao[0] == 'I') {
        printf("Digite seu nome: ");
        fgets(nome, 256, stdin);
        nome[strlen(nome) - 1] = '\0';
        printf("Digite sua matricula: ");
        scanf("%d", &matricula);
        printf("Digite seu DDD: ");
        scanf("%d", &ddd);
        printf("Digite seu telefone: ");
        scanf("%d", &telefone);
        printf("Digite [c] para celular e [f] para fixo: \n");
        scanf(" %c", &tipo);
        getchar();
        registro = criar_registro(nome, matricula, ddd, telefone, tipo);
        inserir_registro(lista, registro);
    } else if (opcao[0] == 'P') {
        percorrer(lista);
    } else if (opcao[0] == 'C') {
        printf("digite o caminho:\n");
        scanf("%s", caminho);
        getchar();
        arq = fopen(caminho, "r");
        if (arq == NULL) {
            printf("nao foi possivel encontrar o arquivo.");
            exit(0);
        }
        while(fscanf(arq, "%s", &nome) == 1) {
            fscanf(arq, "%d",  &matricula);
            fscanf(arq, "%d",  &ddd);
            fscanf(arq, "%d",  &telefone);
            fscanf(arq, " %c", &tipo);
            registro = criar_registro(nome, matricula, ddd, telefone, tipo);
            inserir_registro(lista, registro);
            cont++;
        }
        fclose(arq);
    } else if (opcao[0] == 'S') {
        printf("digite o caminho: \n");
        scanf("%s", caminho);
        getchar();
        arq = fopen(caminho, "w");
        if (lista->primeiro == NULL) {
            printf("nao foi possivel copiar os dados pois estes nao existem");
        } else {
            Agenda *aux = lista->primeiro;
            while (aux != NULL) {
                fprintf(arq, "%s\n", aux->nome);
                fprintf(arq, "%d\n", aux->matricula);
                fprintf(arq, "%d\n", aux->ddd);
                fprintf(arq, "%d\n", aux->telefone);
                fprintf(arq, "%c\n", aux->tipo);
                aux = aux->proximo;
            }
            fclose(arq);
        }
    } else if (opcao[0] == 'R') {
        printf("digite o nome que deseja remover da lista: ");
        fgets(nome, 256, stdin);
        nome[strlen(nome) - 1] = '\0';
        remover_registro(lista, nome);
    } else if (opcao[0] == 'F') {
        printf("Digite seu nome: ");
        fgets(nome, 256, stdin);
        nome[strlen(nome) - 1] = '\0';
        printf("Digite sua matricula: ");
        scanf("%d", &matricula);
        printf("Digite seu DDD: ");
        scanf("%d", &ddd);
        printf("Digite seu telefone: ");
        scanf("%d", &telefone);
        printf("Digite [c] para celular e [f] para fixo: \n");
        scanf(" %c", &tipo);
        getchar();
        registro = criar_registro(nome, matricula, ddd, telefone, tipo);
        inserir_inicio(lista, registro);
    } else if (opcao[0] == 'L') {
        printf("Digite seu nome: ");
        fgets(nome, 256, stdin);
        nome[strlen(nome) - 1] = '\0';
        printf("Digite sua matricula: ");
        scanf("%d", &matricula);
        printf("Digite seu DDD: ");
        scanf("%d", &ddd);
        printf("Digite seu telefone: ");
        scanf("%d", &telefone);
        printf("Digite [c] para celular e [f] para fixo: \n");
        scanf(" %c", &tipo);
        getchar();
        registro = criar_registro(nome, matricula, ddd, telefone, tipo);
        inserir_fim(lista, registro);
    } else if (opcao[0] == 'O') {
        ordenar_lista(lista);
    }
}

int main() {
    int acabou = 0;
    char opcao[256];
    Lista lista;

    lista = criar_lista();
    while(acabou == 0) {
        printf("============ MENU ============\n");
        printf("[I] Inserir registro\n");
        printf("[P] Percorrer lista\n");
        printf("[C] Carregar\n");
        printf("[S] Salvar\n");
        printf("[R] Remover\n");
        printf("[F] Inserir no inicio\n");
        printf("[L] Inserir no final\n");
        printf("[O] Ordenar lista\n");
        printf("[X] Sair\n");
        printf("Digite uma opcao: ");
        fgets(opcao, 256, stdin);
        opcao[0] = verificar_entrada(opcao);
        if (opcao[0] == 'X') {
            acabou = 1;
        } else {
            verificar_opcao(&lista, opcao);
        }
    }

    return 0;
}