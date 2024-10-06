#include<stdio.h>

void findCombinations(int score) {
    int td, td_fg, td_2pt, fg, safety;
    
    printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);

    /*loops through all combos of scores that add up to target score*/
    for (td_2pt = 0; td_2pt * 8 <= score; td_2pt++) {
        for (td_fg = 0; td_fg * 7 <= score; td_fg++) {
            for (td = 0; td * 6 <= score; td++) {
                for (fg = 0; fg * 3 <= score; fg++) {
                    for (safety = 0; safety * 2 <= score; safety++) {
                        int total = td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2;
                        if (total == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                    td_2pt, td_fg, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    /*gets target score and runs loop to find all scores, 0 to end*/
    int score;

    while (1) {
        printf("Enter the NFL score (0 or 1 to STOP): ");
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        findCombinations(score);
    }

    return 0;
}