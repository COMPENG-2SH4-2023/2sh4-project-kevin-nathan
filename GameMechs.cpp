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

  score = 0;

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

// main update function
void GameMechs::update() {
  // Update player direction
  player->updatePlayerDir(input);

  // check player collision with food
  bool hasCollision = false;

  int i;
  for (i = 0; i < foodArray->size(); i++) {
    if (player->checkCollision(foodArray->get(i)->getX(),
                               foodArray->get(i)->getY())) {
      hasCollision = true;
      break;
    }
  }

  if (hasCollision) {
    // call the food objects eaten function
    foodArray->get(i)->eaten(this);

    // remove and generate new food
    removeFood(i);
    generateFood();
  }

  player->movePlayer(boardSizeX, boardSizeY);

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
  MacUILib_printf("Score: %d\n", score);
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
    // randomly generate x, y coords until it generates somewhere without a
    // player or food object
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

void GameMechs::increaseScore(int num) { score += num; }
void GameMechs::clearInput() { input = 0; }

// collection of getters and setters
GameMechs::GameState GameMechs::getGameState() const { return gameState; }
char GameMechs::getInput() const { return input; }
int GameMechs::getBoardSizeX() const { return boardSizeX; }
int GameMechs::getBoardSizeY() const { return boardSizeY; }
int GameMechs::getBorderSize() const { return borderSize; }
int GameMechs::getScore() const { return score; }
void GameMechs::setExitTrue() { gameState = EXIT; }
void GameMechs::setRunningTrue() { gameState = RUNNING; }
void GameMechs::setLoseTrue() { gameState = LOSE; }
void GameMechs::setWinTrue() { gameState = WIN; }
void GameMechs::setInput(char this_input) { input = this_input; }
Player &GameMechs::getPlayer() { return *player; }