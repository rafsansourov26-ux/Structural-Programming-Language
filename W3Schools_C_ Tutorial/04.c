#include <stdio.h>

int main(void) {
    int first_num = 15;
    int second_num = 25;
    int total = first_num + second_num;

    printf("Initial values: x = %d, y = %d\n", first_num, second_num);
    printf("Sum = %d\n", total);

    // Assigning new values to the same variables
    first_num = 50;
    second_num = 70;
    total = first_num + second_num;

    printf("Updated values: x = %d, y = %d\n", first_num, second_num);
    printf("Updated sum = %d\n", total);

    return 0;
}
