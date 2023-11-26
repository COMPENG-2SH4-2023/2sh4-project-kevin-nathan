#include "MacUILib.h"
#include "objPos.h"
#include <iostream>
using namespace std;

#define DELAY_CONST 100000

void Initialize();
void GetInput();
void RunLogic();
void DrawScreen();
void LoopDelay();
void CleanUp();

int main() {

  Initialize();

  while (exitFlag == false) {
    GetInput();
    RunLogic();
    DrawScreen();
    LoopDelay();
  }

  CleanUp();
}

void Initialize(void) {
  MacUILib_init();
  MacUILib_clearScreen();

  exitFlag = false;
}

void GetInput(void) {
  if (MacUILib_hasChar()) {
    //TODO do something
  }

  // TODO modify later
  /*
  if (input >= 'a' && input <= 'z') { // convert to uppercase
    input -= 32;
  }
  */
}

void RunLogic() {}

void DrawScreen() { MacUILib_clearScreen(); }

void LoopDelay() {
  MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp() {
  MacUILib_clearScreen();

  MacUILib_uninit();
}
