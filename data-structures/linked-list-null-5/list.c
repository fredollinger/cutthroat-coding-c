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

void linked_list_print(Node *ll) {
    Node *ptr = ll->next;

    printf("linked_list_print() \n");
    while (NULL != ptr->next) {
        printf("key [%i] \n", ptr->key);
        ptr = ptr->next;
    }
}

// Naive approach, make a new list, and copy it over
Node* linked_list_reverse_naive(Node *ll) {
    Node *ptr = ll->next;
    Node *head = linked_list_create();
    Node *curr = head;
  
    while (NULL != ptr->next) {
        // printf("key [%i] \n", ptr->key);
        curr = linked_list_insert_after(curr, ptr->key);
        ptr = ptr->next;
    }
    return head;
}

void linked_list_insert_before(Node *head, Node *before, int key) {
    Node *ptr = head;
    while (before != ptr->next) {
        ptr = ptr->next;
        printf("linked_list_insert_before [%i] \n", ptr->key);
        // if (NULL == ptr->next->next) return;
    }
    Node *neu = (Node*)malloc(sizeof(Node));   
    neu->key = key;
    neu->next = ptr->next;
    ptr->next = neu;
    
    return;
}

int main() {
    Node *head = linked_list_create();
    Node *ll = head;

    ll = linked_list_insert_after(ll, 6);
    ll = linked_list_insert_after(ll, 5);
    ll = linked_list_insert_after(ll, 4);
    ll = linked_list_insert_after(ll, 3);
    ll = linked_list_insert_after(ll, 1);
    linked_list_insert_before(head, ll, 2);

    linked_list_print(head);
    
    // Node *head2 = linked_list_reverse_naive(head);
  
    // linked_list_print(head2);

   return 0;
}
