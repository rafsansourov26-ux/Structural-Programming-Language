#include <stdio.h>

int main(void) {
    printf("Even numbers between 0 and 20:\n");

    for (int n = 0; n <= 20; n += 2) {
        printf("%d ", n);
    }
    printf("\n");

    return 0;
}
