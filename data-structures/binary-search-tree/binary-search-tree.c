#include <stdlib.h>  // malloc
// #include <stdio.h>

typedef struct node {
  int key, info;
  struct node *left;
  struct node *right;
} node;

void tree_initialize(node *head, node *z) {
    head = (node*)malloc(sizeof(node));
    z = (node*)malloc(sizeof(node));
    z->left = z;
    z->right = z;
    z->info = -1;
    head->left = z;
    head->key = 0;
    return;
}

int main() {
    node *head, *z;
    tree_initialize(head, z);
    return 0;
}
