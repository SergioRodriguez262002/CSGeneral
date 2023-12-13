#include <stdio.h>
#include <stdlib.h>
#include "Printer.h"
#include "Board.h"
int main(){

    char* board = Board();
    printf("%s\n",board);
    Printer(board);
    printChessBoard();



    return 0;
}