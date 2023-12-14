#include <stdio.h>
#include <stdlib.h>
#include "Printer.h"
//#include "Board.h"
int main()
{

    // char *board = Board();
    char gameState[] = "rnbqkbnrpppppppp                                PPPPPPPPRNBQKBNR";
 
    printf("%s\n", gameState);
    Printer(gameState);
    printChessBoard();

    

    return 0;
}