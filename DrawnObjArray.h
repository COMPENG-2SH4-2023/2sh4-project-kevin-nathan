#pragma once

#include "DrawnObj.h"
class DrawnObjArray
{
private:
  DrawnObj** drawnObj;
  int size;
  int capacity;

public:
  DrawnObjArray();
  ~DrawnObjArray();

  int getSize() const;
  int getCapacity() const;
  DrawnObj* get(int nIndex) const;
  void add(DrawnObj* pDrawnObj);
  void remove(int nIndex);
};
