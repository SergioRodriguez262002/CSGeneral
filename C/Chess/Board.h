#ifndef BOARD_H
#define BOARD_H

void Board(char map[]); // Faux constructor
int legalMove();
int move(char c1, int n1, char c2, int n2);
int xyConv(char c, int n);


#endif