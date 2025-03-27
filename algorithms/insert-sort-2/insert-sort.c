#include <stdio.h>
#include <assert.h>

void print_array(int *arr, int size) {
    int i;
    for (i = 0; i < size - 1; i++) {
        printf("%i, ", arr[i]);
    }
    printf("%i \n", arr[size - 1]);
}

void insert_sort(int *arr, int size) {
    int i, tmp, gap;
    for (i = 1; i <= size; i++) {
        gap = i - 1;
        tmp = arr[gap];
        while (gap >= 0) {
            if (arr[gap] < tmp) {
                break;
            }
            print_array(arr, size);
            gap = gap - 1; 
            arr[gap + 1] = arr[gap];
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
