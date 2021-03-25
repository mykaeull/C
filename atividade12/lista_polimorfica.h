#ifndef lista_polimorfica_h
#define lista_polimorfica_h

#include <stdio.h>
#include <stdlib.h>

typedef struct node List;

struct node {
    void *data;
    int type;
    int key;
    struct node *next;
    struct node *previous;
};

void init(List **);
void send_option(int, List **);

int insert(List **, int, List *);
int insert_int(List **, int, int);
int insert_float(List **, int, float);
int insert_string(List **, int, char *);
int insert_char(List **, int, char);

int get_type(List *, int);
int get_int(List *, int);
float get_float(List *, int);
char* get_string(List *, int);
char get_char(List *, int);

void show(List *);

#endif