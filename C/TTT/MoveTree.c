#include <stdio.h>
#include <stdlib.h>
#include "MoveTree.h"

Node *root;
char *pMap;
Node *currentNode;
Node *createMoveTree(char map[])
{
    root = (Node *)malloc(sizeof(Node));
    currentNode = root;
    pMap = map;
    return root;
}

int move(int lastMove)
{
    int nextMove = 0;
    if(currentNode == NULL){ // encountered null node


    }
    if(currentNode->nextMove[lastMove] == NULL){ // encountered no further moves

    }
    
    return 0;
}

void createNode(){}

int randomMove(){
    
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