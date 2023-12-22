#include <stdio.h>
#include <stdlib.h>
#include "AnyBase.h"
#include "Printer.h"

int main()
{

    char inputText[100]; // Assuming a maximum length of 99 characters
    int base;
    char buffer[100];  // Buffer to store user input

    do{
        // Prompt user for input
        printf("Enter the base (2-16): ");

        // Read user input as a string
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            // Handle input error
            fprintf(stderr, "Error reading input.\n");
            return 1;
        }

        // Convert the string to an integer
        if (sscanf(buffer, "%d", &base) == 1) {
            // Conversion successful, break out of the loop
            break;
        } else {
            // Invalid input, prompt the user again
            fprintf(stderr, "Invalid input. Please enter a valid integer.\n");
        }
    }while(sscanf(buffer, "%d", &base) != 1);

    while (1)
    {

        char* num = getPrompt(base);

        printf(" %s\n",  num);

        int userInput;

        // Prompt the user for input
        printPrompt(num, base);

        // Read the integer from the user
        if (scanf("%d", &userInput) == 1)
        {
            // The input was successfully read
            printf("You entered: %d\n", userInput);
        }
        else
        {
            // An error occurred while reading the input
            printf("Invalid input\n");
        }
        if(promptResponse(userInput)){
            printf("Pass\n");
        } else {
            printf("Fail\n");
        }
    }

    return 0;
}