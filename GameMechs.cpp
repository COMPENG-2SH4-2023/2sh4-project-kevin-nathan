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
    drawBuffer[i] = new char[boardSizeX + 1];
    drawBuffer[i][boardSizeX] = '\0';
  }

  drawnObjArray = new DrawnObjArray();
  drawnObjArray->add(player);
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
    drawBuffer[i] = new char[boardSizeX + 1];
    drawBuffer[i][boardSizeX] = '\0';
  }

  drawnObjArray = new DrawnObjArray();
  drawnObjArray->add(player);
}

GameMechs::~GameMechs() {
  for (int i = 0; i < boardSizeY; i++) {
    delete[] drawBuffer[i];
  }
  delete[] drawBuffer;
  delete drawnObjArray;
}

bool GameMechs::getExitFlagStatus() const { return exitFlag; }

char GameMechs::getInput() const { return input; }

int GameMechs::getBoardSizeX() const { return boardSizeX; }

int GameMechs::getBoardSizeY() const { return boardSizeY; }

int GameMechs::getBorderSize() const { return borderSize; }

void GameMechs::setExitTrue() { exitFlag = true; }

void GameMechs::setInput(char this_input) { input = this_input; }

void GameMechs::clearInput() { input = 0; }

void GameMechs::update() const {
  player->updatePlayerDir(input);
  player->movePlayer(boardSizeX, boardSizeY, true);
}

void GameMechs::draw() const {
  // draw border
  for (int i = 0; i < boardSizeY; i++) {
    for (int j = 0; j < boardSizeX; j++) {
      if (i == 0 || i == boardSizeY - borderSize) {
        drawBuffer[i][j] = BORDER_CHAR;
      } else if (j == 0 || j == boardSizeX - borderSize) {
        drawBuffer[i][j] = BORDER_CHAR;
      } else {
        drawBuffer[i][j] = FIELD_CHAR;
      }
    }
  }

  for (int i = 0; i < drawnObjArray->getSize(); i++) {
    drawnObjArray->get(i)->draw(drawBuffer);
  }
}

void GameMechs::flip() const {
  // flip buffer onto screen
  MacUILib_clearScreen();
  for (int i = 0; i < boardSizeY; i++) {
    MacUILib_printf("%s\n", drawBuffer[i]);
  }
}
