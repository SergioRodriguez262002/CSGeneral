#include <stdio.h>
#include <stdlib.h>
#include "Board.h"


// Lowercase leters = uppercase - 32
char *gameState;
void Board(char map[]){
    gameState = map;
}

int legalMove(){

}

int xyConv(char c, int n){
    int index = 64 - ((n-1)*8) - (73 - (int)c);
}
int move(char c1, int n1, char c2, int n2){
    // PRNBQK

    char piece;

    // H is 72;
    // A is 65; 
    int index1 = xyConv(c1,n1);
    int index2 = xyConv(c1,n2);

    printf("piece at %c%i : %c\n", c1,n1, gameState[index1]);
    printf("move %i to %i \n",index1,index2); 
    /*
    Error codes:
        0 no error legal move
        1 not a valid piece
        2 not a valid move to
    */

   piece = gameState[index1]; // selected position


   if(piece == ' '){
    return 1;
   }

    

    
    switch (piece)
    {
    case 'P':
    case 'p':
        //int checkBounds = (gameState[xyConv((char))])
        if(index2 == index1 - 8 && gameState[index2] == ' '){
            gameState[index2] = gameState[index1];
            gameState[index1] = ' ';
        }

        break;
    
    case 'R':
    case 'r':

    break;

    case 'N':
    case 'n':

    break;

    case 'B':
    case 'b':

    break;

    case 'Q':
    case 'q':

    break;

    case 'K':
    case 'k':

    break;
    
    default:
        break;
    }
    
}