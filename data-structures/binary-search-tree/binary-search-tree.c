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
        else if (key > ptr->key) {
            ptr = ptr->right;
        }
        // if the keys are equal, don't insert it by definition of BST
        else if (key == ptr->key) {
            printf("keys are equal %i == %i \n", key, ptr->key);
            return;
        }
        else {
            printf("we should never get here key: %i, ptr->key: %i \n", key, ptr->key);
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

// Got through all the keys and print them out
void tree_print(node **head, node **z) {
    node *ptr = *head;
    // While we are not at the end
    if (ptr == *z) {
        return;
    }
    printf("key: %i \n", ptr->key);
    tree_print(&(ptr->right), z);
    tree_print(&(ptr->left), z);
}

int main() {
    node *head, *z;
    tree_initialize(&head, &z);
    tree_insert(&head, &z, 1);
    tree_insert(&head, &z, 10);
    tree_insert(&head, &z, 14);
    tree_insert(&head, &z, 3);
    tree_insert(&head, &z, 2);
    tree_insert(&head, &z, 8);
    tree_insert(&head, &z, 50);
    tree_insert(&head, &z, 101);
    tree_insert(&head, &z, 71);
    tree_insert(&head, &z, 30);
    tree_insert(&head, &z, 22);
    tree_print(&head, &z);
    return 0;
}
