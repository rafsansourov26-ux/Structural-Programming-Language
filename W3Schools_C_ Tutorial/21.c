#include <stdio.h>

int main(void) {
    int pass_num = 1;

    printf("Executing do-while loop:\n");
    do {
        printf("Iteration pass: %d\n", pass_num);
        pass_num++;
    } while (pass_num <= 5);

    // Shows that a do-while block always runs at least once
    int run_once = 10;
    printf("\nGuaranteed single pass check (condition false from start):\n");
    do {
        printf("Runs at least once, single_run = %d\n", run_once);
        run_once++;
    } while (run_once < 5);

    return 0;
}
