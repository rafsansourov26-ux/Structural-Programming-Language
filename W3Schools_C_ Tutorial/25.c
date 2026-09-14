#include <stdio.h>

int main(void) {
    printf("1. 2D Coordinate Grid (3x3):\n");
    for (int r = 1; r <= 3; r++) {
        for (int c = 1; c <= 3; c++) {
            printf("(%d,%d) ", r, c);
        }
        printf("\n");
    }

    printf("\n2. Right-Angled Triangle Pattern:\n");
    int total_rows = 5;
    for (int row = 1; row <= total_rows; row++) {
        for (int star = 1; star <= row; star++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n3. Loop Control (break at 5, skip 3 with continue):\n");
    for (int idx = 1; idx <= 10; idx++) {
        if (idx == 3) {
            continue;
        }
        if (idx == 6) {
            break;
        }
        printf("%d ", idx);
    }
    printf("\n");

    return 0;
}
