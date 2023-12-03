#include "Food.h"
#include "objPos.h"

// the default constructor calls the other constructor with default values
Food::Food() { Food(2, 2); }
Food::Food(int x, int y) { pos = objPos(x, y, 'Q'); }

void Food::draw(char **buffer) { buffer[pos.y][pos.x] = pos.symbol; }

void Food::setXY(int x, int y) {
  pos.setX(x);
  pos.setY(y);
}

int Food::getX() const { return pos.getX(); }

int Food::getY() const { return pos.getY(); }
