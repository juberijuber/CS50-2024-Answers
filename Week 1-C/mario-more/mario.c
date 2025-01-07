#include <stdio.h>

void print_row(int bricks, int total_height);

int main(void)
{
    // Prompt the user for the pyramid's height
    int n;
    do
    {
        printf("Height: ");
        scanf("%d", &n);
    }
    while (n < 1 || n > 8); // Ensure the height is at least 1

    // Print the double-sided pyramid
    for (int i = 1; i <= n; i++)
    {
        // Print spaces for the left pyramid
        for (int j = 0; j < n - i; j++)
        {
            printf(" ");
        }

        // Print the left pyramid
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        // Print the gap between the two pyramids
        printf("  "); // Two spaces as a gap

        // Print the right pyramid
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}
