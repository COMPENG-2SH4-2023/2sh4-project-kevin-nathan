#include "Player.h"
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

// the default constructor calls the other constructor with default values
Player::Player(int x, int y) {
  myDir = STOP;
  playerPosList = new objPosArrayList();

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

// moves the player in the direction it is facing
// deleteTail dictates whether the tail should be deleted or not
// useful for extending the player by one segment per frame
void Player::movePlayer(int boardSizeX, int boardSizeY,
                        bool deleteTail = true) {
  objPos snakeHead;
  playerPosList->getHeadElement(snakeHead);

  int x = snakeHead.getX();
  int y = snakeHead.getY();
  char symbol = snakeHead.getSymbol();

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

  x = (x - 1 + (boardSizeX - 2)) % (boardSizeX - 2) + 1;
  y = (y - 1 + (boardSizeY - 2)) % (boardSizeY - 2) + 1;

  playerPosList->insertHead(objPos(x, y, symbol));

  if (deleteTail) {
    playerPosList->removeTail();
  }
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

// checks if the player has collided with a given position with any of its
// segments
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
