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
    //*root->nextMove = (Node *)malloc(9 * sizeof(Node));
    currentNode = root;
    pMap = map;
    return root;
}

int move()
{
    int nextMove = 0;
    if(currentNode->move == 0){
        printf("Empty node\n");
        //printf("Update pMap\n");
        for(int i = 0; i < 9; i++){
            currentNode->pMap[i] = pMap[i];
        }
        //printf("Updated pMap %s \n",currentNode->pMap);
        nextMove = randomMove();
        currentNode->move = nextMove;
        currentNode->nextMove[nextMove] = (Node*)malloc(sizeof(Node));
        printNode(currentNode);
    }
    currentNode = currentNode->nextMove[nextMove];
    return nextMove;
}

void printNode(Node *node){
    printf("Mem  %p \n",node);
    printf("pMap %s \n",node->pMap);
    printf("Move %d \n",node->move);
    for(int i = 0; i < 9; i++){
        printf("\tnextMove[%d] %p \n",i,node->nextMove[i]);
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
        //printf("Board %c\n", pMap[randomNumber]);
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