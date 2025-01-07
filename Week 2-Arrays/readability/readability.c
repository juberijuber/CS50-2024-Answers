#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> // Added to include isalpha() and isspace()
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int get_grade_level(int letters, int words, int sentences); // Changed function name to follow naming conventions

int main(void)
{
    // Get input text from the user
    string text = get_string("Text: ");

    // Count letters, words, and sentences
    int cl = count_letters(text);
    int cw = count_words(text);
    int cs = count_sentences(text);

    // Calculate the grade level
    int grade_level = get_grade_level(cl, cw, cs);

    // Print the grade level in the required format
    if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade_level);
    }

    return 0;
}

int count_letters(string text)
{
    int count = 0;

    // Count alphabetic characters in the text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }

    return count;
}

int count_words(string text)
{
    int count = 0;

    // Count spaces to determine the number of words
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }

    // Adding one to account for the last word (if the text is non-empty)
    return count + 1;
}

int count_sentences(string text)
{
    int count = 0;

    // Count punctuation marks that indicate sentence endings
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    return count;
}

int get_grade_level(int letters, int words, int sentences)
{
    // Calculate the L and S values for the Coleman-Liau index
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    // Return the rounded Coleman-Liau index
    return round(0.0588 * L - 0.296 * S - 15.8);
}
