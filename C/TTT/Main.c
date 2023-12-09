#include <stdio.h>
#include "Teleprinter.h"

int main() {
    int number;
    printBoard(1, '1');
    
    while (winState() == 'n') {
        printf("Enter move: ");
        if (scanf("%d", &number) != 1) {
            // Handling invalid input (non-integer)
            printf("Invalid input. Please enter a valid integer.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        printBoard(number, 'X');
        printf("You entered: %d\n", number);
    }
    printf("%c Wins\n",winState());

    return 0;
}
