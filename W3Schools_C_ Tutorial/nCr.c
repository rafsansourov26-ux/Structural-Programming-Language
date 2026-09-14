#include <stdio.h>

long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

long long nCr(int n, int r) {
    if (r > n) return 0;
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n, r;
    printf("Enter n and r (n >= r): ");
    scanf("%d %d", &n, &r);
    printf("C(%d, %d) = %lld\n", n, r, nCr(n, r));
    return 0;
}
