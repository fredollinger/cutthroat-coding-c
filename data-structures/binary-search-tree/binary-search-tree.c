#include <stdlib.h>  // malloc
// #include <stdio.h>

typedef struct node {
  int key, info;
  struct node *left;
  struct node *right;
} node;

node* tree_initialize() {
    node *head = (node*)malloc(sizeof(node));
    node *z = (node*)malloc(sizeof(node));
    z->left = z;
    z->right = z;
    z->info = -1;
    head->left = z;
    head->key = 0;
    return head;
}

int main() {
    node *head = tree_initialize();
    return 0;
}
