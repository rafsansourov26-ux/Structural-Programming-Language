#include <stdio.h>

int main(void) {
    int weekday_num = 4;

    printf("Day number: %d\n", weekday_num);
    printf("Weekday   : ");

    switch (weekday_num) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Invalid day index (choose 1-7)\n");
            break;
    }

    return 0;
}
