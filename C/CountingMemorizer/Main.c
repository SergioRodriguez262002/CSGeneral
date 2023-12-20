#include <stdio.h>
#include <stdlib.h>
#include "AnyBase.h"

int main()
{

    char inputText[100]; // Assuming a maximum length of 99 characters

    while (1)
    {

        char* num = getPrompt(16);

        printf("Random number %s\n",  num);

        int userInput;

        // Prompt the user for input
        printf("Enter an integer: ");

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
            /*
        if(promptResponse(userInput)){
            printf("Pass\n");
        } else {
            printf("Fail\n");
        }*/
    }

    return 0;
}