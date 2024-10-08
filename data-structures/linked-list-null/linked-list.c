#include "linked-list.h"

#include <stdlib.h>
#include <stdio.h>

node* list_create() {
    node *head = malloc(sizeof(node));
    node *z = malloc(sizeof(node));
    head->next = z;
    z->next = NULL;
    return head;
}

node* list_insert_after(node *ptr, int data) {
    node *curr = ptr;
    while(NULL != curr->next && data != curr->data) {
        curr = curr->next;
    }
    node *neu = malloc(sizeof(node));
    neu->data = data;
    neu->next = curr->next;
    curr->next = neu;
    return neu;
}

void list_print(node *head) {
    node *ptr = head->next;
	while(NULL != ptr->next) {
       printf("ptr: %p data: %i \n", ptr, ptr->data);
       ptr = ptr->next;
    }
}

int main()
{
    node *head = list_create();
    node *ptr = list_insert_after(head, 1);
    ptr = list_insert_after(ptr, 2);
    ptr = list_insert_after(ptr, 3);
    ptr = list_insert_after(ptr, 4);
    ptr = list_insert_after(ptr, 5);
    ptr = list_insert_after(ptr, 6);
    ptr = list_insert_after(ptr, 7);
    ptr = list_insert_after(ptr, 8);
    list_print(head);
}
