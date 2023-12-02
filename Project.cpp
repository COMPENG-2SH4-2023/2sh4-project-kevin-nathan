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
char displayBuffer[BOARD_HEIGHT][BOARD_WIDTH];

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

  if (input >= 'a' && input <= 'z') { // convert to uppercase
    input -= 32;
  }

  if(input == '\e'){
    game->setExitTrue();
  }

  game->setInput(input);
}

void RunLogic() {}

void DrawScreen() {
  MacUILib_clearScreen();

  for (int i = 0; i < BOARD_HEIGHT; i++) {
    for (int j = 0; j < BOARD_WIDTH; j++) {
      MacUILib_printf("%c", displayBuffer[i][j]);
    }
    MacUILib_printf("\n");
  }

  MacUILib_printf("Press ESC to quit.\n");
  MacUILib_printf("Border Size: %d\n", game->getBorderSize());
}

void LoopDelay() {
  MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp() {
  MacUILib_clearScreen();

  MacUILib_uninit();
}