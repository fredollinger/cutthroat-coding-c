#include <stdio.h>
#include <assert.h>

int sequential_search(int item, int *arr, int len) {
    for (int i = 0; i < len; i++) {
    }
    return 50;
}

int binary_search(int item, int *arr, int len) {}

void print_array(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%i : %i \n", i, arr[i]);
    }
}

int main() {
    int len = 100;
    int item = 50; // item to search for
    int list[len];
    int prev = 0;
    for (int i=0; i < len; i++) {
        list[i] = prev + 5;
	prev = list[i];
    }
    print_array(list, len);
    // int res1 = sequential_search(item, list, len);
    // assert (res1 == item);
    /*
    printf("item: %i result: %i \n", item, res1);
    int res2 = binary_search(item, list, len);
    printf("item: %i result: %i \n", item, res2);
    */
}

