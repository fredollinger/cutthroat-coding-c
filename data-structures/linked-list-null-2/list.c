#include "list.h"

// for malloc
#include <stdlib.h>
#include <stdio.h>

node* list_create() {
    node *head = malloc(sizeof(node));
    node *tail = malloc(sizeof(node));
    head->next = tail;
    head->key = -1000;
    tail->key = -1;
    tail->next = NULL;
    return head;
}

node* list_insert_after(node *ptr, int key) {
    node *neu = malloc(sizeof(node)); 
    neu->key = key;
    neu->next = ptr->next;
    ptr->next = neu;
    return neu;
}

void list_destroy(node *head) {
    node *ptr = head;
    while (NULL != ptr->next) {
        free(ptr);
    }
    // ptr points to tail node, delete that as well
    free(ptr);
}

// Insert a key into the list in a sorted manner
node* list_insert_sorted(node *head, int key) {
    node *neu = malloc(sizeof(node));
    neu->key = key;
    node *ptr = head;
    while(NULL != ptr->next->next) {
        // case where we have nothing inserted yet
        if (ptr->next->key > key) {
	        break;
	    }
        ptr = ptr->next;
    }
    neu->next = ptr->next;
    ptr->next = neu;
    return neu;
}

node* print_list(node *head) {
    node *ptr = head->next;
    int i = 1;
    while (NULL != ptr) {
        printf("%i %p %i \n", i, ptr, ptr->key);
	i++;
	ptr = ptr->next;
    }
}

int main() {
    node *head = list_create();
    node *ptr = list_insert_after(head, 71);
    ptr = list_insert_sorted(head, 9);
    ptr = list_insert_sorted(head, 1);
    ptr = list_insert_sorted(head, 81);
    // ptr = list_insert_sorted(head, 1);
    print_list(head);
}