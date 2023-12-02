#ifndef PLAYER_H
#define PLAYER_H

#include "objPos.h"
#include "objPosArrayList.h"

#include "DrawnObj.h"

class Player : public DrawnObj {
public:
  enum Dir { UP, DOWN, LEFT, RIGHT, STOP }; // This is the direction state

  Player();
  ~Player();

  void updatePlayerDir(char input);
  void movePlayer(int boardSizeX, int boardSizeY, bool deleteTailFlag);
  void draw(char** buffer) override;

  bool checkSelfCollision();
  bool checkCollision(int x, int y);

private:
  objPos playerPos; // Upgrade this in iteration 3.
  enum Dir myDir;
  objPosArrayList *playerPosList;
};

#endif
