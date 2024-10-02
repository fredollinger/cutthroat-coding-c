#include <stdlib.h>
#include <stdio.h>

struct node { 
    int key; 
    struct node *next; 
};

/*
    Traversal - To access each element of the linked list.
    Insertion - To add/insert a new node to the list.
    Deletion - To remove ane existing node from the list.
    Search - To find a node in the list.
    Sort - To sort the nodes.
*/

struct node* linked_list_initialize() {
    struct node *head = malloc(sizeof(struct node));
    struct node *z = malloc(sizeof(struct node));
    head->next = z;
    z->next = z; 
    head->key = 69;
    z->key = -1;
    return head;
}

struct node* insert_after(int key, struct node *head) {
    struct node *neu = malloc(sizeof(struct node));
    neu->key = key; // new node has the key
    neu->next = head->next; // new node points to the last node
    head->next = neu; // old node points to the new node
    return neu; // return pointer to the current node
}

void print_linked_list(struct node *head) {
    // printf("head %p -> %p %i \n", head, head->next, head->key);
    // printf("one %p -> %p %i \n", head->next, head->next->next, head->next->key);
    // printf("z %p -> %p %i \n", head->next->next, head->next->next->next, head->next->next->key);

    struct node *next = head->next;
    while(next != next->next) {
        printf("key: %i \n", next->key);
        printf("next: %p \n", next);
        printf("%p -> %p \n", next, next->next);
        next = next->next;
    }
}

int main() {
    struct node *head = linked_list_initialize();
    struct node *ll = insert_after(13, head);
    print_linked_list(head);
    return 0;
}
