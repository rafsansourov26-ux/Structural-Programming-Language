#include <stdio.h>

int main(void) {
    int base_number = 7;

    printf("Multiplication Table for %d:\n", base_number);
    printf("---------------------------\n");

    for (int multiplier = 1; multiplier <= 10; multiplier++) {
        printf("%2d x %2d = %3d\n", base_number, multiplier, base_number * multiplier);
    }

    return 0;
}
