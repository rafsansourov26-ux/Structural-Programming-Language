#include <stdio.h>

int main(void) {
    int num_a = 10;
    int num_b = 20;

    printf("Comparison Results (1 = True, 0 = False):\n");
    printf("x == y : %d\n", num_a == num_b);
    printf("x != y : %d\n", num_a != num_b);
    printf("x < y  : %d\n", num_a < num_b);
    printf("x >= y : %d\n", num_a >= num_b);

    printf("\nMemory Size (Bytes):\n");
    printf("sizeof(char)   : %zu byte(s)\n", sizeof(char));
    printf("sizeof(int)    : %zu byte(s)\n", sizeof(int));
    printf("sizeof(float)  : %zu byte(s)\n", sizeof(float));
    printf("sizeof(double) : %zu byte(s)\n", sizeof(double));

    return 0;
}
