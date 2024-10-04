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

struct node* search(int key, struct node *head) {
    struct node *ptr = head;
    while (ptr != ptr->next) {
        if (key == ptr->key) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

struct node* delete_after(int key, struct node *head) {
    struct node *ptr = head;
    while (ptr != ptr->next) {
        if (key == ptr->key) {
	    struct node *del = ptr->next;
            ptr->next = ptr->next->next;
	    free(del);
        }
        ptr = ptr->next;
    }
}

void print_linked_list(struct node *head) {
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
    struct node *ll = insert_after(1, head);
    ll = insert_after(2, ll);
    ll = insert_after(3, ll);
    ll = insert_after(4, ll);
    ll = insert_after(5, ll);
    ll = insert_after(6, ll);
    ll = insert_after(7, ll);
    ll = insert_after(8, ll);
    struct node *found = search(5, head);
    printf("Found 5 %p %i \n", found, found->key);
    delete_after(5, head);
    print_linked_list(head);
    return 0;
}
