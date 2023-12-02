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
  void draw(char **buffer) override;
};

#endif
