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

  boardSizeX = DEFAULT_BOARD_WIDTH;
  boardSizeY = DEFAULT_BOARD_HEIGHT;
  borderSize = DEFAULT_BORDER_SIZE;

  player = new Player();

  drawBuffer = new char *[boardSizeY];
  for (int i = 0; i < boardSizeY; i++) {
    drawBuffer[i] = new char[boardSizeX];
  }

  drawnObjList = new DrawnObj *[6];
  drawnObjCount = 0;
}

GameMechs::GameMechs(int boardX, int boardY) {
  input = 0;
  exitFlag = false;

  boardSizeX = boardX;
  boardSizeY = boardY;
  borderSize = DEFAULT_BORDER_SIZE;

  player = new Player();

  drawBuffer = new char *[boardSizeY];
  for (int i = 0; i < boardSizeY; i++) {
    drawBuffer[i] = new char[boardSizeX];
  }

  drawnObjList = new DrawnObj *[6];
  drawnObjCount = 0;
}

GameMechs::~GameMechs() {
  for (int i = 0; i < boardSizeY; i++) {
    delete[] drawBuffer[i];
  }
  delete[] drawBuffer;
  delete[] drawnObjList;
}

bool GameMechs::getExitFlagStatus() const { return exitFlag; }

char GameMechs::getInput() const { return input; }

int GameMechs::getBoardSizeX() const { return boardSizeX; }

int GameMechs::getBoardSizeY() const { return boardSizeY; }

int GameMechs::getBorderSize() const { return borderSize; }

void GameMechs::setExitTrue() { exitFlag = true; }

void GameMechs::setInput(char this_input) { input = this_input; }

void GameMechs::clearInput() { input = 0; }

void GameMechs::draw() const {
  for (int i = 0; i < drawnObjCount; i++) {
    drawnObjList[i]->draw(drawBuffer);
  }

  // draw border
  for (int i = 0; i < boardSizeY; i++) {
    for (int j = 0; j < boardSizeX; j++) {
      if (i == 0 || i == boardSizeY - borderSize) {
        drawBuffer[i][j] = '#';
      } else if (j == 0 || j == boardSizeX - borderSize) {
        drawBuffer[i][j] = '#';
      } else {
        drawBuffer[i][j] = ' ';
      }
    }
  }
}

void GameMechs::flip() const {
  // flip buffer onto screen
  MacUILib_clearScreen();
  for (int i = 0; i < boardSizeY; i++) {
    for (int j = 0; j < boardSizeX; j++) {
      MacUILib_printf("%c", drawBuffer[i][j]);
    }
    MacUILib_printf("\n");
  }
}
