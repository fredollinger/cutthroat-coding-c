// for malloc
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int key;
    struct Node *prev;
    struct Node *next;
} Node;

/* linked list */
// node* list_create();
/*
node* list_insert_after(node *ptr, int key);
void list_destroy(node *head);
node* list_insert_end(node *head, int key);
void list_remove(node *head, node *ptr);
void list_remove_by_key(node *head, int key);
node* list_find_node(node *head, node *ptr);
node* list_find_by_key(node *head, int key);
*/

Node* double_list_create() {
    Node *head = (Node*)malloc(sizeof(Node));
    Node *tail = (Node*)malloc(sizeof(Node));

    head->key = -1;
    head->prev = NULL;
    head->next = tail;

    tail->key = -2;
    tail->prev = head;
    tail->next = NULL;
    return head;
}

Node* double_list_insert_after(Node *first, int key) {
    Node *last = first->next;
    Node *middle = (Node*)malloc(sizeof(Node));
    middle->key = key;

    middle->next = first->next;
    middle->prev = first;

    first->next = middle;
    last->prev = middle;
    // printf("neu->prev %i prt %i \n", neu->prev->key, ptr->key);
    return middle;
}

Node* double_list_print_forwards(Node *head) {
    Node *curr = head->next;
    while(curr->next != NULL) {
        printf("double_list_print_forwards() %i \n", curr->key);
        curr = curr->next;
    }
}

Node* double_list_print_backwards(Node *tail) {
    Node *curr = tail->prev;
    while(curr->prev != NULL) {
        printf("double_list_print_backwards() %i \n", curr->key);
        curr = curr->prev;
    }
}

void double_list_remove(Node *dead) {
    Node *first = dead->prev;
    Node *last = dead->next;

    first->next = last;
    last->prev = first;
    free(dead);
}

void double_list_swap(Node *one, Node *two) {
    Node *one_prev = one->prev;
    Node *one_next = one->next;
    Node *two_prev = two->prev;
    Node *two_next = two->next;

    one_prev = two;
    one_next = two;
    two_prev = one;
    two_next = one;

    return;
}

int main() {
    Node *head = double_list_create();
    Node *tail = head->next;
   
    // printf("tail %i \n", tail->key);

    Node *curr = double_list_insert_after(head, 7);
    curr = double_list_insert_after(curr, 6);
    curr = double_list_insert_after(curr, 5);
    curr = double_list_insert_after(curr, 4);
    Node *four = curr;
    curr = double_list_insert_after(curr, 3);
    Node *three = curr;
    curr = double_list_insert_after(curr, 2);
    Node *two = curr;
    curr = double_list_insert_after(curr, 1);

    printf("Before swap \n");
    double_list_print_forwards(head);
    printf("\n");

    double_list_swap(two, four);

    printf("\nAfter swap \n");
    double_list_print_forwards(head);
    printf("\n");

/*
    printf("Before removal \n");
    double_list_print_forwards(head);
    printf("\n");
    double_list_print_backwards(tail);

    double_list_remove(four);

    printf("\nAfter removal \n");
    double_list_print_forwards(head);
    printf("\n");
    double_list_print_backwards(tail);
    printf("\n");
*/

/*
    ll = linked_list_insert_after(ll, 6);
    ll = linked_list_insert_after(ll, 5);
    Node *five = ll;
    ll = linked_list_insert_after(ll, 4);
    Node *four = ll;
    ll = linked_list_insert_after(ll, 3);
    Node *three = ll;
    ll = linked_list_insert_after(ll, 1);
    linked_list_insert_before(head, ll, 2);


    //linked_list_swap(head, four, three);

    linked_list_print(head);
    linked_list_reverse_in_place(head);
    printf("linked list swap \n");
    linked_list_print(head);
*/

   return 0;
}
