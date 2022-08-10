#ifndef SDL2TEST_GUI_OBJECT_H
#define SDL2TEST_GUI_OBJECT_H

#include "SDL.h"
#include <memory>
#include <random>
#include <vector>

class GuiObject;
using v_p_gui_objects = std::vector<std::unique_ptr<GuiObject>>;

// abstract definition of an obect that will be rendered on screen
class GuiObject {

 public:
  explicit GuiObject(v_p_gui_objects *gui_objects) : gui_objects(gui_objects){};
  virtual ~GuiObject() = default;
  virtual void update() = 0;  //called in each cycle while the game is running. modify position, colour, ect.
  std::vector<SDL_Point> occupied_squares; // in game grid

 protected:
  const v_p_gui_objects *gui_objects;
  [[nodiscard]] GuiObject *is_occupied(const int &x, const int &y) const {
    for (const auto &gui_object : *gui_objects) {
      for (const auto &square : gui_object->occupied_squares) {
        if (square.x == x && square.y == y) return gui_object.get();
      }
    }
    return nullptr;
  }
};

#endif //SDL2TEST_GUI_OBJECT_H
