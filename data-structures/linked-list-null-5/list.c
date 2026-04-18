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
    int i = 0;
    printf("linked_list_print() [ ");
    while (NULL != ptr->next && i < 15) {
        printf("%i ", ptr->key);
        ptr = ptr->next;
        i = i + 1;
    }
    printf("] \n");
}

Node* linked_list_insert_before(Node *head, Node *before, int key) {
    Node *ptr = head;
    while (before != ptr->next) {
        ptr = ptr->next;
        // printf("linked_list_insert_before [%i] \n", ptr->key);
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

// swap 2 elements that are not touching
int linked_list_swap_not_touching(Node *head, Node *first, Node *second) {
    Node *before_first = linked_list_find_before(head, first);
    Node *before_second = linked_list_find_before(head, second);
    Node *old_first_next = first->next;
    Node *old_second_next = second->next;

    second->next = old_first_next;
    first->next = old_second_next;
    before_first->next = second;
    before_second->next = first;
    return 0;
}

int linked_list_swap_touching(Node *head, Node *first, Node *second) {
    Node *before_first = linked_list_find_before(head, first);
    Node *before_second = linked_list_find_before(head, second);
    Node *old_second_next = second->next;

    second->next = first->next->next;
    first->next = old_second_next;
    before_first->next = second;
    return 1;
}

int linked_list_swap(Node *head, Node *first, Node *second) {
    printf("\nswap first %i, second %i \n", first->key, second->key);
 
    if (first->next == second) {
        printf("\nswap first->next %i == second %i \n", first->next->key, second->key);
        return linked_list_swap_touching(head, first, second);
    }
    else {
        return linked_list_swap_not_touching(head, first, second);
    }
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
    Node *first_prev = head;
    Node *last_prev = tail;
    // printf("list item of linked list first %i, last %i \n", first_curr->key, last_curr->key);
    while(first_curr != last_curr) {
        linked_list_print(head);
        // printf("first_prev %i last_prev %i \n", first_prev->key, last_prev->key);
        // printf("first_curr %i last_curr %i \n", first_curr->key, last_curr->key);
        if (first_prev == first_curr) {
            printf("break \n");
            break;
        }
        if (first_curr->key != last_curr->key) {
            last_before = linked_list_find_before(head, last_curr);
            // if we are swapping two touching nodes then we are at the end
            if (1 == linked_list_swap(head, first_curr, last_curr)) {
                return;
            }
            first_prev = last_curr;
            last_prev = first_curr;
            // printf("setting linked list swap %i, last %i \n", first_curr->key, last_curr->key);
        }
        else {
            break;
        }

        first_curr = last_curr->next;
        last_curr = last_before;
        // printf("list item of linked list first %i, last %i \n\n", first_curr->key, last_curr->key);
    }

    linked_list_print(head);
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


    //linked_list_swap(head, four, three);

    linked_list_print(head);
    linked_list_reverse_in_place(head);
    printf("linked list swap \n");
    linked_list_print(head);

   return 0;
}
