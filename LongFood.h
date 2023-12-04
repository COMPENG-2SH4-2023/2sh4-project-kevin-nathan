#include "Food.h"
#include "GameMechs.h"

class LongFood : public Food {
public:
  LongFood(int x, int y);

  void eaten(GameMechs &game) override;
};