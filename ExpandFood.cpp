#include "ExpandFood.h"

// default constructor, but uses 'E' as symbol rather then the default 'q'
ExpandFood::ExpandFood(int x, int y) : Food(x, y, 'E') {}

// expands the board by 1 in each direction
void ExpandFood::eaten(GameMechs &game) {
  game.resizeBoard(game.getBoardSizeX() + 1, game.getBoardSizeY() + 1);
}
