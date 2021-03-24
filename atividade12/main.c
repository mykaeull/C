#include <stdio.h>
#include <stdlib.h>

#define T_INT 0
#define T_FLOAT 1
#define T_STR 2

typedef struct node List;

union data {
    int i;
    float f;
    char str[20];
};

struct node {
    union data data;
    int type;
    int key;
    struct node *next;
    struct node *previous;
};

int inserir(List **list, int key, List *node) {
    if (*list == NULL) {
        (*(node)).next = node;
        (*(node)).previous = node;
        *list = node;
        return 1;
    } else {
        if ((*(list))->key >= key) {
            if ((*(list))->key == key) {
                free(node);
                return 0;
            }
            (*(node)).previous = (*(list))->previous;
            (*(node)).next = *list;
            (*(list))->previous->next = node;
            (*(list))->previous = node;
            *list = node;
            return 1;
        }
        List *aux = *list;
        while ((*(aux)).next->key < key) {
            aux = aux->next;
            if ((*(aux)).next->key == key) {
                free(node);
                return 0;
            }
            (*(node)).next = (*(aux)).next;
            (*(node)).previous = aux;
            (*(node)).next->previous = node;
            (*(aux)).next = node;
            return 1;
        }
    }
}

int inserir_inteiro(List **list, int key, int value) {
    int res;
    List *node = (List*)malloc(sizeof(List));
    (*(node)).data.i = value;
    (*(node)).type = T_INT;
    (*(node)).key = key;

    res = inserir(list, key, node);
    return res;
}

/*void show(List **list) {
    List *aux = *list;
    int flag = 1;
    printf("---------------\n");
    //printf("%d\n", (*(aux)).key);
    //printf("---------------\n");
    while (flag) {
        printf("%d\n", (*(aux)).key);
        if ((*(aux)).next == aux) {
            flag = 0;
        } else if ((*(aux)).next == *list) {
            flag = 0;
        }
        aux = (*(aux)).next;
    }
}*/

int obter_tipo(List *list, int key) {
    int flag = 1;

    if (list == NULL) {
        return 0;
    }
    List *aux = list;
    while (flag) {
        if ((*(aux)).key == key) {
            flag = 0;
            return (*(aux)).type;
        } else if ((*(aux)).next == list) {
            flag = 0;
            return -1;
        }
        
        aux = aux->next;
    }

}

void send_option(int option, List **list) {
    int res;
    int key;
    int value;

    if (option == 1) {
        printf("-----------------------\n");
        printf("digite a chave: ");
        scanf("%d", &key);
        printf("digite o valor: ");
        scanf("%d", &value);
        printf("-----------------------\n");
        res = inserir_inteiro(list, key, value);
        if (res) {
            printf("-----------------------\n");
            printf("inserido com sucesso\n");
            printf("-----------------------\n");
        } else {
            printf("-----------------------\n");
            printf("erro ao inserir\n");
            printf("-----------------------\n");
        }
    } else if (option == 2) {
        printf("-----------------------\n");
        printf("digite a chave: ");
        scanf("%d", &key);
        printf("-----------------------\n");
        res = obter_tipo(*list, key);
        if (res == -1) {
            printf("-----------------------\n");
            printf("chave nao existe\n");
            printf("-----------------------\n");
        } else if (res == 0) {
            printf("-----------------------\n");
            printf("inteiro\n");
            printf("-----------------------\n");
        }
    }

    //show(list);
}

void init(List **list) {
    *list = NULL;
}

int main() {
    List *list;
    int flag = 1;
    int option;

    init(&list);

    while(flag) {
        printf("[1] Para inserior inteiro\n");
        printf("[2] Para obter tipo\n");
        scanf("%d", &option);
        send_option(option, &list);
    }
    

    return 0;
}