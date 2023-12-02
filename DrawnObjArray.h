#pragma once

#include "DrawnObj.h"
class DrawnObjArray
{
private:
  DrawnObj** m_ppDrawnObj;
  int m_nSize;
  int m_nCapacity;

public:
  DrawnObjArray();
  ~DrawnObjArray();

  int getSize() const;
  int getCapacity() const;
  DrawnObj* get(int nIndex) const;
  void add(DrawnObj* pDrawnObj);
  void remove(int nIndex);
};
