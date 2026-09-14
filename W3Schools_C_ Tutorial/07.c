#include <stdio.h>

int main(void) {
    int full_marks = 500;
    int marks_scored = 423;

    // Casting to float first avoids losing precision from integer division
    float percent_score = ((float)marks_scored / full_marks) * 100.0f;

    printf("Total Marks    : %d\n", full_marks);
    printf("Obtained Marks : %d\n", marks_scored);
    printf("Percentage     : %.2f%%\n", percent_score);

    return 0;
}
