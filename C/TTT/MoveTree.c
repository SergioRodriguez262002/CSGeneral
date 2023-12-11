#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "MoveTree.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

Node *root;
char *pMap;
Node *currentNode;
Node *createMoveTree(char map[])
{
    root = (Node *)malloc(sizeof(Node));
    //*root->nextMove = (Node *)malloc(9 * sizeof(Node));
    currentNode = root;
    pMap = map;
    return root;
}

void resetTree()
{
    currentNode = root;
}
/*
0x14b606970 0x14b704080 0x14b7040e0
0x14b606970
*/
int move(int p2)
{
    printf(ANSI_COLOR_RED "CURRENT NODE\n" ANSI_COLOR_RESET);
    printNode(currentNode);
    int nextMove = 0;
    // if(p2){
    for (int i = 0; i < 9; i++)
    {
        if (currentNode->nextMove[i] != 0x0)
        {
            printf("\t%s\n",currentNode->nextMove[i]->pMap);
            printf("\t%s\n",pMap);
            if (equalGame(currentNode->nextMove[i]->pMap, pMap))
            {
                //currentNode = currentNode->nextMove[currentNode->move];
                currentNode = currentNode->nextMove[i];
                printf(ANSI_COLOR_RED"GAME STATE SEEN BEFORE\n"ANSI_COLOR_RESET);
                printNode(currentNode);
                nextMove = currentNode->move;
                //currentNode = currentNode->nextMove[nextMove];
                return nextMove;
            } //root 0x146f04080 -> 0x148004080 -> 0x1480040e0 -> 0x148004140
              // 0 -> 4 -> 6 -> 7
        }
    }
    printf("Empty node\n");
    // printf("Update pMap\n");
    nextMove = randomMove();
    currentNode->nextMove[nextMove] = (Node *)malloc(sizeof(Node));
    printf(ANSI_COLOR_RED "CURRENT NODE BEFORE UPDATING CHILD NODE\n" ANSI_COLOR_RESET);
    printNode(currentNode);
    currentNode = currentNode->nextMove[nextMove];
    for (int i = 0; i < 9; i++)
    {
        currentNode->pMap[i] = pMap[i];
    }
    printf("Updated pMap %s \n",currentNode->pMap);
    currentNode->move = nextMove;
    printf(ANSI_COLOR_RED "CURRENT NODE AFTER ADDING CHILD NODE\n" ANSI_COLOR_RESET);
    printNode(currentNode);
    return nextMove;

    //}
}

void printNode(Node *node)
{
    printf("Mem  %p \n", node);
    printf("pMap %s \n", node->pMap);
    printf("Move %d \n", node->move);
    for (int i = 0; i < 9; i++)
    {
        printf("\tnextMove[%d] %p \n", i, node->nextMove[i]);
    }
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
        // Generate and print a random number between 0 and 8
        randomNumber = rand() % 8;
        printf("Random machine move %d\n", randomNumber);
        // printf("Board %c\n", pMap[randomNumber]);
    } while (pMap[randomNumber] == 'X' || pMap[randomNumber] == 'O');

    return randomNumber;
}
int movesAvailable()
{
    for (int i = 0; i < 9; i++)
    {
        if (pMap[i] != 'X' && pMap[i] != 'O')
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