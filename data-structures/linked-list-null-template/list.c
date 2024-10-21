// for malloc
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int key;
    struct node *next;
} node;

/* linked list */
node* list_create();
node* list_insert_after(node *ptr, int key);
void list_destroy(node *head);
node* list_insert_end(node *head, int key);
void list_remove(node *head, node *ptr);
void list_remove_by_key(node *head, int key);
node* list_find_node(node *head, node *ptr);
node* list_find_by_key(node *head, int key);

int main() {
}
