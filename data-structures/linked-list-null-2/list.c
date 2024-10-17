#include "list.h"

// for malloc
#include <stdlib.h>

node* list_create() {
    node *head = malloc(sizeof(node));
    node *tail = malloc(sizeof(node));
    head->next = tail;
    tail->key = -1;
    tail->next = NULL;
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
    node *ptr = head->next; // skip past the head
    while(ptr->key < key) {
        // case where we have nothing inserted yet
        if (ptr->next == NULL) {
	    break;
	}
    }
    neu->next = ptr;
    ptr->next = neu;
    return neu;
}

int main() {
    node *ll = list_create();
}
