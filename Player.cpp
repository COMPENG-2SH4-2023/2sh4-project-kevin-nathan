#include "Player.h"
#include "objPosArrayList.h"

Player::Player(GameMechs *thisGMRef) {
  mainGameMechsRef = thisGMRef;
  myDir = STOP;
  objPosArrayList playerPosList;
}

Player::~Player() {}

//TODO fix
void Player::getPlayerPos(objPosArrayList &returnPos) {
  returnPos = objPosArrayList(playerPosList);
}

void Player::updatePlayerDir() {
  char input = mainGameMechsRef->getInput();
  switch (input) {
  case '\e':
    mainGameMechsRef->setExitTrue();
    break;
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

void Player::movePlayer(bool deleteTailFlag) {
  objPos snakeHead;
  playerPosList.getHeadElement(snakeHead);

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

  x = x % mainGameMechsRef->getBoardSizeX();
  y = y % mainGameMechsRef->getBoardSizeY();

  // playerPosList.insertHead(objPos(x, y, symbol));

  // if(!deleteTailFlag){
  //   playerPosList.removeTail();
  // }
}