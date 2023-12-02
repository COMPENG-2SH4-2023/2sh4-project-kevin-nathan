#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

#include "DrawnObj.h"

class Player : DrawnObj {
  // Construct the remaining declaration from the project manual.
public:
  enum Dir { UP, DOWN, LEFT, RIGHT, STOP }; // This is the direction state

  Player(GameMechs *thisGMRef);
  ~Player();

  void getPlayerPos(objPosArrayList &returnPos); // Upgrade this in iteration 3.
  void updatePlayerDir();
  void movePlayer(bool deleteTailFlag);

private:
  objPos playerPos; // Upgrade this in iteration 3.
  enum Dir myDir;
  objPosArrayList playerPosList;

  // Need a reference to the Main Game Mechanisms
  GameMechs *mainGameMechsRef;
};

#endif
