#ifndef _LIST_H
#define _LIST_H

typedef struct node {
	int data;
	struct node *next;
} node;

/* linked list */
node* list_create();
node* list_insert_after(node *ptr, int data);

void list_destroy(node **list);
node* list_insert_beginning(node *list, void *data);
node* list_insert_end(node *list, void *data);
void list_remove(node **list, node *ptr);
void list_remove_by_data(node **list, void *ptr);
node* list_find_node(node *list, node *ptr);
node* list_find_by_data(node *list, void *data);
node* list_find(node *list, int(*func)(node*,void*), void *data);

#endif

