#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int applicant_age = 20;
    const int MIN_VOTING_AGE = 18;

    bool can_vote = applicant_age >= MIN_VOTING_AGE;

    printf("Candidate Age : %d\n", applicant_age);
    printf("Voting Age    : %d\n", MIN_VOTING_AGE);
    printf("Eligibility   : %d (1 = Eligible, 0 = Ineligible)\n", can_vote);

    if (can_vote) {
        printf("Status        : Eligible to vote in national elections.\n");
    } else {
        printf("Status        : Not eligible to vote yet.\n");
    }

    return 0;
}
