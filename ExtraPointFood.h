#include "Food.h"
#include "GameMechs.h"

class ExtraPointFood : public Food {
public:
  ExtraPointFood(int x, int y);

  void eaten(GameMechs &game) override;
};