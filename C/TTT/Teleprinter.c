#include <stdio.h>
#include "Teleprinter.h"

char* pMap;
void initializeBoard(char map[]){
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

    return 'n';
}

void printBoard(int pos, char player)
{
    if(pos == 99){
        return;
    }
    
    if (pos != 0)
    {
        pMap[pos - 1] = player;
    }
    for (int i = 0; i < 3; i++)
    {
        int p = (i * 3);
        printf(" %c | %c | %c", pMap[6 - p], pMap[7 - p], pMap[8 - p]);
        if (i < 2)
        {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}
