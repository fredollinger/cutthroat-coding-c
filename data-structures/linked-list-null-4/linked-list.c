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
}

struct node* insert_after(int key, struct node *head) {
}

struct node* search(int key, struct node *head) {
}

void delete_after(int key, struct node *head) {
}

void print_linked_list(struct node *head) {
}

int main() {
/*
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
    delete_after(5, head); // should delete 6
    delete_after(8, head); // will this crash?
    print_linked_list(head);
*/
    return 0;
}
