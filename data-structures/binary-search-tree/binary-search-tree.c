#include <stdlib.h>  // malloc
#include <stdio.h>   // printf

int test_int = 4;

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
} node;

// Note that it is not a generic inorder successor
// function. It mainly works when the right child
// is not empty, which is  the case we need in
// BST delete.
struct node* get_successor(node* curr, node* z) {
    curr = curr->right;
    while (curr != z && curr->left != z) {
        curr = curr->left;
    }
    return curr;
}

void tree_delete(node *head, node *z, int key) {
    node *ptr = head->right;
    node *prev = head;
    while (ptr->key != key && ptr != z) {
        prev = ptr;
        // higher is on the right
        if (ptr->key < key) {
            ptr = ptr->right;
        }
        // lower keys go to the left
        else if (ptr->key > key) {
            ptr = ptr->left;
        }
        else {
            printf("tree_delete() we should never get here \n");
            exit(-1);
        }
    }

    // Handle all the cases to delete
    // 0 1, 2 children

    // 0 children
    // delete the pointer
    if (ptr->left == z && ptr->right == z) {
        printf("tree_delete: %i no children \n ", ptr->key);
        if (prev->left == ptr) {
            prev->left = z;
        }
        else if (prev->right == ptr) {
            prev->right = z;
        }
        else {
            printf("Neither prev->right nor prev->left point to ptr. Bug!! \n");
        }

        free(ptr);
    }
    // 1 child right
    else if (ptr->left == z && ptr->right != z) {
        printf("tree_delete: %i 1 child right %i \n", ptr->key, ptr->right->key);
        prev->right = ptr->right;
        free(ptr);
    }
    // 1 child left
    else if (ptr->left != z && ptr->right == z) {
        printf("tree_delete: %i 1 child left %i \n", ptr->key, ptr->left->key);
        prev->left = ptr->left;
        free(ptr);
    }
    // 2 children
    else if (ptr->left != z && ptr->right != z) {
        printf("tree_delete(): %i 2 children left: %i right: %i \n", ptr->key, ptr->left->key, ptr->right->key);
        // find the node to replace the node we want to delete
        node *succ = get_successor(ptr, z);
        // swap the nodes
        succ->left = ptr->left;
        prev->left = succ;
        // prev->key = succ->key;
        // ptr->right = prev;
        // free(succ);
        printf("tree_delete(): succeessor %i \n", succ->key);
    }
 
    return;
}

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

void tree_print(node *head, node *z) {
    if (head == z || head == NULL) {
        return;
    }
    // In-order traversal: left, current, right
    tree_print(head->left, z);
    printf("key: %i \n", head->key);
    tree_print(head->right, z);
}

node* tree_search(node *head, node *z, int key) {
    node *ptr = head->right;
    while (ptr != z) {
        // lower keys go to the left
        if (key < ptr->key) {
            ptr = ptr->left;
        }
        else if (key > ptr->key) {
            ptr = ptr->right;
        }
        else if (key == ptr->key) {
            return ptr;
        }
    }
    return z;
}

int main() {
    node *head, *z;
    tree_initialize(&head, &z);

    tree_insert(&head, &z, 2);
    tree_insert(&head, &z, 1);
    tree_insert(&head, &z, 7);
    tree_insert(&head, &z, 4);
    tree_insert(&head, &z, 3);
    tree_insert(&head, &z, 6);
    tree_insert(&head, &z, 5);

    node *res = tree_search(head, z, test_int);

    if (z != res) {
        printf("test_int result is %i \n", res->key);
    }
    else {
        printf("Can't find test_int. \n");
    }

    printf("test_int is %i \n", test_int);

    tree_delete(head, z, test_int);
    // tree_delete(head, z, 71);
    // tree_delete(head, z, 70);

    res = tree_search(head, z, test_int);
    if (z != res) {
        printf("test_int result is %i \n", res->key);
    }
    else {
        printf("Can't find test_int. \n");
    }
    tree_print(head, z);
    return 0;
}
