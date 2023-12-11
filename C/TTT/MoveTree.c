#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "MoveTree.h"

Node *root;
char *pMap;
Node *currentNode;
Node *createMoveTree(char map[])
{
    root = (Node *)malloc(sizeof(Node));
    *root->nextMove = (Node *)malloc(9 * sizeof(Node));
    currentNode = root;
    pMap = map;
    return root;
}

int move(int lastMove)
{
    int nextMove = 0;
    
    


    return nextMove;
}

void createNode() {}

int randomMove()
{
    // Seed the random number generator with the current time
    int randomNumber;
    srand(time(NULL));
    if (!movesAvailable())
    {
        return 99;
    }
    do
    {
        // Generate and print a random number between 1 and 9
        randomNumber = rand() % 9 + 1;
        printf("Random machine move %d\n", randomNumber);
        printf("Board %c\n", pMap[randomNumber]);
    } while (pMap[randomNumber - 1] == 'X' || pMap[randomNumber - 1] == 'O');

    return randomNumber;
}
int movesAvailable()
{
    for (int i = 0; i < 9; i++)
    {
        if (pMap[i] != 'X' || pMap[i] != 'O')
        {
            return 1;
        }
    }
    return 0;
}
void emptyMoves()
{
}

int equalGame(char a[], char b[])
{
    for (int i = 0; i < 9; i++)
    {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}