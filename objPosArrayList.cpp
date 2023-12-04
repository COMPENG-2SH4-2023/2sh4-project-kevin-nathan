#include "objPosArrayList.h"

//initialize with 0 elements
objPosArrayList::objPosArrayList() {
  sizeList = 0;
  sizeArray = ARRAY_MAX_CAP;
  aList = new objPos[sizeArray];
}

objPosArrayList::~objPosArrayList() { delete[] aList; }

int objPosArrayList::getSize() { return sizeList; }

void objPosArrayList::insertHead(objPos thisPos) {
  //shift all elements right
  for (int i = sizeList; i > 0; i--) {
    aList[i] = aList[i - 1];
  }

  //adds new element
  aList[0] = thisPos;
  sizeList++;
}

void objPosArrayList::insertTail(objPos thisPos) {
  //adds element to end of list and increase size
  aList[sizeList++] = thisPos;
  sizeList++;
}

void objPosArrayList::removeHead() {
  //shift all element left
  for (int i = 0; i < sizeList; i++) {
    aList[i] = aList[i + 1];
  }

  //"removes" last element by decreasing size
  sizeList--;
}

void objPosArrayList::removeTail() { sizeList--; }

void objPosArrayList::getHeadElement(objPos &returnPos) {
  returnPos = aList[0];
}

void objPosArrayList::getTailElement(objPos &returnPos) {
  returnPos = aList[sizeList - 1];
}

void objPosArrayList::getElement(objPos &returnPos, int index) {
  returnPos = aList[index];
}
