#include <stdio.h>

int main(void) {
    const int MASTER_PIN = 1337;
    int typed_pin = 1337;

    printf("Security Access System\n");
    printf("Entered PIN: %d\n", typed_pin);

    if (typed_pin == MASTER_PIN) {
        printf("Verification: Correct PIN.\n");
        printf("Status      : Access Granted. Door unlocked.\n");
    } else {
        printf("Verification: Incorrect PIN.\n");
        printf("Status      : Access Denied. Door remains locked.\n");
    }

    return 0;
}
