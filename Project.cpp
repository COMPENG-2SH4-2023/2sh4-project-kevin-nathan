#include "GameMechs.h"
#include "MacUILib.h"
#include "objPos.h"
#include <iostream>
using namespace std;

#define DELAY_CONST 100000
#define BOARD_WIDTH 20
#define BOARD_HEIGHT 10

GameMechs game;

void Initialize();
void GetInput();
void RunLogic();
void DrawScreen();
void LoopDelay();
void CleanUp();

int main() {

  Initialize();

  while (!game.getExitFlagStatus()) {
    GetInput();
    RunLogic();
    DrawScreen();
    LoopDelay();
  }

  CleanUp();
}

void Initialize(void) {
  MacUILib_init();
  MacUILib_clearScreen();

  GameMechs game(BOARD_WIDTH, BOARD_HEIGHT);
}

void GetInput(void) {
  if (MacUILib_hasChar()) {
    game.setInput(MacUILib_getChar());
  }

  if (game.getInput() >= 'a' && game.getInput() <= 'z') { // convert to uppercase
    game.setInput(game.getInput() - 32);
  }
}

void RunLogic() {}

void DrawScreen() {
  game.draw();
  game.flip();
}

void LoopDelay() {
  MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp() {
  MacUILib_clearScreen();

  MacUILib_uninit();
}
