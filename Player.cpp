#include "Player.h"
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

Player::Player() {
  myDir = STOP;
  playerPosList = new objPosArrayList();
  for (int i = 0; i < 5; i++) {
    playerPosList->insertHead(objPos(5, 1 + i, '@'));
  }
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

void Player::draw(char **buffer) {
  for (int i = 0; i < playerPosList->getSize(); i++) {
    objPos returnPos;
    playerPosList->getElement(returnPos, i);
    buffer[returnPos.getY()][returnPos.getX()] = i == 0 ? '0' : 'o';
  }
}

bool Player::checkSelfCollision(){
  objPos head;
  playerPosList->getElement(head, 0);
  for(int i = 1; i < playerPosList->getSize(); i++){
    objPos tail;
    playerPosList->getElement(tail, i);
    if(head.getX() == tail.getX() && head.getY() == tail.getY()){
      return true;
    }
  }
  return false;
}

bool Player::checkCollision(int x, int y){
  objPos segment;
  for(int i = 0; i < playerPosList->getSize(); i++){
    playerPosList->getElement(segment, i);
    if(segment.getX() == x && segment.getY() == y){
      return true;
    }
  }
  return false;
}