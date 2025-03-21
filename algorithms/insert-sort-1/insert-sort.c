#include <stdio.h>
#include <assert.h>

void print_array(int *arr, int size) {
    int i;
    printf("\n");
    for (i = 0; i < size; i++) {
        printf("%i, ", arr[i]);
    }
}

void insert_sort(int *arr, int size) {
    int i, gap, tmp;
    for (i = 1; i < size; i++) {
        tmp = arr[i];
        gap = i - 1;
        while (gap >= 0) {
            if (arr[gap] < tmp) {
                break;
            }
            arr[gap + 1] = arr[gap];
            gap = gap - 1;
        }
        arr[gap + 1] = tmp;
    }
}

int main() {
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    int size = 7;
    print_array(arr, size);
    insert_sort(arr, size);
    print_array(arr, size);
    printf("\n");
    return 0;
}
