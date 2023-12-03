#include "GameMechs.h"
#include "MacUILib.h"
#include "Player.h"
#include "objPos.h"
#include <memory>

#include "Food.h"

#define DEFAULT_BORDER_SIZE 1
#define MAX_FOOD 5
#define FIELD_CHAR ' '
#define BORDER_CHAR '#'

GameMechs::GameMechs(int boardX, int boardY) {
  // empty input
  input = 0;
  // currently running
  gameState = RUNNING;

  // read in the board size
  boardSizeX = boardX;
  boardSizeY = boardY;
  borderSize = DEFAULT_BORDER_SIZE;

  // allocate the player and the food array
  // also puts the player at a random position within the board
  player = new Player(rand() % (boardSizeX - 2 * borderSize) + borderSize,
                      rand() % (boardSizeY - 2 * borderSize) + borderSize);
  foodArray = new Array<Food *>();

  // allocate the draw buffer
  drawBuffer = new char *[boardSizeY];
  for (int i = 0; i < boardSizeY; i++) {
    drawBuffer[i] = new char[boardSizeX + 1];
    drawBuffer[i][boardSizeX] = '\0';
  }

  // allocate the objects to draw array and add the player
  drawnObjArray = new Array<DrawnObj *>();
  drawnObjArray->add(player);

  // generate initial food
  generateFood();
}

GameMechs::~GameMechs() {
  // free the draw buffer
  for (int i = 0; i < boardSizeY; i++) {
    delete[] drawBuffer[i];
  }
  delete[] drawBuffer;

  // free the player
  delete player;

  // free the food
  for (int i = 0; i < foodArray->size(); i++) {
    delete foodArray->get(i);
  }
  delete foodArray;

  // free the objects to draw
  delete drawnObjArray;
}

// collection of getters and setters
GameMechs::GameState GameMechs::getGameState() const { return gameState; }
char GameMechs::getInput() const { return input; }
int GameMechs::getBoardSizeX() const { return boardSizeX; }
int GameMechs::getBoardSizeY() const { return boardSizeY; }
int GameMechs::getBorderSize() const { return borderSize; }
void GameMechs::setExitTrue() { gameState = EXIT; }
void GameMechs::setRunningTrue() { gameState = RUNNING; }
void GameMechs::setLoseTrue() { gameState = LOSE; }
void GameMechs::setWinTrue() { gameState = WIN; }
void GameMechs::setInput(char this_input) { input = this_input; }
void GameMechs::clearInput() { input = 0; }

// main update function
void GameMechs::update() {
  // Update player
  player->updatePlayerDir(input);

  // check player collision with food
  bool hasCollision = false;
  for (int i = 0; i < foodArray->size(); i++) {
    if (player->checkCollision(foodArray->get(i)->getX(),
                               foodArray->get(i)->getY())) {
      // we have a collision so remove the food and generate a new one
      removeFood(i);
      generateFood();
      hasCollision = true;
      break;
    }
  }

  // if there was no collision, just move the player
  // otherwise, extend the player and move it
  if (hasCollision) {
    player->movePlayer(boardSizeX, boardSizeY, false);
  } else {
    player->movePlayer(boardSizeX, boardSizeY, true);
  }

  // check if the player has collided with itself
  if (player->checkSelfCollision()) {
    gameState = LOSE;
  }
}

// draws everything to the draw buffer but does not flip it
void GameMechs::draw() const {
  // draw border and clear the draw buffer
  for (int i = 0; i < boardSizeY; i++) {
    for (int j = 0; j < boardSizeX; j++) {
      if (i == 0 || i == boardSizeY - borderSize) {
        // top and bottom border
        drawBuffer[i][j] = BORDER_CHAR;
      } else if (j == 0 || j == boardSizeX - borderSize) {
        // left and right border
        drawBuffer[i][j] = BORDER_CHAR;
      } else {
        // empty space
        drawBuffer[i][j] = FIELD_CHAR;
      }
    }
  }

  for (int i = 1; i < drawnObjArray->size(); i++) {
    drawnObjArray->get(i)->draw(drawBuffer);
  }
  // always draw the player last
  drawnObjArray->get(0)->draw(drawBuffer);
}

// flip the draw buffer onto the screen
void GameMechs::flip() const {
  // flip buffer onto screen
  MacUILib_clearScreen();
  for (int i = 0; i < boardSizeY; i++) {
    MacUILib_printf("%s\n", drawBuffer[i]);
  }
  // print the length of the player
  MacUILib_printf("Length: %d\n", player->getLength());
}

// remove the food at the given index
void GameMechs::removeFood(int index) {
  // remove from the objects to draw array
  // this is offset by 1 because the player is always at index 0
  drawnObjArray->remove(index + 1);
  // delete the food
  delete foodArray->get(index);
  // remove from the food array
  foodArray->remove(index);
}

// generate food until there are MAX_FOOD on the board
void GameMechs::generateFood() {
  while (foodArray->size() < MAX_FOOD) {
    // randomly generate x, y coords until it does not generate on a player or
    // collides with another food
    int x, y;
    do {
      x = rand() % (boardSizeX - 2 * borderSize) + borderSize;
      y = rand() % (boardSizeY - 2 * borderSize) + borderSize;
    } while (player->checkCollision(x, y) || collidesWithFood(x, y));

    // add the food to the arrays
    foodArray->add(new Food(x, y));
    drawnObjArray->add(foodArray->get(foodArray->size() - 1));
  }
}

// checks if the given x, y coords collide with any food
bool GameMechs::collidesWithFood(int x, int y) {
  // loop through all food
  for (int i = 0; i < foodArray->size(); i++) {
    // if the food is at the given coords, return true
    if (foodArray->get(i)->getX() == x && foodArray->get(i)->getY() == y) {
      return true;
    }
  }
  return false;
}
