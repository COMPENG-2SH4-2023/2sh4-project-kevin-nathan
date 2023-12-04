#include "objPos.h"

objPos::objPos() {
  x = 0;
  y = 0;
  symbol = 0;
}

// Deep copy constructor
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

// overwrites all fields with the parameter's fields
void objPos::setObjPos(objPos o) {
  x = o.x;
  y = o.y;
  symbol = o.symbol;
}

// sets all fields at once
void objPos::setObjPos(int xPos, int yPos, char sym) {
  x = xPos;
  y = yPos;
  symbol = sym;
}

bool objPos::isPosEqual(const objPos *refPos) {
  return (refPos->x == x && refPos->y == y);
}

char objPos::getSymbolIfPosEqual(const objPos *refPos) {
  return isPosEqual(refPos) ? getSymbol() : 0;
}

//collection of getters and setters
void objPos::setX(int xPos) { x = xPos; }
void objPos::setY(int yPos) { y = yPos; }
int objPos::getX() const { return this->x; };
int objPos::getY() const { return this->y; };
char objPos::getSymbol() { return symbol; }
void objPos::getObjPos(objPos &returnPos) { returnPos.setObjPos(x, y, symbol); }