#include "PortalFood.h"
#include "GameMechs.h"

PortalFood::PortalFood(int x, int y) : Food(x, y, '@') {}

void PortalFood::eaten(GameMechs &game) {
  // when eaten by the player, the player teleports to a random location that is
  // not occupied by the player or food

  int x, y;
  do {
    x = rand() % (game.getBoardSizeX() - 2 * game.getBorderSize()) + game.getBorderSize();
    y = rand() % (game.getBoardSizeY() - 2 * game.getBorderSize()) + game.getBorderSize();
  } while (game.getPlayer().checkCollision(x, y) || game.collidesWithFood(x, y));

  // teleport the player
  game.getPlayer().teleport(x, y);

  // add points to the score equal to the current players length * 50
  game.increaseScore(game.getPlayer().getLength() * 50);
}
