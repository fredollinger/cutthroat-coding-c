// for malloc
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int key;
    struct Node *next;
} Node;

/* linked list */
// node* list_create();
/*
node* list_insert_after(node *ptr, int key);
void list_destroy(node *head);
node* list_insert_end(node *head, int key);
void list_remove(node *head, node *ptr);
void list_remove_by_key(node *head, int key);
node* list_find_node(node *head, node *ptr);
node* list_find_by_key(node *head, int key);
*/

Node* list_create() {
    Node *head = (Node*)malloc(sizeof(Node));   
    head->key = -1;
    Node *tail = (Node*)malloc(sizeof(Node));   
    tail->key = -2;
    head->next = tail;
    tail->next = NULL;
    return head;
}

int main() {
    Node *ptr = list_create();
    printf("tail %i \n", ptr->next->key);
}
