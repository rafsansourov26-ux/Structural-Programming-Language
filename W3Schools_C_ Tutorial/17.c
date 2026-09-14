#include <stdio.h>

int main(void) {
    double first_val = 24.0;
    double second_val = 8.0;
    char chosen_op = '/';

    printf("Calculation: %.2lf %c %.2lf\n", first_val, chosen_op, second_val);

    switch (chosen_op) {
        case '+':
            printf("Result = %.2lf\n", first_val + second_val);
            break;
        case '-':
            printf("Result = %.2lf\n", first_val - second_val);
            break;
        case '*':
            printf("Result = %.2lf\n", first_val * second_val);
            break;
        case '/':
            if (second_val != 0.0) {
                printf("Result = %.2lf\n", first_val / second_val);
            } else {
                printf("Error: Division by zero is undefined.\n");
            }
            break;
        default:
            printf("Error: Unsupported operator '%c'\n", chosen_op);
            break;
    }

    return 0;
}
