#include <stdio.h>
#include <stdlib.h>
#include "Teleprinter.h"
#include "MoveTree.h"

int main()
{
    int number;
    char pMap[] = "123456789";
    initializeBoard(pMap);
    printBoard(1, '1');
    printf("%s\n", pMap);

    Node *MoveTree = createMoveTree(pMap);

    while (winState() == 'n')
    {
        printf("Enter move: ");
        if (scanf("%d", &number) != 1)
        {
            // Handling invalid input (non-integer)
            printf("Invalid input. Please enter a valid integer.\n");
            // Clear the input buffer
            while (getchar() != '\n')
                ;
            continue;
        }

        printBoard(number, 'X');
        printf("You entered: %d\n", number);
        if (movesAvailable())
        {
            printBoard(move(number), 'O');
        }
    }
    printf("%c Wins\n", winState());

    return 0;
}
