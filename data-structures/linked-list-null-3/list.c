// for malloc
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int key;
    struct node *next;
} node;

void list_destroy(node *head);
void list_remove(node *head, node *ptr);
void list_remove_by_key(node *head, int key);
node* list_find_node(node *head, node *ptr);
node* list_find_by_key(node *head, int key);

void list_print(node *head) {
    printf("head: %p key: %i \n", head, head->key);	
    node *ptr = head->next;
    while(ptr->next != NULL) {
        printf("ptr: %p key: %i \n", ptr, ptr->key);	
        ptr = ptr->next;
    }
    printf("tail: %p key: %i \n", ptr, ptr->key);	
}

node* list_create() {
    node *head = malloc(sizeof(node));
    node *tail = malloc(sizeof(node));
    head->next = tail;
    head->key = -1;
    tail->next = NULL;
    tail->key = -1;
    return head;
}

int list_size(node *head) {
    int c = 1;
    node *ptr = head; 
    while (ptr->next != NULL) {
        c++;
	ptr = ptr->next;
    }
    return c;
}

node* list_insert_after(node *ptr, int key) {
    node *neu = malloc(sizeof(node));
    neu->key = key;
    neu->next = ptr->next;
    ptr->next = neu;
    return neu;
}

node* list_insert_sorted(node *head, int key) {
    node *neu = malloc(sizeof(node));
    neu->key = key;
    node *ptr = head->next;
    node *prev = head;
    while(ptr->next != NULL) {
        if(ptr->key > key) {
            break;
        }
	    prev = ptr;
        ptr = ptr->next;
    }
    neu->next = prev->next;
    prev->next = neu;
    return neu;
}

// sequential search
node* list_find_by_key_seq(node *head, int key) {
    node *ptr = head;
    while(ptr->next != NULL) {
        if (ptr->key == key) {
	        break;
	    }
        ptr = ptr->next;
    }
    return ptr;
}

node* list_binary_search(node *head, int key) {
    node *ptr = head;
    while(ptr->next != NULL) {
    }
}

int main() {
    int key = 22;
    node *head = list_create();
    node *ptr = list_insert_after(head, 1);
    for (int i = 2; i < 101; i++) {
	// printf("%i \n", i);
        ptr = list_insert_sorted(head, i);
    }
    /*
    ptr = list_insert_sorted(head, 22);
    ptr = list_insert_sorted(head, 4);
    ptr = list_insert_sorted(head, 2);
    ptr = list_insert_sorted(head, 0);
    */
    // printf("list size: %i \n", list_size(head));
    list_print(head);
    ptr = list_find_by_key_seq(head, key);
    printf("finding %i : %i %p \n", key, ptr->key, ptr);
}

