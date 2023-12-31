#ifndef FOOD_H
#define FOOD_H

#include "DrawnObj.h"
#include "objPos.h"

class GameMechs;

class Food : public DrawnObj {
protected:
  objPos pos;

public:
  Food(int x, int y, char symbol = 'q');
  void draw(char **buffer) override;
  void setXY(int x, int y);
  int getX() const;
  int getY() const;
  virtual void eaten(GameMechs &game);
};

#endif
