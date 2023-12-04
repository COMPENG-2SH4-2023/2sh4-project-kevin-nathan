#include "objPosArrayList.h"

//initialize with 0 elements
objPosArrayList::objPosArrayList() {
  listSize = 0;
  arrayCapacity = ARRAY_MAX_CAP;
  list = new objPos[arrayCapacity];
}

objPosArrayList::~objPosArrayList() { delete[] list; }

int objPosArrayList::getSize() { return listSize; }

void objPosArrayList::insertHead(objPos thisPos) {
  //shift all elements right
  for (int i = listSize; i > 0; i--) {
    list[i] = list[i - 1];
  }

  //adds new element
  list[0] = thisPos;
  listSize++;
}

void objPosArrayList::insertTail(objPos thisPos) {
  //adds element to end of list and increase size
  list[listSize++] = thisPos;
}

void objPosArrayList::removeHead() {
  //shift all elements left
  for (int i = 0; i < listSize; i++) {
    list[i] = list[i + 1];
  }

  //"removes" last element by decreasing size
  listSize--;
}

void objPosArrayList::removeTail() { listSize--; }

void objPosArrayList::getHeadElement(objPos &returnPos) {
  returnPos = list[0];
}

void objPosArrayList::getTailElement(objPos &returnPos) {
  returnPos = list[listSize - 1];
}

void objPosArrayList::getElement(objPos &returnPos, int index) {
  returnPos = list[index];
}
