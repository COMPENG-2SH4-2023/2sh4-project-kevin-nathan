#ifndef PLAYER_H
#define PLAYER_H

#include "objPos.h"
#include "objPosArrayList.h"

#include "DrawnObj.h"

class Player : DrawnObj {
  // Construct the remaining declaration from the project manual.
public:
  enum Dir { UP, DOWN, LEFT, RIGHT, STOP }; // This is the direction state

  Player();
  ~Player();

  void getPlayerPos(objPosArrayList &returnPos); // Upgrade this in iteration 3.
  void updatePlayerDir(char input);
  void movePlayer(int boardSizeX, int boardSizeY, bool deleteTailFlag);

private:
  objPos playerPos; // Upgrade this in iteration 3.
  enum Dir myDir;
  objPosArrayList playerPosList;
};

#endif
