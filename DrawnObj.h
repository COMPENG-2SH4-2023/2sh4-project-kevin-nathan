#pragma once

// Abstract class for objects that can be drawn on the screen
// contains a pure virtual function draw() that takes a buffer
// downstream classes must implement this function to draw themselves
class DrawnObj {
public:
  virtual void draw(char **buffer) = 0;
};
