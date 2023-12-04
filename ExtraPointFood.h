#include "Food.h"
#include "GameMechs.h"

class ExtraPointFood : public Food {
  ExtraPointFood(int x, int y);
  ~ExtraPointFood();

  void eaten(GameMechs *game) override;
};