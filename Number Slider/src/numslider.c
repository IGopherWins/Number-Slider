#include "numslider.h"

void setupGameData(int randMoves){   // Creating the Board with values
  int value = 1;
  for(int j = 0; j < H; j++){
    for(int i = 0; i < W; i++){
      gameData[i][j] = value;
      value++;
    }
  }
  blankX = W-1;
  blankY = H-1;
  gameData[blankX][blankY] = -1;
  srand(time(0));
  int i = 0;
  while(i<randMoves){
    int random = rand() % 4;
    switch(random){
      case 0:
      if (moveUp()) i++;
      break;
      case 1:
      if (moveDown()) i++;
      break;
      case 2:
      if (moveLeft()) i++;
      break;
      case 3:
      if (moveRight()) i++;
      break;
    }
  }
}

void printGameData(){     // Creating the sides of the board
  printf(" ");
  for(int i = 0; i < W; i++) printf("-----");
  printf("\n");

  for(int j = 0; j < H; j++){
      printf("|");
    for(int i = 0; i < W; i++){
      if(gameData[i][j] == -1){
        printf(" [ ] ");
      }else{
        printf("%3d  ",gameData[i][j]);
      }
    }
    printf("|");
    printf("\n");
  }
  printf(" ");
  for(int i = 0; i < W; i++) printf("-----");
  printf("\n");
  fflush(stdout);
}

int moveLeft() {
  int success = 0;
  if(blankX-1 >= 0){
    int swap = gameData[blankX-1][blankY];
    gameData[blankX-1][blankY] = gameData[blankX][blankY];
    gameData[blankX][blankY] = swap;
    blankX = blankX - 1;
    success = 1;
  }
  return success;
}

int moveRight() {
  if(blankX+1 < W){
    int swap = gameData[blankX+1][blankY];
    gameData[blankX+1][blankY] = gameData[blankX][blankY];
    gameData[blankX][blankY] = swap;
    blankX = blankX + 1;
  }
}

int moveUp() {
  if(blankY-1 >= 0){
    int swap = gameData[blankX][blankY-1];
    gameData[blankX][blankY-1] = gameData[blankX][blankY];
    gameData[blankX][blankY] = swap;
    blankY = blankY - 1;
  }
}

int moveDown() {
  if(blankY+1 < H){
    int swap = gameData[blankX][blankY+1];
    gameData[blankX][blankY+1] = gameData[blankX][blankY];
    gameData[blankX][blankY] = swap;
    blankY = blankY + 1;
  }
}

int gameOver(){
 int match = 1;
  int value = 1;
    for(int j = 0; j < H; j++){
      for(int i = 0; i < W; i++){
        if(!(i == W-1 && j == H-1)){
          if(gameData[i][j] != value){
            match = 0;
          }
        }
        value++;
      }
    }
    if(match){
      printf("You Won! \n");
    }else{
      printf("You loose! \n");
    }

  }
