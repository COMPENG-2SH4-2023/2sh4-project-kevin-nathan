#include "GameMechs.h"
#include "MacUILib.h"
#include "Player.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include <iostream>
using namespace std;

#define DELAY_CONST 100000
#define BOARD_WIDTH 30
#define BOARD_HEIGHT 20

GameMechs *game;

void Initialize();
void GetInput();
void RunLogic();
void DrawScreen();
void LoopDelay();
void CleanUp();
void killScreen();
void winScreen();

int main() {

  Initialize();

  while (game->getGameState() == GameMechs::RUNNING) {
    GetInput();
    RunLogic();
    DrawScreen();
    LoopDelay();
  }

  if (game->getGameState() == GameMechs::LOSE) {
    killScreen();
  }

  CleanUp();
}

void Initialize() {
  MacUILib_init();
  MacUILib_clearScreen();

  srand(time(NULL));

  game = new GameMechs(BOARD_WIDTH, BOARD_HEIGHT);
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

  if (input == '\e') {
    game->setExitTrue();
  }

  game->setInput(input);
}

void RunLogic() { game->update(); }

void DrawScreen() {
  game->draw();
  game->flip();
}

void LoopDelay() { MacUILib_Delay(DELAY_CONST); }

void CleanUp() {
  MacUILib_clearScreen();

  MacUILib_uninit();
}

void killScreen() {
  MacUILib_clearScreen();
  MacUILib_printf("YOU DIED!\n");
  MacUILib_printf("Final Score: %d\n", game->getScore());
  MacUILib_printf("Final Length: %d\n", game->getPlayer().getLength());

  MacUILib_printf("Press ESC to exit");
  while (true) {
    if (MacUILib_hasChar() && MacUILib_getChar() == '\e') {
      break;
    }
    MacUILib_Delay(10);
  }
}