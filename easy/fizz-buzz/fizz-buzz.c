#include <stdio.h>   // printf

int main() {
    int line = 0;
    for (int x=1; x <= 100; x++) {
        line = 0;
        if (x  % 3 == 0) {
            printf("%i fizz ", x);
            line = 1;
        }
        if (x  % 5 == 0) {
            printf("%i buzz ", x);
            line = 1;
        } 
        if (line) {
            printf("\n");
        }
    }
        return 0;
}
