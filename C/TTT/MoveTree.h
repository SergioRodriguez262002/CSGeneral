#ifndef MOVETREE_H
#define MOVETREE_H

typedef struct Node
{
    char pMap[9];
    int move;
    int layer;
    struct Node *nextMove[9];
} Node;

typedef struct MoveTree
{
    Node *root;
} MoveTree;

Node *createMoveTree(char map[]);
int move();
int randomMove();
int movesAvailable();
char copyCurrentMap();
void printNode(Node *node);

#endif