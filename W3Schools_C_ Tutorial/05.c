#include <stdio.h>

int main(void) {
    int rect_length = 12;
    int rect_width = 7;

    int rect_area = rect_length * rect_width;
    int rect_perimeter = 2 * (rect_length + rect_width);

    printf("Rectangle Dimensions:\n");
    printf("Length    : %d units\n", rect_length);
    printf("Width     : %d units\n", rect_width);
    printf("Area      : %d sq units\n", rect_area);
    printf("Perimeter : %d units\n", rect_perimeter);

    return 0;
}
