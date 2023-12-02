#include "DrawnObjArray.h"

DrawnObjArray::DrawnObjArray() {
  size = 0;
  capacity = 1;
  drawnObj = new DrawnObj*[capacity];
}

DrawnObjArray::~DrawnObjArray() {
  delete[] drawnObj;
}

int DrawnObjArray::getSize() const {
  return size;
}

int DrawnObjArray::getCapacity() const {
  return capacity;
}

DrawnObj* DrawnObjArray::get(int nIndex) const {
  return drawnObj[nIndex];
}

void DrawnObjArray::add(DrawnObj* pDrawnObj) {
  if (size == capacity) {
    capacity *= 2;
    DrawnObj** ppTemp = new DrawnObj*[capacity];
    for (int i = 0; i < size; i++) {
      ppTemp[i] = drawnObj[i];
    }
    delete[] drawnObj;
    drawnObj = ppTemp;
  }
  drawnObj[size] = pDrawnObj;
  size++;
}

void DrawnObjArray::remove(int nIndex) {
  for (int i = nIndex; i < size - 1; i++) {
    drawnObj[i] = drawnObj[i + 1];
  }
  size--;
}
