#include "Food.h"
#include "GameMechs.h"
#include "objPos.h"

// constructor
Food::Food(int x, int y, char symbol) { pos = objPos(x, y, symbol); }

// draw the food to the buffer
void Food::draw(char **buffer) { buffer[pos.y][pos.x] = pos.symbol; }

// when the food is eaten, the player is extended by 1 and the score is increased
void Food::eaten(GameMechs &game){
  game.getPlayer().extendBy(1);
  game.increaseScore(50);
}

// getters and setters
int Food::getX() const { return pos.getX(); }
int Food::getY() const { return pos.getY(); }
void Food::setXY(int x, int y) {
  pos.setX(x);
  pos.setY(y);
}
