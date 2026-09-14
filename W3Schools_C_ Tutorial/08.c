#include <stdio.h>

int main(void) {
    const float PI_CONST = 3.14159265f;
    const int MINS_IN_HOUR = 60;
    float circle_radius = 5.5f;

    float circle_circumference = 2.0f * PI_CONST * circle_radius;
    float circle_area = PI_CONST * circle_radius * circle_radius;

    printf("Time Constant     : %d minutes in an hour\n", MINS_IN_HOUR);
    printf("Circle Radius     : %.2f\n", circle_radius);
    printf("Circumference     : %.4f\n", circle_circumference);
    printf("Area              : %.4f\n", circle_area);

    return 0;
}
