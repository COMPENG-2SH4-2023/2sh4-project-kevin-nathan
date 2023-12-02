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

int main() {

  Initialize();

  while (!game->getExitFlagStatus()) {
    GetInput();
    RunLogic();
    DrawScreen();
    LoopDelay();
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
