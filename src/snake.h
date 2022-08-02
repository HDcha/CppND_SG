#ifndef SNAKE_H
#define SNAKE_H

#include "SDL.h"
#include "gui_object.h"
#include <vector>

class Snake : private GuiObject {
 public:
  enum class Direction { kUp,
                         kDown,
                         kLeft,
                         kRight };

  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x((float) grid_width / 2),
        head_y((float) grid_height / 2) {}

  void update() override;

  void GrowBody();
  [[nodiscard]] bool SnakeCell(int x, int y) const;

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif
