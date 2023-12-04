#include "LongFood.h"

// default constructor, but uses 'S' as symbol rather then the default 'q'
LongFood::LongFood(int x, int y) : Food(x, y, 'S') {}

// extends plyer length by a random amount between 1-5
void LongFood::eaten(GameMechs &game) {
  game.getPlayer().extendBy(rand() % 5 + 1);
}