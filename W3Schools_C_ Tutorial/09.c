#include <stdio.h>

int main(void) {
    int val1 = 20;
    int val2 = 6;

    printf("a = %d, b = %d\n", val1, val2);
    printf("a + b = %d\n", val1 + val2);
    printf("a - b = %d\n", val1 - val2);
    printf("a * b = %d\n", val1 * val2);
    printf("a / b = %d (integer division)\n", val1 / val2);
    printf("a %% b = %d (remainder)\n", val1 % val2);

    // Demonstrating increment and compound assignment operators
    int tally = 10;
    tally++;
    printf("count after ++ : %d\n", tally);
    tally += 5;
    printf("count after += 5 : %d\n", tally);
    tally *= 2;
    printf("count after *= 2 : %d\n", tally);

    return 0;
}
