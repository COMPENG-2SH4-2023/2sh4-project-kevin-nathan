#include "ExtraPointFood.h"

// default constructor, but uses 'Q' as symbol rather then the default 'q'
ExtraPointFood::ExtraPointFood(int x, int y) : Food(x, y, 'Q') {}

// Gives extra points, but does not increase the player's length
void ExtraPointFood::eaten(GameMechs &game) { game.increaseScore(rand() % 10 * 50); }