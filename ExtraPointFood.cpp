#include "ExtraPointFood.h"

ExtraPointFood::ExtraPointFood(int x, int y) : Food(x, y, 'Q'){}

void ExtraPointFood::eaten(GameMechs *game){
  game->increaseScore(250);
}