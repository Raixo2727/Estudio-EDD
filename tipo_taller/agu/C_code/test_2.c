# include <stdio.h>

// División entre ints y resultado en decimal (float o double)

int main(int argc, char const *argv[])
{
    float x = 5;
    float y = 2;
    float sum = (float) x / y;

    printf("%.2f\n", sum);

    // Set the maximum possible score in the game to 500
    int maxScore = 500;

    // The actual score of the user
    int userScore = 423;

    /* Calculate the percantage of the user's score in relation to the maximum available score.
    Convert userScore to float to make sure that the division is accurate */
    float percentage = (float) userScore / maxScore * 100.0;

    // Print the percentage
    printf("User's percentage is %.2f", percentage);

    return 0;
}


