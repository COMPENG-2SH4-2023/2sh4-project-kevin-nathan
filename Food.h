#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "DrawnObj.h"

class Food : public DrawnObj
{
private:
  objPos pos;

public:
  Food();
  Food(int x, int y);
  ~Food();
  void draw(char **buffer) override;
  void setXY(int x, int y);
  int getX() const;
  int getY() const;
};

#endif
