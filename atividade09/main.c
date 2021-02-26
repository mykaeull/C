#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXNOME 100
#define MAXREGISTROS 1000

typedef struct agenda Agenda;

struct agenda {
    char nome[256];
    int matricula;
    int ddd;
    int telefone;
    char tipo;
};

char verificar_dado(char *opcao) {
    opcao[0] = tolower(opcao[0]);
    while(strlen(opcao) > 2 || (opcao[0] != 'b' && opcao[0] != 'i' && opcao[0] != 'a' && opcao[0] != 'l' && opcao[0] != 's')) {
        printf("ERROR\n");
        printf("Digite novamente uma opcao: ");
        fgets(opcao, 256, stdin);
        opcao[0] = tolower(opcao[0]);
        system("cls");
    }
    opcao[1] = '\0';
    return opcao[0];
}

void verificar_nome(char *nome) {
    while (nome[MAXNOME]) {
        memset(nome, 0, sizeof(nome));
        printf("Entre um nome com ate 100 caracteres\n");
        printf("Digite seu nome: ");
        fgets(nome, 256, stdin);
    }
}

int retornar_posicao_valida(Agenda *agenda) {
  for(int i = 0; i < 1000; i++) {
    if (agenda[i].ddd == -1) {
      return i;
    }
  }
  return -1;
}

void inserir_contato(Agenda *agenda) {
    int posicao = retornar_posicao_valida(agenda);
    if (posicao != -1) {
        memset(agenda[posicao].nome, 0, sizeof(agenda[posicao].nome));
        printf("Digite seu nome: ");
        fgets(agenda[posicao].nome, 256, stdin);
        verificar_nome(agenda[posicao].nome);
        agenda[posicao].nome[strlen(agenda[posicao].nome) - 1] = '\0';
        printf("Digite sua matricula: ");
        scanf("%d", &agenda[posicao].matricula);
        printf("Digite seu DDD: ");
        scanf("%d", &agenda[posicao].ddd);
        printf("Digite seu telefone: ");
        scanf("%d", &agenda[posicao].telefone);
        printf("Digite [c] para celular e [f] para fixo: \n");
        scanf(" %c", &agenda[posicao].tipo);
        getchar();
    } else {
		printf("a agenda esta cheia\n");
	}
    system("cls");
}

void listar_nomes(Agenda *agenda) {
    int qtd = retornar_posicao_valida(agenda);
    printf("========= LISTA =========\n");
    if (qtd == 0) {
        printf("a agenda esta vazia\n");
        printf("Digite [ENTER] para continuar ");
        getchar();
        system("cls");
    } else {
        for(int i = 0; i < qtd; i++) {
            printf("nome: %s\n", agenda[i].nome);
        }
        printf("-------------------------\n");
        printf("Digite [ENTER] para continuar ");
        getchar();
        system("cls");
    }
}

int buscar_nome(Agenda *agenda, char *nome) {
    int qtd = retornar_posicao_valida(agenda);
    for (int i = 0; i < qtd; i++) {
        if (strcmp(nome, agenda[i].nome) == 0) {
            return i;
        }
    }
    return -1;
}

void set_opcao(char *opcao, Agenda *agenda) {
    char nome[256];
    int index;
    if (opcao[0] == 'i') {
        inserir_contato(agenda);
    } else if (opcao[0] == 'l') {
        listar_nomes(agenda);
    } else if (opcao[0] == 'b') {
        printf("Digite o nome que deseja buscar: ");
        fgets(nome, 256, stdin);
        nome[strlen(nome) - 1] = '\0';
        index = buscar_nome(agenda, nome);
        if (index == -1) {
            printf("O nome buscado nao consta na agenda\n");
            printf("Digite [ENTER] para continuar ");
            getchar();
            system("cls");
        } else {
            printf("%s - (%d) %d\n", agenda[index].nome, agenda[index].ddd, agenda[index].telefone);
            printf("-------------------------\n");
            printf("Digite [ENTER] para continuar ");
            getchar();
            system("cls");
        }
    } else if (opcao[0] == 'a') {
        printf("Digite o nome para apagar o registro: ");
        fgets(nome, 256, stdin);
        nome[strlen(nome) - 1] = '\0';
        index = buscar_nome(agenda, nome);
        if (index == -1) {
            printf("O nome buscado nao consta na agenda\n");
            printf("Digite [ENTER] para continuar ");
            getchar();
            system("cls");
        } else {
            agenda[index].ddd = -1;
            printf("registro de %s apagado\n", agenda[index].nome);
            printf("-------------------------\n");
            printf("Digite [ENTER] para continuar ");
            getchar();
            system("cls");
        }
    }
}

int main(int argc, char *argv[]) {
    char opcao[256];
    int cont = 0;
    int acabou = 0;
    char value[256];
    FILE *arq;

    Agenda agenda[MAXREGISTROS];

	for(int i = 0; i < 1000; i++) {
        agenda[i].ddd = -1;
    }

    if (argc == 1) {
        while(acabou != 1) {
            printf("============ MENU ============\n");
            printf("[B] Buscar telefone pelo nome\n");
            printf("[I] Inserir novo registro\n");
            printf("[A] Apagar registro pelo nome\n");
            printf("[L] Listar nomes da agenda\n");
            printf("[S] Sair\n");
            printf("Digite uma opcao: ");
            fgets(opcao, 256, stdin);
            system("cls");
            opcao[0] = verificar_dado(opcao);
            if (opcao[0] == 's') {
                acabou = 1;
            } else {
                set_opcao(opcao, agenda);
            }
        }
    } else {
        arq = fopen(argv[1], "r");
        if (arq == NULL) {
            printf("nao foi possivel encontrar o arquivo.");
            return EXIT_FAILURE;
        }
        while(fscanf(arq, "%s", agenda[cont].nome) == 1) {
            fscanf(arq, "%d",  &agenda[cont].matricula);
            fscanf(arq, "%d",  &agenda[cont].ddd);
            fscanf(arq, "%d",  &agenda[cont].telefone);
            fscanf(arq, " %c", &agenda[cont].tipo);
            cont++;
        }

        while(acabou != 1) {
            printf("============ MENU ============\n");
            printf("[B] Buscar telefone pelo nome\n");
            printf("[I] Inserir novo registro\n");
            printf("[A] Apagar registro pelo nome\n");
            printf("[L] Listar nomes da agenda\n");
            printf("[S] Sair\n");
            printf("Digite uma opcao: ");
            fgets(opcao, 256, stdin);
            system("cls");
            opcao[0] = verificar_dado(opcao);
            if (opcao[0] == 's') {
                acabou = 1;
            } else {
                set_opcao(opcao, agenda);
            }
        }

        fclose(arq);
    }
    
    return 0;
}