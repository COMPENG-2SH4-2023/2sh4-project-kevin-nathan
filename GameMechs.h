#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "DrawnObj.h"
#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class GameMechs {
  // Construct the remaining declaration from the project manual.

  // Only some sample members are included here

  // You will include more data members and member functions to complete your
  // design.

private:
  char input;
  bool exitFlag;

  int boardSizeX;
  int boardSizeY;
  int borderSize;

  char **drawBuffer;
  DrawnObj **drawnObjList;
  int drawnObjCount;

public:
  GameMechs();
  GameMechs(int boardX, int boardY);
  ~GameMechs();

  bool getExitFlagStatus() const;
  void setExitTrue();

  char getInput() const;
  void setInput(char this_input);
  void clearInput();

  int getBoardSizeX() const;
  int getBoardSizeY() const;
  int getBorderSize() const;

  void draw() const;
  void flip() const;
};

#endif
