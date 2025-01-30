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
                linked_list_swap(ptr);
                done = 0;
            }
            else {
            }
            ptr = ptr->next;
        }
    } while(!done);
}


node* linked_list_search(int key, node *head) {
    node *ptr = head;
    while (ptr != NULL) {
        if (ptr->key == key) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void linked_list_delete(int key, struct node *head) {
    node *ptr = head;
    node *prev = ptr;
    while (ptr != NULL && ptr->key != key) {
        prev = ptr;
        ptr = ptr->next;
    }
    
    if (NULL == ptr) {
        return;
    }

    prev->next = ptr->next;
    free(ptr);
}

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
    node *four = linked_list_search(4, head);
    printf("found 4 as %i \n", four->key);
    linked_list_delete(5, head); // should delete 6
    print_linked_list(head);

/*
    linked_list_swap(head->next->next);
    struct node *ll = insert_after(1, head);
    struct node *found = search(5, head);
    printf("Found 5 %p %i \n", found, found->key);
    delete_after(8, head); // will this crash?
    print_linked_list(head);
*/
    return 0;
}
