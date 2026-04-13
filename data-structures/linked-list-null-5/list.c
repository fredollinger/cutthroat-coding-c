// for malloc
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int key;
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

Node* linked_list_create() {
    Node *head = (Node*)malloc(sizeof(Node));   
    head->key = -1;
    Node *tail = (Node*)malloc(sizeof(Node));   
    tail->key = -2;
    head->next = tail;
    tail->next = NULL;
    return head;
}

Node* linked_list_insert_after(Node *ptr, int key) {
    Node *neu = (Node*)malloc(sizeof(Node));   
    neu->key = key;
    neu->next = ptr->next;
    ptr->next = neu;
    return neu;
}

void linked_list_print(Node *ll) {
    Node *ptr = ll->next;

    printf("linked_list_print() \n");
    while (NULL != ptr->next) {
        printf("key [%i] \n", ptr->key);
        ptr = ptr->next;
    }
}

Node* linked_list_insert_before(Node *head, Node *before, int key) {
    Node *ptr = head;
    while (before != ptr->next) {
        ptr = ptr->next;
        printf("linked_list_insert_before [%i] \n", ptr->key);
        // if (NULL == ptr->next->next) return;
    }
    Node *neu = (Node*)malloc(sizeof(Node));   
    neu->key = key;
    neu->next = ptr->next;
    ptr->next = neu;
    
    return neu;
}

// Naive approach, make a new list, and copy it over
Node* linked_list_reverse_naive(Node *ll) {
    Node *ptr = ll->next;
    Node *head = linked_list_create();
    Node *curr = head;

    linked_list_insert_after(curr, ptr->key);
    ptr = ptr->next;
    curr = curr->next;

    while (NULL != ptr->next) {
        curr = linked_list_insert_before(head, curr, ptr->key);
        ptr = ptr->next;
    }

    return head;
}

// find the Node right before the ptr
Node* linked_list_find_before(Node *head, Node *ptr) {
    Node *curr = head;
    while(curr->next != ptr) {
        curr = curr->next;
    }
    return curr;    
}

void linked_list_remove(Node *head, Node *ptr) {
    Node *before = linked_list_find_before(head, ptr);
    before->next = ptr->next;
}

void linked_list_swap(Node *head, Node *first, Node *second) {
    printf("linked list swap %i, last %i \n", first->key, second->key);
    Node *before_first = linked_list_find_before(head, first);
    Node *before_second = linked_list_find_before(head, second);
    Node *old_first_next = first->next;
    Node *old_second_next = second->next;
    first->next = old_second_next;
    second->next = old_first_next;
    before_first->next = second;
    before_second->next = first;
}

// Naive approach, make a new list, and copy it over
void linked_list_reverse_in_place(Node *head) {
    // find end of linked list
    Node *tail = linked_list_find_before(head, NULL);
    Node *last = linked_list_find_before(head, tail);
    Node *last_curr = last;
    Node *first = head->next;
    Node *first_curr = first;
    Node *last_before = NULL;
    printf("list item of linked list first %i, last %i \n", first_curr->key, last_curr->key);
    while(first_curr != last_curr) {
        if (first_curr->key != last_curr->key) {
            last_before = linked_list_find_before(head, last_curr);
            linked_list_swap(head, first_curr, last_curr);
        }
        else {
            break;
        }
        first_curr = last_curr->next;
        last_curr = last_before;
        printf("list item of linked list first %i, last %i \n", first_curr->key, last_curr->key);
    }
    return;
}

int main() {
    Node *head = linked_list_create();
    Node *ll = head;

    ll = linked_list_insert_after(ll, 7);
    ll = linked_list_insert_after(ll, 6);
    ll = linked_list_insert_after(ll, 5);
    Node *five = ll;
    ll = linked_list_insert_after(ll, 4);
    Node *four = ll;
    ll = linked_list_insert_after(ll, 3);
    Node *three = ll;
    ll = linked_list_insert_after(ll, 1);
    linked_list_insert_before(head, ll, 2);

    linked_list_print(head);

    // linked_list_swap(head, five, three);

    linked_list_reverse_in_place(head);
    printf("linked list swap \n");
    linked_list_print(head);
    // Node *head2 = linked_list_reverse_naive(head);

   return 0;
}
