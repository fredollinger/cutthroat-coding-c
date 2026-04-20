// for malloc
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int key;
    struct Node *prev;
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
    Node *tail = (Node*)malloc(sizeof(Node));

    head->key = -1;
    head->prev = NULL;
    head->next = tail;

    tail->key = -2;
    tail->prev = head;
    tail->next = NULL;
}

int main() {
    Node *ll = linked_list_create();

/*
    ll = linked_list_insert_after(ll, 7);
    ll = linked_list_insert_after(ll, 6);
    ll = linked_list_insert_after(ll, 5);
    Node *five = ll;
    ll = linked_list_insert_after(ll, 4);
    Node *four = ll;
    ll = linked_list_insert_after(ll, 3);
    Node *three = ll;
    ll = linked_list_insert_after(ll, 1);
    linked_list_insert_before(head, ll, 2);


    //linked_list_swap(head, four, three);

    linked_list_print(head);
    linked_list_reverse_in_place(head);
    printf("linked list swap \n");
    linked_list_print(head);
*/

   return 0;
}
