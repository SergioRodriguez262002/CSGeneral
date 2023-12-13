#include <stdio.h>
#include <stdlib.h>
#include "Printer.h"

const char *bgColorRed = "\x1b[41m";
const char *bgColorGreen = "\x1b[42m";
const char *bgColorBlue = "\x1b[44m";
const char *bgColorWhite = "\x1b[47m";
const char *bgColorReset = "\x1b[0m";

// printf("%s%s%s", bgColorWhite, boardSpace, bgColorReset);

char *gameState;
void Printer(char board[])
{
    gameState = board;
    printf("%s\n",gameState);
}

void printChessBoard()
{
    printf("%s",gameState);
    for (int i = 0; i < 8 * 8; i++)
    {
        if (i % 8 == 0)
        { // new board row
            printf("\n%i", (i / 8) + 1);
        }
        printf(" %c ",gameState[i]);

        
    }
    printf("\n  A  B  C  D  E  F  G  H\n");
}

void moveCursor()
{
}