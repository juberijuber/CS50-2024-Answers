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
    while (n < 1); // Ensures height is at least 1

    // Print a pyramid of that height
    for (int i = 0; i < n; i++)
    {
        // Print row of bricks, passing the total height
        print_row(i + 1, n);
    }

    return 0;
}

void print_row(int bricks, int total_height)
{
    // Print spaces for right alignment
    for (int i = 0; i < total_height - bricks; i++)
    {
        printf(" ");
    }

    // Print the '#' bricks
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }

    // Move to the next line
    printf("\n");
}
