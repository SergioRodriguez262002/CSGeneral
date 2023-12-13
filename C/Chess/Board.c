#include <stdio.h>
#include <stdlib.h>
#include "Board.h"

char gameState[] = "rnbqkbnrpppppppp                               PPPPPPPPRNBQKBNR";
// Lowercase leters = uppercase - 32
char* Board(){
    return gameState;
}