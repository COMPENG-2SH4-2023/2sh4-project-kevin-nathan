#include "GameMechs.h"
#include "MacUILib.h"
#include "Player.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include <iostream>
using namespace std;

#define DELAY_CONST 100000
#define BOARD_WIDTH 20
#define BOARD_HEIGHT 10

GameMechs *game;

void Initialize();
void GetInput();
void RunLogic();
void DrawScreen();
void LoopDelay();
void CleanUp();
void loseScreen();
void winScreen();

int main() {

  Initialize();

  while (game->getGameState() != GameMechs::RUNNING) {
    GetInput();
    RunLogic();
    DrawScreen();
    LoopDelay();
  }

  if(game->getGameState() == GameMechs::LOSE){
    loseScreen();
  }else if(game->getGameState() == GameMechs::WIN){
    winScreen();
  }

  CleanUp();
}

void Initialize() {
  MacUILib_init();
  MacUILib_clearScreen();

  game = new GameMechs(BOARD_WIDTH, BOARD_HEIGHT);
  Player player;
}

void GetInput() {
  char input = 0;
  if (MacUILib_hasChar()) {
    input = MacUILib_getChar();
  }

  // convert to uppercase
  if (input >= 'a' && input <= 'z') { 
    input -= 32;
  }

  if(input == '\e'){
    game->setExitTrue();
  }

  game->setInput(input);
}

void RunLogic() {
  game->update();
}

void DrawScreen() {
  game->draw();
  game->flip();
}

void LoopDelay() {
  MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp() {
  MacUILib_clearScreen();

  MacUILib_uninit();
}

void loseScreen(){
  MacUILib_printf("YOU LOSE!\n");
  MacUILib_printf("Press any key to exit");
  while(!MacUILib_hasChar()){
    MacUILib_Delay(10);
  }
}

void winScreen(){
  MacUILib_printf("YOU WIN!\n");
  MacUILib_printf("Press any key to exit");
  while(!MacUILib_hasChar()){
    MacUILib_Delay(10);
  }
}