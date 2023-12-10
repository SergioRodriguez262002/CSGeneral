#include <stdio.h>
#include <stdlib.h>
#include "MoveTree.h"

Node* root;
char *pMap;
Node* createMoveTree(char map[]){
    root = (Node*)malloc(sizeof(Node));
    pMap = map;
    return root;
}

int move(){
    printf("test %s\n",pMap);
    return 0;
}