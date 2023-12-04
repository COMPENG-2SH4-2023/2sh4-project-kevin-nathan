#include "ExpandFood.h"

ExpandFood::ExpandFood(int x, int y) : Food(x, y, 'E') {}

void ExpandFood::eaten(GameMechs &game) {
  game.resizeBoard(game.getBoardSizeX() + 1, game.getBoardSizeY() + 1);
}
