#ifndef SDL2TEST_GUI_OBJECT_H
#define SDL2TEST_GUI_OBJECT_H

#include "SDL.h"
#include <vector>

class GuiObject {
  virtual void update() = 0;
  std::vector<SDL_Point> occupied_squares;
};

class [[maybe_unused]] food {
};

#endif //SDL2TEST_GUI_OBJECT_H
