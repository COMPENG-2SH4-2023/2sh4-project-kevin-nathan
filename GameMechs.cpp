#include "GameMechs.h"
#include "MacUILib.h"
#include "Player.h"
#include "objPos.h"
#include <memory>

#define DEFAULT_BOARD_WIDTH 20
#define DEFAULT_BOARD_HEIGHT 10
#define DEFAULT_BORDER_SIZE 1
#define PLAYER_CHAR '@'
#define FIELD_CHAR ' '
#define BORDER_CHAR '#'

GameMechs::GameMechs() {
  input = 0;
  exitFlag = false;
  loseFlag = false;
  score = 0;

  boardSizeX = DEFAULT_BOARD_WIDTH;
  boardSizeY = DEFAULT_BOARD_HEIGHT;
  borderSize = DEFAULT_BORDER_SIZE;

  player = new Player();

  displayBuffer[boardSizeY][boardSizeX];
  char **displayBuffer;
}

GameMechs::GameMechs(int boardX, int boardY) {
  input = 0;
  exitFlag = false;
  loseFlag = false;
  score = 0;

  boardSizeX = boardX;
  boardSizeY = boardY;
  borderSize = DEFAULT_BORDER_SIZE;

  player = new Player();

  displayBuffer[boardSizeY][boardSizeX];
}

GameMechs::~GameMechs() { delete player; }

bool GameMechs::getExitFlagStatus() const { return exitFlag; }

char GameMechs::getInput() const { return input; }

int GameMechs::getBoardSizeX() const { return boardSizeX; }

int GameMechs::getBoardSizeY() const { return boardSizeY; }

int GameMechs::getBorderSize() const { return borderSize; }

void GameMechs::setExitTrue() { exitFlag = true; }

void GameMechs::setInput(char this_input) { input = this_input; }

void GameMechs::clearInput() { input = 0; }

void GameMechs::generateBoard() {
  for (int i = 0; i < boardSizeY; i++) {
    for (int j = 0; j < boardSizeX; j++) {
      if (i < borderSize || i >= boardSizeY - borderSize || 
          j < borderSize || j >= boardSizeX - borderSize) {
        displayBuffer[i][j] = BORDER_CHAR;
      } else {
        displayBuffer[i][j] = ' ';
      }
    }
  }
}