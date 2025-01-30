#include <stdlib.h>
#include <stdio.h>

typedef struct node { 
    int key; 
    struct node *next; 
} node;

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

    // linked_list_bubble_sort(head);
    print_linked_list(head);

    return 0;
}
