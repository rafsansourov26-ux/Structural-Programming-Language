#include <stdio.h>

int main(void) {
    int timer = 5;

    printf("Commencing Countdown:\n");
    while (timer > 0) {
        printf("%d...\n", timer);
        timer--;
    }

    printf("Happy New Year!\n");

    return 0;
}
