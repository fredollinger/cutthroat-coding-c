#include <stdio.h>

int main() {
    int len = 100;
    int item = 50; // item to search for
    int list[len];
    for (int i=0; i < len; i++) {
        list[i] = i;
    }
    /*
    int res1 = sequential_search(item, list, len);
    printf("item: %i result: %i \n", item, res1);
    int res2 = binary_search(item, list, len);
    printf("item: %i result: %i \n", item, res2);
    */
}

