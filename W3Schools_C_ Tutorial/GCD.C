#include <stdio.h>

int main() {
    int a, b, temp;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    int originalA = a, originalB = b;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    printf("GCD of %d and %d = %d\n", originalA, originalB, a);
    return 0;
}
