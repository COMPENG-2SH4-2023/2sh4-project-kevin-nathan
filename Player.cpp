#include "Player.h"
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

Player::Player() {
  myDir = STOP;
  playerPosList = new objPosArrayList();
  playerPosList->insertHead(objPos(5, 5, '@'));
}

Player::~Player() {
  delete playerPosList;
}

void Player::updatePlayerDir(char input) {
  switch (input) {
  case 'W':
    if (myDir != DOWN) {
      myDir = UP;
    }
    break;
  case 'S':
    if (myDir != UP) {
      myDir = DOWN;
    }
    break;
  case 'A':
    if (myDir != RIGHT) {
      myDir = LEFT;
    }
    break;
  case 'D':
    if (myDir != LEFT) {
      myDir = RIGHT;
    }
    break;
  default:
    break;
  }
}

void Player::movePlayer(int boardSizeX, int boardSizeY,
                        bool deleteTailFlag = true) {
  objPos snakeHead;
  playerPosList->getHeadElement(snakeHead);

  int x = snakeHead.getX();
  int y = snakeHead.getY();
  char symbol = snakeHead.getSymbol();

  switch (myDir) {
  case UP:
    y += 1;
    break;
  case DOWN:
    y -= 1;
    break;
  case LEFT:
    x -= 1;
    break;
  case RIGHT:
    x += 1;
    break;
  case STOP:
  default:
    return;
    break;
  }

  x = x % boardSizeX;
  y = y % boardSizeY;

  playerPosList->insertHead(objPos(x, y, symbol));

  if (!deleteTailFlag) {
    playerPosList->removeTail();
  }
}

void Player::draw(char **buffer) {
  for (int i = 0; i < playerPosList->getSize(); i++) {
    objPos returnPos;
    playerPosList->getElement(returnPos, i);
    buffer[returnPos.getY()][returnPos.getX()] = returnPos.getSymbol();
  }
}
