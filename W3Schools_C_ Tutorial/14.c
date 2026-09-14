#include <stdio.h>

int main(void) {
    int given_number = -28;

    printf("Input Value: %d\n", given_number);

    // Determine the sign of the number
    if (given_number > 0) {
        printf("Sign       : Positive number\n");
    } else if (given_number < 0) {
        printf("Sign       : Negative number\n");
    } else {
        printf("Sign       : Zero\n");
    }

    // Determine odd or even
    if (given_number % 2 == 0) {
        printf("Parity     : Even\n");
    } else {
        printf("Parity     : Odd\n");
    }

    return 0;
}
