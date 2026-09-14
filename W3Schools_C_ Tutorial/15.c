#include <stdio.h>

int main(void) {
    int exam_score = 78;
    int min_pass_mark = 40;

    const char *outcome = (exam_score >= min_pass_mark) ? "PASSED" : "FAILED";

    int num_x = 45;
    int num_y = 62;
    int larger_value = (num_x > num_y) ? num_x : num_y;

    printf("Exam Score : %d (Passing Mark: %d)\n", exam_score, min_pass_mark);
    printf("Result     : %s\n", outcome);
    printf("Numbers    : %d, %d -> Maximum = %d\n", num_x, num_y, larger_value);

    return 0;
}
