#include "Food.h"

Food::Food() {
  pos = objPos(0, 0, 'Q');
}

Food::Food(int x, int y) {
  pos = objPos(x, y, 'Q');
}

void Food::draw(char **buffer) {
  buffer[pos.y][pos.x] = pos.symbol;
}
