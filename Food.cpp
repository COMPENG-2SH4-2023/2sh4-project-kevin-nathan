#include "Food.h"
#include "GameMechs.h"
#include "objPos.h"

Food::Food(int x, int y, char symbol = 'Q') { pos = objPos(x, y, symbol); }

void Food::draw(char **buffer) { buffer[pos.y][pos.x] = pos.symbol; }

void Food::eaten(GameMechs* game){
  game->getPlayer().extendBy(1);
  game->increaseScore(50);
}

int Food::getX() const { return pos.getX(); }
int Food::getY() const { return pos.getY(); }
void Food::setXY(int x, int y) {
  pos.setX(x);
  pos.setY(y);
}
