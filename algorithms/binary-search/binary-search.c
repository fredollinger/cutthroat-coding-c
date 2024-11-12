#include <stdio.h>

// Given an item, find the spot where
// that item appears in the list or return -1
// if the item is not found
int sequential_search(int item, int *arr, int len) {
    printf("len: %i \n", len);
    int i;
    for (i=0; i < item; i++) {}
    printf("search item: %i result: %i \n", item, i);
}

int main() {
    int len = 100;
    int list[len];
    for (int i=0; i < len; i++) {
        list[i] = i;
    }
    sequential_search(50, list, len);
}

