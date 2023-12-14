#include <stdio.h>
#include <stdlib.h>
#include "Board.h"


// Lowercase leters = uppercase - 32
char* Board(){
    char gameState[] = "rnbqkbnrpppppppp                                PPPPPPPPRNBQKBNR";
    return gameState;
}