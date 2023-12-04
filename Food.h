#ifndef FOOD_H
#define FOOD_H

#include "DrawnObj.h"
#include "objPos.h"

class GameMechs;

class Food : public DrawnObj {
protected:
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
