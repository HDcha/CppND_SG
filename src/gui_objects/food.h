
#ifndef RAINBOWSNAKEPROJECT_FOOD_H
#define RAINBOWSNAKEPROJECT_FOOD_H
#include "gui_object.h"
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
#include "gui_object.h"
#endif //RAINBOWSNAKEPROJECT_FOOD_H
