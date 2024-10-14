#ifndef _LIST_H
#define _LIST_H

typedef struct node {
	int key;
	struct node *next;
} node;

/* linked list */
node* list_create();
node* list_insert_after(node *ptr, int data);
node* list_insert_beginning(node *head, int data);
void list_destroy(node *heaed);
node* list_insert_end(node *head, void *data);
void list_remove(node *head, node *ptr);
void list_remove_by_data(node *head, void *ptr);
node* list_find_node(node *head, node *ptr);
node* list_find_by_data(node *head, void *data);

#endif

