#ifndef FOOD_H
#define FOOD_H

#include "DrawnObj.h"
#include "GameMechs.h"
#include "objPos.h"

class Food : public DrawnObj {
private:
  objPos pos;

public:
  Food();
  Food(int x, int y);
  void draw(char **buffer) override;
  void setXY(int x, int y);
  int getX() const;
  int getY() const;
  virtual void eaten(GameMechs *game);
};

#endif
