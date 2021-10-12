#ifndef NUMSLIDER_H_
#define NUMSLIDER_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define W 5
#define H 3

int gameData[W][H];
int blankX, blankY;

void setupGameData(int randMoves);

void printGameData();

int moveLeft();

int moveRight();

int moveUp();

int moveDown();

int gameOver();
#endif /* NUMSLIDER_H_ */
