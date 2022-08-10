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

class Food : public GuiObject { //CHA

 public:
  explicit Food(const size_t &grid_width, const size_t &grid_height, v_p_gui_objects *gui_objects)
      : engine(dev()),
        random_w(0, static_cast<int>(grid_width - 1)),
        random_h(0, static_cast<int>(grid_height - 1)),
        GuiObject(gui_objects) { randomize_position(); }
  void update() override {} // food is inactive
  void randomize_position() // reset position in game grid
  {
    int x, y;
    do {
      x = random_w(engine);
      y = random_h(engine);
    } while (is_occupied(x, y));
    occupied_squares = {{x, y}};
  }

 private:
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
};

class Barrier : public GuiObject {
 public:
  Barrier(const int &x, const int &y, const int height, const int width, v_p_gui_objects *gui_objects) : GuiObject(gui_objects) {
    occupied_squares = {};
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        occupied_squares.emplace_back(SDL_Point{x + i, y + j});
      }
    }
  }
  void update() override{}; // barrier is passive
};

#endif //SDL2TEST_GUI_OBJECT_H
