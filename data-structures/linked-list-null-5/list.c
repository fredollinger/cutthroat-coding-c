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

Node* linked_list_create() {
    Node *head = (Node*)malloc(sizeof(Node));   
    head->key = -1;
    Node *tail = (Node*)malloc(sizeof(Node));   
    tail->key = -2;
    head->next = tail;
    tail->next = NULL;
    return head;
}

Node* linked_list_insert_after(Node *ptr, int key) {
    Node *neu = (Node*)malloc(sizeof(Node));   
    neu->key = key;
    neu->next = ptr->next;
    ptr->next = neu;
    return neu;
}

void print_linked_list(Node *ll) {
    Node *ptr = ll->next;

    while (NULL != ptr->next) {
        printf("key [%i] \n", ptr->key);
        ptr = ptr->next;
    }
}

int main() {
    Node *head = linked_list_create();
    Node *ll = head;

    ll = linked_list_insert_after(ll, 6);
    ll = linked_list_insert_after(ll, 5);
    ll = linked_list_insert_after(ll, 4);
    ll = linked_list_insert_after(ll, 3);
    ll = linked_list_insert_after(ll, 2);
    ll = linked_list_insert_after(ll, 1);

    print_linked_list(head);

   return 0;
}
