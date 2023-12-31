#pragma once

#include "Food.h"
#include "GameMechs.h"

// portal food class
// when eaten, the player will teleport to a random location
class PortalFood : public Food {
public:
  PortalFood(int x, int y);

  void eaten(GameMechs &game) override;
};
