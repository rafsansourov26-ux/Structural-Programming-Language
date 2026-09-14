#include <stdio.h>

int main(void) {
    int current_hour = 14;

    printf("Current Hour: %02d:00\n", current_hour);

    if (current_hour < 12) {
        printf("Greeting    : Good Morning!\n");
    } else if (current_hour < 18) {
        printf("Greeting    : Good Afternoon!\n");
    } else {
        printf("Greeting    : Good Evening!\n");
    }

    return 0;
}
