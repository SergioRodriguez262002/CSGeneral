#ifndef MOVETREE_H
#define MOVETREE_H

typedef struct Node
{
    char pMap[9];
    struct Node *nextMove[9];
} Node;

typedef struct MoveTree
{
    Node *root;
} MoveTree;

Node *createMoveTree(char map[]);
int move();

#endif