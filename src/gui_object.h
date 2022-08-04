#ifndef SDL2TEST_GUI_OBJECT_H
#define SDL2TEST_GUI_OBJECT_H

#include "SDL.h"
#include <memory>
#include <random>
#include <vector>

class GuiObject { // CHA

 public:
  virtual void update(std::vector<std::unique_ptr<GuiObject>> *gui_objects) = 0;
  std::vector<SDL_Point> occupied_squares;
};

class Food : public GuiObject { //CHA
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

 public:
  explicit Food(const size_t &grid_width, const size_t &grid_height)
      : engine(dev()),
        random_w(0, static_cast<int>(grid_width - 1)),
        random_h(0, static_cast<int>(grid_height - 1)) { randomize_position(); }
  void update(std::vector<std::unique_ptr<GuiObject>> *gui_objects) override {} // food is inactive
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
  void update(std::vector<std::unique_ptr<GuiObject>> *gui_objects) override{}; // wall is passive
 public:
  Barrier(const int &x, const int &y, const int height, const int width) {
    occupied_squares = {};
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        occupied_squares.emplace_back(SDL_Point{x + i, y + j});
      }
    }
  }
};

#endif //SDL2TEST_GUI_OBJECT_H
