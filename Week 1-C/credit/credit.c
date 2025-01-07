#include <stdio.h>

long get_credit_card_number(void);
int get_digit_count(long number);
int luhn_algorithm(long number);
void check_card_type(long number);

int main(void)
{
    // Get credit card number from the user
    long card_number = get_credit_card_number();

    // Check if the card passes the Luhn's algorithm
    if (luhn_algorithm(card_number))
    {
        // Check the card type (AMEX, VISA, MASTERCARD)
        check_card_type(card_number);
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

// Function to prompt the user for a valid credit card number
long get_credit_card_number(void)
{
    long number;
    do
    {
        printf("Number: ");
        scanf("%ld", &number);
    }
    while (number < 0);
    return number;
}

// Function to calculate the total number of digits in the card number
int get_digit_count(long number)
{
    int count = 0;
    while (number != 0)
    {
        number /= 10;
        count++;
    }
    return count;
}

// Function to check the card's validity using Luhn's Algorithm
int luhn_algorithm(long number)
{
    int sum = 0;
    int is_second = 0;

    while (number > 0)
    {
        int digit = number % 10;

        // If it's a second digit from the right, multiply it by 2
        if (is_second)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;

        number /= 10;
        is_second = !is_second;
    }

    return (sum % 10 == 0);
}

// Function to determine the card type (AMEX, MASTERCARD, VISA) or INVALID
void check_card_type(long number)
{
    int length = get_digit_count(number);
    long starting_digits = number;

    // Get the first 2 digits for comparison
    while (starting_digits >= 100)
    {
        starting_digits /= 10;
    }

    // American Express: 15 digits, starts with 34 or 37
    if (length == 15 && (starting_digits == 34 || starting_digits == 37))
    {
        printf("AMEX\n");
    }
    // MasterCard: 16 digits, starts with 51, 52, 53, 54, 55
    else if (length == 16 && (starting_digits >= 51 && starting_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    // Visa: 13 or 16 digits, starts with 4
    else if ((length == 13 || length == 16) && (starting_digits / 10 == 4))
    {
        printf("VISA\n");
    }
    // Otherwise, invalid card
    else
    {
        printf("INVALID\n");
    }
}
