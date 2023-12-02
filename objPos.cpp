#include "objPos.h"

objPos::objPos() {
  x = 0;
  y = 0;
  symbol = 0; // NULL
}

objPos::objPos(objPos &o) {
  x = o.x;
  y = o.y;
  symbol = o.symbol;
}

objPos::objPos(int xPos, int yPos, char sym) {
  x = xPos;
  y = yPos;
  symbol = sym;
}

void objPos::setObjPos(objPos o) {
  x = o.x;
  y = o.y;
  symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym) {
  x = xPos;
  y = yPos;
  symbol = sym;
}

void objPos::setX(int xPos){ x = xPos; }

void objPos::setY(int yPos){ y = yPos; }

int objPos::getX() const {return this->x;};

int objPos::getY() const {return this->y;};

void objPos::getObjPos(objPos &returnPos) { returnPos.setObjPos(x, y, symbol); }

char objPos::getSymbol() { return symbol; }

bool objPos::isPosEqual(const objPos *refPos) {
  return (refPos->x == x && refPos->y == y);
}

//TODO delete if unnecessary, also delete from .h file
char objPos::getSymbolIfPosEqual(const objPos *refPos) {
  return isPosEqual(refPos) ? getSymbol() : 0;
}
