#include <stdio.h>

int main(void) {
    int roll_number = 43;
    float grade_point = 3.85f;
    double pi_value = 3.141592653589793;
    char letter_grade = 'A';

    printf("Roll No.   : %d\n", roll_number);
    printf("GPA        : %.2f\n", grade_point);
    printf("Double PI  : %.8lf\n", pi_value);
    printf("Grade      : %c\n", letter_grade);

    return 0;
}
