#include <stdlib.h>
#include <stdio.h>

int main() {
    node *head = linked_list_initialize();

    // populate linked list
    node *ll = linked_list_insert(7, head);
    ll = linked_list_insert(6, ll);
    ll = linked_list_insert(5, ll);
    ll = linked_list_insert(4, ll);
    ll = linked_list_insert(3, ll);
    ll = linked_list_insert(2, ll);
    ll = linked_list_insert(1, ll);

    printf("original \n");
    print_linked_list(head);

    node *two = linked_list_search(2, head);
    linked_list_bubble_sort(head);

    // linked_list_bubble_sort(head);
    printf("\n sorted \n");
    print_linked_list(head);

    return 0;
}
