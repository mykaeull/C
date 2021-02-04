#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct tree Tree;

struct node {
    int num;
    struct node *left;
    struct node *right;
};

struct tree {
    struct node *root;
};

Tree create_tree(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node)); 
    new_node->num = data;
    new_node->left = NULL;
    new_node->right = NULL;
    Tree t;
    t.root = new_node;
    return t;
}

Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node)); 
    new_node->num = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void add_left(Tree *t, int data) {
    Node *new_node = create_node(data);
    Node *aux = t->root;
    if (aux->left == NULL) {
        aux->left = new_node;
    } else {
        while(aux->left != NULL) {
            aux = aux->left;
        }
        aux->left = new_node;
    }
}

void add_rigth(Tree *t, int data) {
    Node *new_node = create_node(data);
    Node *aux = t->root;
    if (aux->right == NULL) {
        aux->right = new_node;
    } else {
        while(aux->right != NULL) {
            aux = aux->right;
        }
        aux->right = new_node;
    }
}

void show_left_elements(Tree *t) {
    Node *aux = t->root;
    printf("left elements: ");
    while(aux != NULL) {
        printf("%d ", aux->num);
        aux = aux->left;
    }
    printf("\n");
}

void show_right_elements(Tree *t) {
    Node *aux = t->root;
    printf("rigth elements: ");
    while(aux != NULL) {
        printf("%d ", aux->num);
        aux = aux->right;
    }
    printf("\n");
}

void pos_ordem(Tree *t, Node *node) {
    if (node == NULL) {
        node = t->root;
    }
    if (node->left != NULL) {
        pos_ordem(t, node->left);
    }
    if (node->right != NULL) {
        pos_ordem(t, node->right);
    }
    printf("%d ", node->num);
}

void pre_ordem(Tree *t, Node *node) {
    if (node == NULL) {
        node = t->root;
    }
    printf("%d ", node->num);
    if (node->left != NULL) {
        pre_ordem(t, node->left);
    }
    if (node->right != NULL) {
        pre_ordem(t, node->right);
    }
}

void em_ordem(Tree *t, Node *node) {
    if (node == NULL) {
        node = t->root;
    }
    if (node->left != NULL) {
        em_ordem(t, node->left);
    }
    printf("%d ", node->num);
    if (node->right != NULL) {
        em_ordem(t, node->right);
    }
}

int height(Tree *t, Node *node) {
    if (node == NULL) {
        node = t->root;
    }
    int hleft = 0;
    int hright = 0;
    if (node->left != NULL) {
        hleft = height(t, node->left);
    }
    if (node->right != NULL) {
        hright = height(t, node->right);
    }
    if (hleft > hright) {
        return hleft + 1;
    } else {
        return hright + 1;
    }
}

int main() {

    Tree t1 = create_tree(5);

    Node *node1 = create_node(6);
    Node *node2 = create_node(7);

    t1.root->left = node1;
    t1.root->right = node2;

    add_left(&t1, 9);
    add_rigth(&t1, 8);

    show_left_elements(&t1);
    show_right_elements(&t1);

    pos_ordem(&t1, NULL);
    printf("\n");
    pre_ordem(&t1, node1);
    printf("\n");
    em_ordem(&t1, NULL);
    printf("\n");
    printf("altura: %d", height(&t1, NULL));
    printf("\n");
    printf("altura: %d", height(&t1, node1));

    return 0;
}