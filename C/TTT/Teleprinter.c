#include <stdio.h>
#include "Teleprinter.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

char *pMap;
void initializeBoard(char map[])
{
    pMap = map;
}
char winState()
{
    // Horizontal wins
    for (int i = 0; i < 3; i++)
    {
        int p = (i * 3);
        if (pMap[6 - p] == pMap[7 - p] && pMap[7 - p] == pMap[8 - p])
        {
            return pMap[6 - p];
        }
    }
    // Vertical wins
    for (int i = 0; i < 3; i++)
    {
        int p = (i - 1);
        if (pMap[1 + p] == pMap[4 + p] && pMap[4 + p] == pMap[7 + p])
        {
            return pMap[1 + p];
        }
    }
    // Horizontal wins

    if (pMap[0] == pMap[4] && pMap[4] == pMap[8])
    {
        return pMap[0];
    }
    if (pMap[2] == pMap[4] && pMap[4] == pMap[6])

    {
        return pMap[2];
    }

    for (int i = 0; i < 9; i++)
    {
        if (pMap[i] != 'X' && pMap[i] != 'O')
        {
            return 'n';
        }
    }

    return 'd';
}

void printBoard()
{
    for (int i = 0; i < 3; i++)
    {
        int p = (i * 3);

        for (int i = 0; i < 3; i++)
        {

            if (pMap[6 - p + i] == 'X')
            {
                printf(ANSI_COLOR_BLUE " %c " ANSI_COLOR_RESET, pMap[6 - p + i]);
            }
            else if (pMap[6 - p + i] == 'O')
            {
                printf(ANSI_COLOR_RED " %c " ANSI_COLOR_RESET, pMap[6 - p + i]);
            }
            else
            {
                printf(" %c ",pMap[6 - p + i]);
            }
            if (i != 2)
                printf("|");
        }

        // printf(" %c | %c | %c", pMap[6 - p], pMap[7 - p], pMap[8 - p]);
        if (i < 2)
        {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}
