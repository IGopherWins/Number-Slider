#include "numslider.h"

int main(){

  int loop = 1;
  while(loop){
    int userInput =-10;
    printf("Select: [1]-Start [2]-Quit \n");
    fflush(stdout);
    scanf("%d", &userInput);
    switch(userInput){
      case 1:
        setupGameData(5);
        puts("Welcome!");
        printGameData();

        char controls = 'q';
        while(controls){
          printf("Select: [w]-Up [s]-Down [a]-Left [d]-right [q]-Quit \n");
          fflush(stdout);
          while(getchar() != '\n');
          scanf("%c", &userInput);
          switch(userInput){
            case 'q':
            controls = 0;
            break;
            case 'w':
            moveUp();
            printGameData();
            break;
            case 's':
            moveDown();
            printGameData();
            break;
            case 'a':
            moveLeft();
            printGameData();
            break;
            case 'd':
            moveRight();
            printGameData();
            break;
          }
        }
        break;
        case 2:
        loop = 0;
        break;
    }
    gameOver();
  }

  //for(int i = 0; i < 7; i++){
  //  moveLeft();
//    printGameData();
//  }

//  for(int i = 0; i < 3; i++){
//    moveRight();
//    printGameData();
//  }

//  for(int i = 0; i < 5; i++){
//    moveUp();
//    printGameData();
//  }

//  for(int i = 0; i < 5; i++){
//    moveDown();
//    printGameData();
//  }
  return 0;
}
