#ifndef SDL2TEST_GUI_OBJECT_H
#define SDL2TEST_GUI_OBJECT_H

#include "SDL.h"
#include <memory>
#include <random>
#include <vector>
class GuiObject;
using v_p_gui_objects = std::vector<std::unique_ptr<GuiObject>>;
class GuiObject { // CHA

 public:
  explicit GuiObject(v_p_gui_objects *gui_objects) : gui_objects(gui_objects){};
  virtual void update() = 0;
  std::vector<SDL_Point> occupied_squares;
  const v_p_gui_objects *gui_objects;
};

class Food : public GuiObject { //CHA
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

 public:
  explicit Food(const size_t &grid_width, const size_t &grid_height, v_p_gui_objects *gui_objects)
      : engine(dev()),
        random_w(0, static_cast<int>(grid_width - 1)),
        random_h(0, static_cast<int>(grid_height - 1)),
        GuiObject(gui_objects) { randomize_position(); }
  void update() override {} // food is inactive
  void randomize_position() {
    int x, y;
    while (true) {
      // todo check collision
      x = random_w(engine);
      y = random_h(engine);
      // Check that the location is not occupied by a snake item before placing
      // food.
      occupied_squares = {{x, y}};
      return;
    }
  }
};

class Barrier : public GuiObject {
  ;
  void update() override{}; // wall is passive
 public:
  Barrier(const int &x, const int &y, const int height, const int width, v_p_gui_objects *gui_objects) : GuiObject(gui_objects) {
    occupied_squares = {};
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        occupied_squares.emplace_back(SDL_Point{x + i, y + j});
      }
    }
  }
};

#endif //SDL2TEST_GUI_OBJECT_H
