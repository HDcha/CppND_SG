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

  Snake(int grid_width, int grid_height, v_p_gui_objects *gui_objects)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x((float) grid_width / 2),
        head_y((float) grid_height / 2),
        score(0),
        GuiObject(gui_objects) {
    occupied_squares = {{(int) head_x, int(head_y)}};
  }

  void update() override;

  Direction direction = Direction::kUp;
  bool alive{true};
  [[nodiscard]] int get_score() const { return score; };
  [[nodiscard]] int get_size() const { return size; }

 private:
  void UpdateHead();
  void update_tail();
  void move_head(const SDL_Point &current_head_cell);
  void collision_check(const SDL_Point &new_head_position);

  float head_x;
  float head_y;
  int score{};
  int size{1};
  float speed{0.1f};
  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif
