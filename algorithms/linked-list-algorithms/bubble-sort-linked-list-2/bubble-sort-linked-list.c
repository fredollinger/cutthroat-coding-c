#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int key;
    struct node *next;
} node;

node* linked_list_initialize() {
    node *head = malloc(sizeof(node));
    head->next = NULL;
    head->key = 0;
    return head;
}

node* linked_list_insert(int key, node* ptr) {
    node *neu = malloc(sizeof(node));
    neu->next = ptr->next;
    neu->key = key;
    ptr->next = neu;
    return neu;
}

void linked_list_print(node* head) {
    node *ptr = head;
    while(NULL != ptr) {
        printf("%i \n", ptr->key);
        ptr = ptr->next;
    }
}

void linked_list_swap(node* ptr1, node *ptr2) {
    int key = ptr1->key;
    ptr1->key = ptr2->key;
    ptr2->key = key;
}

node* linked_list_bubble_sort(node* head) {
    node *ptr = head->next;
    int done = 0;
    while(!done){
        done = 1;
        ptr = head->next;
        while(NULL != ptr->next) {
            if (ptr->key > ptr->next->key) {
                linked_list_swap(ptr, ptr->next);
                done = 0;
            }
            ptr = ptr->next;
        }
    }
    return head;
}

int main() {
    node *head = linked_list_initialize();

    // populate linked list
    node *ll = linked_list_insert(7, head);

    ll = linked_list_insert(6, ll);
    ll = linked_list_insert(5, ll);
    ll = linked_list_insert(4, ll);
    ll = linked_list_insert(3, ll);
    ll = linked_list_insert(2, ll);
    ll = linked_list_insert(1, ll);

    printf("original \n");
    linked_list_print(head);

    linked_list_bubble_sort(head);

    // linked_list_bubble_sort(head);
    printf("\n sorted \n");
    linked_list_print(head);

    return 0;
}
