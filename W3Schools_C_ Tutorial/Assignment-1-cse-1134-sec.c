#include <stdio.h>

int main() {
    int num, i = 2, isPrime = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num <= 1) {
        isPrime = 0;
    } else {
        do {
            if (num % i == 0 && num != i) {
                isPrime = 0;
                break;
            }
            i++;
        } while (i * i <= num);
    }

    if (isPrime)
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);

    return 0;
}
