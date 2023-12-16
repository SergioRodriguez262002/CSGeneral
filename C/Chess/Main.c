#include <stdio.h>
#include <stdlib.h>
#include "Printer.h"
#include "Board.h"
//#include "Board.h"
int main()
{

    // char *board = Board();
    char gameState[] = "rnbqkbnrpppppppp                                PPPPPPPPRNBQKBNR";
 
    printf("%s\n", gameState);
    Printer(gameState);
    printChessBoard();

    char inputString[100]; // Adjust the size as needed

    printf("Enter a string: ");
    scanf("%s", inputString);

    printf("You entered: %s\n", inputString);

    Board(gameState);

    move( 'B', 2, 'B', 3);

    printChessBoard();


    

    return 0;
}