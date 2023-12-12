#include <stdio.h>
#include <stdlib.h>
#include "Teleprinter.h"
#include "MoveTree.h"

int main()
{
    int number;
    char pMap[] = "123456789";
    initializeBoard(pMap);
    printf("%s\n", pMap);

    Node *MoveTree = createMoveTree(pMap);

    char cont;

    char b[] = "123456789";
    

    // while (winState() == 'n' || winState() == 'd')
    while (1)
    {
        printBoard();
        printf("Enter move: ");
        if (scanf("%d", &number) != 1 || number < 1 || number > 9 || pMap[number] == 'X' || pMap[number] == 'O')
        {
            // Handling invalid input (non-integer)
            printf("Invalid input. Please enter a valid integer.\n");
            // Clear the input buffer
            while (getchar() != '\n')
                ;
            continue;
        }
        printf("\nYou entered: %d\n", number);
        pMap[number - 1] = 'X';
        int machineMove = move(1);
        if (machineMove != 99)
        {
            pMap[machineMove] = 'O';
        }
        // printBoard();
        if (winState() == 'X' || winState() == 'O')
        {
            printf("%c Wins\n",winState());
            for (int i = 0; i < 9; i++)
            {
                pMap[i] = (char)(i+49);
            }
            resetTree();
            printf("%s\n",pMap);
        }
    }

    return 0;
}
