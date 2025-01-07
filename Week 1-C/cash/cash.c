#include <stdio.h>

int main(void)
{
    int change;

    // Repeatedly prompt the user for a valid amount of change (non-negative integer)
    do
    {
        printf("Change owed: ");
        int result = scanf("%d", &change);

        // Clear the input buffer if invalid input was provided
        while (getchar() != '\n')
            ;

        // Re-prompt if input is not an integer or a non-negative value
        if (result != 1 || change < 0)
        {
            change = -1; // Force loop to continue if invalid
        }
    }
    while (change < 0);

    // Calculate the minimum number of coins needed
    int coins = 0;

    // Quarters (25 cents)
    coins += change / 25;
    change = change % 25;

    // Dimes (10 cents)
    coins += change / 10;
    change = change % 10;

    // Nickels (5 cents)
    coins += change / 5;
    change = change % 5;

    // Pennies (1 cent)
    coins += change;

    // Output the number of coins
    printf("%d\n", coins);

    return 0;
}
