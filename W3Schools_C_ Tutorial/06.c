#include <stdio.h>

int main(void) {
    int quantity = 45;
    float price_each = 8.75f;
    char currency_symbol = '$';

    float grand_total = quantity * price_each;

    printf("--- Purchase Summary ---\n");
    printf("Quantity      : %d\n", quantity);
    printf("Unit Price    : %c%.2f\n", currency_symbol, price_each);
    printf("Total Amount  : %c%.2f\n", currency_symbol, grand_total);

    return 0;
}
