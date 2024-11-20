#include <stdio.h>

// Given an item, find the spot where
// that item appears in the list or return -1
// if the item is not found
int sequential_search(int item, int *arr, int len) {
    printf("len: %i \n", len);
    int i;
    for (i=0; i < item; i++); 
    printf("search item: %i index: %i result: %i \n", item, i, arr[i]);
}

int binary_search(int item, int *arr, int len) {
    int low = 0;
    int high = len - 1;
    int mid = low + (high - low) / 2;
    int count = 0; // number of checks for the item
    printf("mid: %i \n", mid);
    printf("arr[10] %i \n", arr[10]);
    while (low < high) {
        if (item > arr[mid]) {
            printf("binary_search(): higher mid %i\n", mid);
	    low = mid; 
            mid = low + (high - low) / 2;
        }
	else if (item < arr[mid]) {
            printf("binary_search(): lower mid %i\n", mid);
	    high = mid; 
            mid = low + (high - low) / 2;
	}
	else if (arr[mid] == item) {
	    printf("binary_search(): arr: %i == item: %i \n", arr[mid], item);
	    break;
	}
    }
    return mid;
}

int main() {
    int len = 100;
    int item = 50; // item to search for
    int list[len];
    for (int i=0; i < len; i++) {
        list[i] = i;
    }
    // sequential_search(50, list, len);
    int res1 = sequential_search(item, list, len);
    printf("item: %i result: %i \n", item, res1);
    int res2 = binary_search(item, list, len);
    printf("item: %i result: %i \n", item, res2);
}

