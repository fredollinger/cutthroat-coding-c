#include "linked-list.h"

#include <stdlib.h>

node* list_create() {
    node *head = malloc(sizeof(node));
    return head;
}

int main()
{
    node *head = list_create();
}
