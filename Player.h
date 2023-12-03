#ifndef PLAYER_H
#define PLAYER_H

#include "objPos.h"
#include "objPosArrayList.h"

#include "DrawnObj.h"

class Player : public DrawnObj {
public:
  // enum for player direction
  enum Dir { UP, DOWN, LEFT, RIGHT, STOP };

  Player(int x, int y);
  ~Player();

  void updatePlayerDir(char input);
  void movePlayer(int boardSizeX, int boardSizeY, bool deleteTail);
  void draw(char **buffer) override;

  bool checkSelfCollision();
  bool checkCollision(int x, int y);

  int getNextX() const;
  int getNextY() const;
  int getLength() const;

  void extendBy(int amt);

private:
  enum Dir myDir;
  objPosArrayList *playerPosList;
  int extendAmt;
};

#endif
