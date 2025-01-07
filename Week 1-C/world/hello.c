#include <stdio.h>

int main() {
    char answer[100];  // Declare a character array to store the input
    printf("What's your name? ");

    // Use fgets to get input from the user
    fgets(answer, 100, stdin);

    // Print the name
    printf("Hello, %s", answer);

    return 0;
}
