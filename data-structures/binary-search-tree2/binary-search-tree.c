#include <stdlib.h>  // malloc
#include <stdio.h>   // printf

// A binary search tree is a rooted binary tree in which nodes are arranged in
// strict total order in which the nodes with keys greater than any particular
// node A is stored on the right sub-trees to that node A and the nodes with
// keys equal to or less than A are stored on the left sub-trees to A,
// satisfying the binary search property.


typedef struct node {
  int key;
  struct node *left;
  struct node *right;
} node;

void tree_initialize(node **head, node **end) {
    *head = malloc(sizeof(node));
    *end = malloc(sizeof(node));
    (*head)->key = -1;
    (*head)->left = *end;
    (*head)->right = *end;
    (*end)->left = NULL;
    (*end)->right = NULL;
    (*end)->key = -1;
}

void tree_insert(node **head, node **end, int key) {
    node *prev = *head;
    node *ptr = (*head)->right;
    // While we are not at the end
    while (ptr != *end) {
        if (key > ptr->key) {
            printf("right \n");
            ptr = ptr->right;
        }
        else {
            printf("left \n");
            ptr = ptr->left;
        } 
        prev = ptr;
    }
    node *neu = malloc(sizeof(neu));
    neu->key = key;
    neu->left = *end;
    neu->right = *end;
    if (key > prev->key) {
        prev->right = neu;
    }
    else {
        prev->left = neu;
    }
}

void tree_print(node *head, node *z) {
    if (head == z || head == NULL) {
        return;
    }
    // In-order traversal: left, current, right
    tree_print(head->left, z);
    printf("key: %i \n", head->key);
    tree_print(head->right, z);
}

node* tree_search(node *head, node *end, int key) {
}

void tree_delete(node *head, node *end, int key) {
    return;
}

int main() {
    node *head, *end; 
    tree_initialize(&head, &end);
    printf("head->key [%i] \n", head->key);
    tree_insert(&head, &end, 10);
    // printf("head->right [%i] \n", head->right->key);
    // printf("head->left [%i] \n", head->left->key);
    tree_print(head, end);
    return 0;
}
