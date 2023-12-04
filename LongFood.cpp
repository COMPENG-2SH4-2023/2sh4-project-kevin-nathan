#include "LongFood.h"

LongFood::LongFood(int x, int y) : Food(x, y, 'S') {}

void LongFood::eaten(GameMechs &game) { game.getPlayer().extendBy(rand() % 5 + 1); }