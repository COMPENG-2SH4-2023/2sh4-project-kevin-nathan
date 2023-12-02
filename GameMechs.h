#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "DrawnObj.h"
#include "DrawnObjArray.h"
#include "objPos.h"
#include "objPosArrayList.h"

#include "Player.h"

using namespace std;

class GameMechs {
  // Construct the remaining declaration from the project manual.

  // Only some sample members are included here

  // You will include more data members and member functions to complete your
  // design.

public:
  enum GameState {RUNNING, WIN, LOSE, EXIT};

private:
  char input;

  int boardSizeX;
  int boardSizeY;
  int borderSize;

  GameState gameState;

  Player *player;

  char **drawBuffer;
  DrawnObjArray *drawnObjArray;

public:
  GameMechs();
  GameMechs(int boardX, int boardY);
  ~GameMechs();

  GameState getGameState() const;
  void setExitTrue();

  char getInput() const;
  void setInput(char this_input);
  void clearInput();

  int getBoardSizeX() const;
  int getBoardSizeY() const;
  int getBorderSize() const;

  void update() const;

  void setRunningTrue();
  void setLoseTrue();
  void setWinTrue();

  void draw() const;
  void flip() const;
};

#endif
