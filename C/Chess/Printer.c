#include <stdio.h>
#include <stdlib.h>
#include "Printer.h"

const char *bgColorRed = "\x1b[41m";
const char *bgColorGreen = "\x1b[42m";
const char *bgColorBlue = "\x1b[44m";
const char *bgColorWhite = "\x1b[47m";
const char *bgColorReset = "\x1b[0m";

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

// printf("%s%s%s", bgColorWhite, boardSpace, bgColorReset);

char *gameState;
void Printer(char *board)
{
    gameState = board;
    // printf("%s\n",gameState);
    printf("test string %s\n", board);
}

void printChessBoard()
{
    // printf("%s\n",gameState);

    for (int i = 0; i < 64; i++)
    {
        if (i % 8 == 0)
        { // new board row
            printf("\n%i ", ((-i / 8) + 8 ));
        }
        if (i % 2 == 0 && (i / 8) % 2 == 0)
        { // even row
            if (isLowercase(gameState[i]))
            {
                printf(ANSI_COLOR_BLUE "%s %c %s" ANSI_COLOR_RESET, bgColorWhite, (int)gameState[i] - 32, bgColorReset);
            }else if(isUppercase(gameState[i]))
            {
                printf(ANSI_COLOR_RED "%s %c %s" ANSI_COLOR_RESET, bgColorWhite, gameState[i], bgColorReset);
            }
            else
            {
                printf("%s %c %s", bgColorWhite, gameState[i], bgColorReset);
            }
            // printf("%s %c %s", bgColorWhite, gameState[i], bgColorReset);
        }
        else if (i % 2 > 0 && (i / 8) % 2 == 1)
        { // odd row
            if (isLowercase(gameState[i]))
            {
                printf(ANSI_COLOR_BLUE "%s %c %s" ANSI_COLOR_RESET, bgColorWhite, (int)gameState[i] - 32, bgColorReset);
            }
            else if(isUppercase(gameState[i]))
            {
                printf(ANSI_COLOR_RED "%s %c %s" ANSI_COLOR_RESET, bgColorWhite, gameState[i], bgColorReset);
            }
            else
            {
                printf("%s %c %s", bgColorWhite, gameState[i], bgColorReset);
            }
            // printf("%s %c %s", bgColorWhite, gameState[i], bgColorReset);
        }
        else
        {

            if (isLowercase(gameState[i]))
            {
                printf(ANSI_COLOR_BLUE " %c " ANSI_COLOR_RESET, (int)gameState[i] - 32);
            }
            else if (isUppercase(gameState[i]))
            {
                printf(ANSI_COLOR_RED " %c " ANSI_COLOR_RESET, gameState[i]);
            }
            else
            {
                printf(" %c ", gameState[i]);
            }
            // printf(" %c ", gameState[i]);
        }
    }
    printf("\n   A  B  C  D  E  F  G  H\n");
}

int isLowercase(char c)
{
    char lowerCase[] = "pqkbnr";
    for (int i = 0; i < 6; i++)
    {
        if (c == lowerCase[i])
        {
            return 1;
        }
    }
    return 0;
}

int isUppercase(char c)
{
    char upperCase[] = "PQKBNR";
    for (int i = 0; i < 6; i++)
    {
        if (c == upperCase[i])
        {
            return 1;
        }
    }
    return 0;
}

void moveCursor()
{
}