#ifndef SNAKE_H
#define SNAKE_H

#include "SDL.h"
#include "gui_object.h"
#include <vector>

class Snake : public GuiObject {
 public:
  enum class Direction { kUp,
                         kDown,
                         kLeft,
                         kRight };

  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x((float) grid_width / 2),
        head_y((float) grid_height / 2),
        score(0) {}

  void update(std::vector<std::unique_ptr<GuiObject>> *gui_objects) override;

  Direction direction = Direction::kUp;
  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  int score{};

 private:
  void UpdateHead();
  void UpdateBody(const SDL_Point &current_head_cell, const SDL_Point &prev_head_cell, std::vector<std::unique_ptr<GuiObject>> *gui_objects);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif
