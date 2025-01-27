#include <stdlib.h>
#include <stdio.h>

typedef struct node { 
    int key; 
    struct node *next; 
} node;

/*
    Traversal - To access each element of the linked list.
    Insertion - To add/insert a new node to the list.
    Deletion - To remove ane existing node from the list.
    Search - To find a node in the list.
    Sort - To sort the nodes.
*/

node* linked_list_initialize() {
    node *head = malloc(sizeof(node));
    head->key = 0;
    head->next = NULL;
    return head;
}

// insert the new item right after the head
node* linked_list_insert(int key, node *ptr) {
    node *neu = malloc(sizeof(node));
    neu->key = key;
    neu->next = ptr->next;
    ptr->next = neu;
    return neu;
}

void print_linked_list(node *ptr) {
    while (ptr != NULL) {
        printf("%i \n", ptr->key);
        ptr = ptr->next;
    }
}

void linked_list_swap(node *ptr) {
    node *one, *two, *tmp, *three;
    one = ptr->next;
    two = ptr->next->next;
    three = ptr->next->next->next;
    ptr->next = two;
    ptr->next->next = one;
    one->next = three;
    return;
}

void linked_list_bubble_sort(node *head) {
    node *ptr = head;
    int done = 1;
    do {
        ptr = head;
        done = 1;
        while(ptr->next->next != NULL) {
            if (ptr->next->key > ptr->next->next->key) {
                printf("bubble %i > %i \n", ptr->next->key, ptr->next->next->key);
                linked_list_swap(ptr);
                done = 0;
            }
            else {
                printf("bubble %i < %i \n", ptr->next->key, ptr->next->next->key);
            }
            ptr = ptr->next;
        }
    } while(!done);
}

/*
node* insert_after(int key, struct node *head) {
}

node* search(int key, struct node *head) {
}

void delete_after(int key, struct node *head) {
}

*/

int main() {
    node *head = linked_list_initialize();
    node *ll = linked_list_insert(7, head);

    ll = linked_list_insert(6, ll);
    ll = linked_list_insert(5, ll);
    ll = linked_list_insert(4, ll);
    ll = linked_list_insert(3, ll);
    ll = linked_list_insert(2, ll);
    ll = linked_list_insert(1, ll);

    linked_list_bubble_sort(head);
    print_linked_list(head);

/*
    linked_list_swap(head->next->next);
    struct node *ll = insert_after(1, head);
    struct node *found = search(5, head);
    printf("Found 5 %p %i \n", found, found->key);
    delete_after(5, head); // should delete 6
    delete_after(8, head); // will this crash?
    print_linked_list(head);
*/
    return 0;
}
