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

int main() {

    Tree t1 = create_tree(5);

    Node *node1 = create_node(6);
    Node *node2 = create_node(7);

    t1.root->left = node1;
    t1.root->right = node2;

    printf("%d\n", t1.root->num);
    printf("%d\n", t1.root->left->num);
    printf("%d\n", t1.root->right->num);

    return 0;
}