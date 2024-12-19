#include <stdlib.h>  // malloc
#include <stdio.h>   // printf

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
} node;

void tree_initialize(node **head, node **z) {
    *head = malloc(sizeof(node));
    *z = malloc(sizeof(node));
    (*z)->left = *z;
    (*z)->right = *z;
    (*head)->left = *z;
    (*head)->right = *z;
    (*head)->key = 0;
    return;
}

void tree_insert(node **head, node **z, int key) {
    node *prev = *head;
    node *ptr = (*head)->right;
    // While we are not at the end
    while (ptr != *z) {
        prev = ptr;
        // lower keys go to the left
        if (key < ptr->key) {
            ptr = ptr->left;
        }
        // larger keys go to the right
        else if (key < ptr->key) {
            ptr = ptr->right;
        }
        // if the keys are equal, don't insert it by definition of BST
        else {
            printf("keys are equal %i == %i", key, ptr->key);
            return;
        }
    }
    node *neu = malloc(sizeof(node));
    neu->key = key;
    neu->left = *z;
    neu->right = *z;
    // lower keys go to the left
    if (key < prev->key) {
        prev->left = neu;
    }
    // higher keys go to the right
    else {
        prev->right = neu;
    }
}

int main() {
    node *head, *z;
    tree_initialize(&head, &z);
    tree_insert(&head, &z, 1);
    return 0;
}
