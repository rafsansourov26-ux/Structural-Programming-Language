#include <stdio.h>

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    int x = a, y = b;
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }

    int gcd = x;
    long long lcm = (long long)(a * b) / gcd;

    printf("LCM of %d and %d = %lld\n", a, b, lcm);
    return 0;
}
