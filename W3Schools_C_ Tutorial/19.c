#include <stdio.h>

int main(void) {
    int current_face = 1;

    printf("Simulating dice progression:\n");
    while (current_face <= 6) {
        if (current_face < 6) {
            printf("Rolled %d -> No Yatzy, continuing...\n", current_face);
        } else {
            printf("Rolled %d -> Yatzy! Target reached!\n", current_face);
        }
        current_face++;
    }

    return 0;
}
