#include <stdio.h>

int main(void) {
    int source_num = 12345;
    int working_copy = source_num;
    int flipped_num = 0;

    while (working_copy > 0) {
        int digit = working_copy % 10;
        flipped_num = flipped_num * 10 + digit;
        working_copy /= 10;
    }

    printf("Original Number : %d\n", source_num);
    printf("Reversed Number : %d\n", flipped_num);

    return 0;
}
