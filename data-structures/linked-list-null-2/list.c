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

int main() {
    node *ll = list_create();
}
