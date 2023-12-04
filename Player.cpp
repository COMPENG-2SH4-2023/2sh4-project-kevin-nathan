#include "Player.h"
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

Player::Player(int x, int y) {
  myDir = STOP;
  playerPosList = new objPosArrayList();
  extendAmt = 0;

  playerPosList->insertHead(objPos(x, y, '@'));
}

// need to free the playerPosList
Player::~Player() { delete playerPosList; }

// input handler to change the direction of the player
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

void Player::movePlayer(GameMechs *game) {
  // get data on head of snake
  objPos snakeHead;
  playerPosList->getHeadElement(snakeHead);
  int x = snakeHead.getX();
  int y = snakeHead.getY();

  // moves player coordinates
  switch (myDir) {
  case UP:
    y -= 1;
    break;
  case DOWN:
    y += 1;
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

  // implement wraparound
  int borderSize = game->getBorderSize();
  int boardSizeX = game->getBoardSizeX();
  int boardSizeY = game->getBoardSizeY();
  x = (x - borderSize + (boardSizeX - 2)) % (boardSizeX - 2 * borderSize) +
      borderSize;
  y = (y - borderSize + (boardSizeY - 2)) % (boardSizeY - 2 * borderSize) +
      borderSize;

  // insert new element at head
  playerPosList->insertHead(objPos(x, y, snakeHead.getSymbol()));
}

// overriden draw function from DrawnObj in order to be able to draw the player
void Player::draw(char **buffer) {
  for (int i = 0; i < playerPosList->getSize(); i++) {
    objPos returnPos;
    playerPosList->getElement(returnPos, i);
    buffer[returnPos.getY()][returnPos.getX()] = i == 0 ? '0' : 'o';
  }
}

// check if the player has collided with itself
bool Player::checkSelfCollision() {
  objPos head;
  playerPosList->getElement(head, 0);
  for (int i = 1; i < playerPosList->getSize(); i++) {
    objPos tail;
    playerPosList->getElement(tail, i);
    if (head.getX() == tail.getX() && head.getY() == tail.getY()) {
      return true;
    }
  }
  return false;
}

// checks if any of the player's segments has collided with a given xy
bool Player::checkCollision(int x, int y) {
  objPos segment;
  for (int i = 0; i < playerPosList->getSize(); i++) {
    playerPosList->getElement(segment, i);
    if (segment.getX() == x && segment.getY() == y) {
      return true;
    }
  }
  return false;
}

// gets the length of the player
int Player::getLength() const { return playerPosList->getSize(); }

// increases extendAmt, which increases the snakes length whenever it moves
void Player::extendBy(int amt) { extendAmt += amt; }

// checks if the tail needs to be extended and extends it
void Player::extend() {
  // don't do anything if the player is not moving
  if (myDir == STOP) {
    return;
  }

  // keep the snake's tail if extendAmt is more than 0
  // essentially lengthens the snake if extendAmt > 0
  if (extendAmt <= 0) {
    playerPosList->removeTail();
  } else {
    extendAmt--;
  }
}
