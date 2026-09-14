#include <stdio.h>

int main(void) {
    printf("Counting from 0 to 100 in steps of 10:\n");
    for (int step = 0; step <= 100; step += 10) {
        printf("%d ", step);
    }
    printf("\n\n");

    printf("Powers of 2 up to 1024:\n");
    for (int power = 1; power <= 1024; power *= 2) {
        printf("%d ", power);
    }
    printf("\n");

    return 0;
}
