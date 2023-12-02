#include "GameMechs.h"
#include "MacUILib.h"
#include "objPos.h"
#include <memory>

#define DEFAULT_BOARD_WIDTH 20
#define DEFAULT_BOARD_HEIGHT 10
#define DEFAULT_BORDER_SIZE 1
#define PLAYER_CHAR '@'
#define FIELD_CHAR ' '

GameMechs::GameMechs() {
  char input = 0;
  bool exitFlag = false;
  bool loseFlag = false;
  int score = 0;

  int boardSizeX = DEFAULT_BOARD_WIDTH;
  int boardSizeY = DEFAULT_BOARD_HEIGHT; 
  int borderSize = DEFAULT_BORDER_SIZE;

  objPos food;
}

GameMechs::GameMechs(int boardX, int boardY) {
  char input = 0;
  bool exitFlag = false;
  bool loseFlag = false;
  int score = 0;

  int boardSizeX = boardX;
  int boardSizeY = boardY;
  int borderSize = DEFAULT_BORDER_SIZE;

  objPos food;

// TODO Add destructor for heap variables
}

bool GameMechs::getExitFlagStatus() const { return exitFlag; }

char GameMechs::getInput() const { return input; }

int GameMechs::getBoardSizeX() const { return boardSizeX; }

int GameMechs::getBoardSizeY() const { return boardSizeY; }

int GameMechs::getBorderSize() const { return borderSize; }

void GameMechs::setExitTrue() { exitFlag = true; }

void GameMechs::setInput(char this_input) { input = this_input; }

void GameMechs::clearInput() { input = 0; }