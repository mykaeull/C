#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_polimorfica.h"

#define T_INT 0
#define T_FLOAT 1
#define T_STR 2
#define T_CHAR 3

int insert(List **list, int key, List *node) {
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

int insert_int(List **list, int key, int value) {
    int res;
    List *node; 
    node = (List*)malloc(sizeof(List));
    if (!node) {
        return 0;
    }
    (*(node)).data = malloc(sizeof(int));
    if (!(*(node)).data) {
        free(node);
        return 0;
    }
    *((int*)(*(node)).data) = value;
    (*(node)).type = T_INT;
    (*(node)).key = key;

    res = insert(list, key, node);
    return res;
}

int insert_float(List **list, int key, float value) {
    int res;
    List *node; 
    node = (List*)malloc(sizeof(List));
    if (!node) {
        return 0;
    }
    (*(node)).data = malloc(sizeof(float));
    if (!(*(node)).data) {
        free(node);
        return 0;
    }
    *((float*)(*(node)).data) = value;
    (*(node)).type = T_FLOAT;
    (*(node)).key = key;

    res = insert(list, key, node);
    return res;
}

int insert_string(List **list, int key, char *value) {
    int res;
    List *node; 
    node = (List*)malloc(sizeof(List));
    if (!node) {
        return 0;
    }
    (*(node)).data = malloc(sizeof(char)*strlen(value));
    if (!(*(node)).data) {
        free(node);
        return 0;
    }
    strcpy((char *)(*(node)).data, value);
    (*(node)).type = T_STR;
    (*(node)).key = key;

    res = insert(list, key, node);
    return res;
}

int insert_char(List **list, int key, char value) {
    int res;
    List *node;
    node = (List*)malloc(sizeof(List));
    if (!node) {
        return 0;
    }
    (*(node)).data = malloc(sizeof(char));
    if (!(*(node)).data) {
        free(node);
        return 0;
    }
    *((char*)(*(node)).data) = value;
    (*(node)).type = T_CHAR;
    (*(node)).key = key;

    res = insert(list, key, node);
    return res;
}

void show(List *list) {
    List *aux = list;
    int flag = 1;

    printf("---------------\n");
    printf("%d\n", (*(aux)).key);
    printf("---------------\n");
    while (flag) {
        printf("%d\n", (*(aux)).key);
        if ((*(aux)).type == T_INT) {
            printf("%d\n", *((int*)(*(aux)).data));
        } else if ((*(aux)).type == T_FLOAT) {
            printf("%f\n", *((float*)(*(aux)).data));
        } else if ((*(aux)).type == T_STR) {
            printf("%s\n", (char *)(*(aux)).data);
        } else if ((*(aux)).type == T_CHAR) {
            printf("%c\n", *((char*)(*(aux)).data));
        }
        if ((*(aux)).next == aux) {
            flag = 0;
        } else if ((*(aux)).next == list) {
            flag = 0;
        }
        aux = aux->next;
    }
}

int get_type(List *list, int key) {
    int flag = 1;

    if (list == NULL) {
        return -1;
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

int get_int(List *list, int key) {
    int flag = 1;

    if (list == NULL) {
        return -1;
    }
    List *aux = list;
    while (flag) {
        if ((*(aux)).key == key) {
            flag = 0;
            if ((*(aux)).type == T_INT) {
                return *((int*)(*(aux)).data);
            } else {
                return 0;
            }
        } else if ((*(aux)).next == list) {
            flag = 0;
            return -1;
        }
        
        aux = aux->next;
    }
}

float get_float(List *list, int key) {
    int flag = 1;

    if (list == NULL) {
        return -1.0;
    }
    List *aux = list;
    while (flag) {
        if ((*(aux)).key == key) {
            flag = 0;
            if ((*(aux)).type == T_FLOAT) {
                return *((float*)(*(aux)).data);
            } else {
                return 0.0;
            }
        } else if ((*(aux)).next == list) {
            flag = 0;
            return -1.0;
        }
        
        aux = aux->next;
    }
}

char* get_string(List *list, int key) {
    int flag = 1;

    if (list == NULL) {
        return NULL;
    }
    List *aux = list;
    while (flag) {
        if ((*(aux)).key == key) {
            flag = 0;
            if ((*(aux)).type == T_STR) {
                return (char *)(*(aux)).data;
            } else {
                return "erro";
            }
        } else if ((*(aux)).next == list) {
            flag = 0;
            return NULL;
        }
        
        aux = aux->next;
    }
}

char get_char(List *list, int key) {
    int flag = 1;

    if (list == NULL) {
        return '\0';
    }
    List *aux = list;
    while (flag) {
        if ((*(aux)).key == key) {
            flag = 0;
            if ((*(aux)).type == T_CHAR) {
                return *((char*)(*(aux)).data);
            } else {
                return 'e';
            }
        } else if ((*(aux)).next == list) {
            flag = 0;
            return '\0';
        }
        
        aux = aux->next;
    }
}

void send_option(int option, List **list) {
    int res;
    int key;
    int inteiro;
    float flutuante;
    char str[256];
    char *string;
    char caractere;

    if (option == 1) {
        printf("-----------------------\n");
        printf("digite a chave: ");
        scanf("%d", &key);
        printf("digite o valor: ");
        scanf("%d", &inteiro);
        printf("-----------------------\n");
        res = insert_int(list, key, inteiro);
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
        printf("digite o valor: ");
        scanf("%f", &flutuante);
        printf("-----------------------\n");
        res = insert_float(list, key, flutuante);
        if (res) {
            printf("-----------------------\n");
            printf("inserido com sucesso\n");
            printf("-----------------------\n");
        } else {
            printf("-----------------------\n");
            printf("erro ao inserir\n");
            printf("-----------------------\n");
        }
    } else if (option == 3) {
        printf("-----------------------\n");
        printf("digite a chave: ");
        scanf("%d", &key);
        printf("digite o valor: ");
        scanf("%s", &str);
        printf("-----------------------\n");
        res = insert_string(list, key, str);
        if (res) {
            printf("-----------------------\n");
            printf("inserido com sucesso\n");
            printf("-----------------------\n");
        } else {
            printf("-----------------------\n");
            printf("erro ao inserir\n");
            printf("-----------------------\n");
        }
    } else if (option == 4) {
        printf("-----------------------\n");
        printf("digite a chave: ");
        scanf("%d", &key);
        printf("digite o valor: ");
        scanf(" %c", &caractere);
        getchar();
        printf("-----------------------\n");
        res = insert_char(list, key, caractere);
        if (res) {
            printf("-----------------------\n");
            printf("inserido com sucesso\n");
            printf("-----------------------\n");
        } else {
            printf("-----------------------\n");
            printf("erro ao inserir\n");
            printf("-----------------------\n");
        }
    } else if (option == 5) {
        printf("-----------------------\n");
        printf("digite a chave: ");
        scanf("%d", &key);
        printf("-----------------------\n");
        res = get_type(*list, key);
        if (res == -1) {
            printf("-----------------------\n");
            printf("chave nao existe\n");
            printf("-----------------------\n");
        } else if (res == 0) {
            printf("-----------------------\n");
            printf("inteiro\n");
            printf("-----------------------\n");
        } else if (res == 1) {
            printf("-----------------------\n");
            printf("flutuante\n");
            printf("-----------------------\n");
        } else if (res == 2) {
            printf("-----------------------\n");
            printf("string\n");
            printf("-----------------------\n");
        } else if (res == 3) {
            printf("-----------------------\n");
            printf("caractere\n");
            printf("-----------------------\n");
        }
    } else if (option == 6) {
        printf("-----------------------\n");
        printf("digite a chave: ");
        scanf("%d", &key);
        printf("-----------------------\n");
        inteiro = get_int(*list, key);
        if (inteiro == -1) {
            printf("-----------------------\n");
            printf("chave nao existe\n");
            printf("-----------------------\n");
        } else if (inteiro == 0) {
            printf("-----------------------\n");
            printf("o tipo referente a chave nao eh um inteiro\n");
            printf("-----------------------\n");
        } else {
            printf("-----------------------\n");
            printf("%d\n", inteiro);
            printf("-----------------------\n");
        }
    } else if (option == 7) {
        printf("-----------------------\n");
        printf("digite a chave: ");
        scanf("%d", &key);
        printf("-----------------------\n");
        flutuante = get_float(*list, key);
        if (flutuante == -1.0) {
            printf("-----------------------\n");
            printf("chave nao existe\n");
            printf("-----------------------\n");
        } else if (flutuante == 0.0) {
            printf("-----------------------\n");
            printf("o tipo referente a chave nao eh um flutuante\n");
            printf("-----------------------\n");
        } else {
            printf("-----------------------\n");
            printf("%f\n", flutuante);
            printf("-----------------------\n");
        }
    } else if (option == 8) {
        printf("-----------------------\n");
        printf("digite a chave: ");
        scanf("%d", &key);
        printf("-----------------------\n");
        string = get_string(*list, key);
        if (string == NULL) {
            printf("-----------------------\n");
            printf("chave nao existe\n");
            printf("-----------------------\n");
        } else if (strcmp(string, "erro") == 0) {
            printf("-----------------------\n");
            printf("o tipo referente a chave nao eh um string\n");
            printf("-----------------------\n");
        } else {
            printf("-----------------------\n");
            printf("%s\n", string);
            printf("-----------------------\n");
        }
    } else if (option == 9) {
        printf("-----------------------\n");
        printf("digite a chave: ");
        scanf("%d", &key);
        printf("-----------------------\n");
        caractere = get_char(*list, key);
        if (caractere == '\0') {
            printf("-----------------------\n");
            printf("chave nao existe\n");
            printf("-----------------------\n");
        } else if (caractere == 'e') {
            printf("-----------------------\n");
            printf("o tipo referente a chave nao eh um caractere\n");
            printf("-----------------------\n");
        } else {
            printf("-----------------------\n");
            printf("%c\n", caractere);
            printf("-----------------------\n");
        }
    } else if (option == 10) {
        show(*list);
    } else {
        printf("-----------------------\n");
        printf("entre com um valor valido\n");
        printf("-----------------------\n");
    }

}

void init(List **list) {
    *list = NULL;
}