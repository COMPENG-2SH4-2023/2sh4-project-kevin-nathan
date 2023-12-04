#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "DrawnObj.h"
#include "Array.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Player.h"
#include "Food.h"

using namespace std;

class GameMechs {
public:
  // enum for game state
  enum GameState {RUNNING, LOSE, EXIT};

private:
  // holds the currently buffered input
  char input;
  // holds the current game state
  GameState gameState;

  // board configuration
  int boardSizeX;
  int boardSizeY;
  int borderSize;

  // player and food objects
  Player *player;
  Array<Food*> *foodArray;
  int score;

  // double buffered screen
  // this gets flipped to the actual screen after everything has been drawn
  char **drawBuffer;

  // array of stuff that should be drawn
  Array<DrawnObj*> *drawnObjArray;

public:
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
  int getScore() const;
  Player& getPlayer();

  void update();

  void removeFood(int i);
  void generateFood();
  bool collidesWithFood(int x, int y);

  void setRunningTrue();
  void setLoseTrue();

  void resizeBoard(int x, int y);
  void draw() const;
  void flip() const;

  void increaseScore(int num);
};

#endif
