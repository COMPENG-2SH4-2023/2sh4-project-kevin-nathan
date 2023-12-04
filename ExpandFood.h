#include "Food.h"
#include "GameMechs.h"

class ExpandFood : public Food {
public:
  ExpandFood(int x, int y);

  void eaten(GameMechs &game) override;
};
