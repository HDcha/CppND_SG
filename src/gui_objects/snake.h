#ifndef SNAKE_H
#define SNAKE_H

#include "SDL.h"
#include "display_parameters.h"
#include "gui_objects/food.h"
#include "gui_objects/gui_object.h"
#include <vector>

template<int num_of_colors>
class SnakeObj : public GuiObject {

 public:
  enum class Direction // from controller input
  { kUp,
    kDown,
    kLeft,
    kRight };

  SnakeObj(const int &grid_width, const int &grid_height, v_p_gui_objects *gui_objects)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x((float) grid_width / 2),
        head_y((float) grid_height / 2),
        score(0),
        GuiObject(gui_objects) {
    occupied_squares = {{(int) head_x, int(head_y)}};
    set_color_palette<num_of_colors>();
  }

  void update() override // set new position, color
  {
    SDL_Point prev_cell{(int) (head_x), (int) (head_y)}; // We first capture the head's cell before updating.
    UpdateHead();
    SDL_Point current_cell{(int) (head_x), (int) (head_y)}; // Capture the head's cell after updating.

    // update the occupied_squares vector items if the snake head has moved to a new
    // cell.
    if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
      update_tail();
      collision_check(current_cell);
      move_head(current_cell);
    }
  }

  [[nodiscard]] int get_score() const { return score; };

  [[nodiscard]] int get_size() const { return size; }

  Direction direction = Direction::kUp;
  bool alive{true};
  std::vector<std::array<uint8_t, 4>> color_palette; // all colors that are used to draw the snake

 private:
  template<size_t no_colors>
  void set_color_palette() {
    for (size_t i = 0; i < no_colors; i++) {
      float phase = (float) i * 3. / (float) no_colors;
      if (phase > 2)
        color_palette.emplace_back(std::array<uint8_t, 4>{(unsigned char) ((phase - 2) * 0xFF),
                                                          (unsigned char) ((3 - phase) * 0xFF),
                                                          0x00,
                                                          0xFF});
      else if (phase > 1)
        color_palette.emplace_back(std::array<uint8_t, 4>{0x00,
                                                          (unsigned char) ((phase - 1) * 0xFF),
                                                          (unsigned char) ((2 - phase) * 0xFF),
                                                          0xFF});
      else
        color_palette.emplace_back(std::array<uint8_t, 4>{(unsigned char) ((1 - phase) * 0xFF),
                                                          0x00,
                                                          (unsigned char) ((phase) *0xFF),
                                                          0xFF});
    }
  }

  void UpdateHead() {
    switch (direction) {
      case Direction::kUp:
        head_y -= speed;
        break;

      case Direction::kDown:
        head_y += speed;
        break;

      case Direction::kLeft:
        head_x -= speed;
        break;

      case Direction::kRight:
        head_x += speed;
        break;
    }

    // Wrap the Snake around to the beginning if going off of the screen.
    head_x = (float) fmod(head_x + (float) grid_width, grid_width);
    head_y = (float) fmod(head_y + (float) grid_height, grid_height);
  }

  void update_tail() {
    if (!growing) {
      // Remove the tail from the vector.
      occupied_squares.erase(occupied_squares.begin());
    } else {
      growing = false;
      size++;
    }
  }

  void move_head(const SDL_Point &current_head_cell) {
    occupied_squares.push_back(current_head_cell);
  }

  void collision_check(const SDL_Point &new_head_position) {
    if (auto const &gui_object = is_occupied(new_head_position.x, new_head_position.y); gui_object) {
      if (auto food_ptr = dynamic_cast<Food *>(gui_object); food_ptr) {
        growing = true;
        score++;
        speed += 0.02;
        food_ptr->randomize_position();
      } else {
        alive = false;
      }
    }
  }

  float head_x;
  float head_y;
  int score{};
  int size{1};
  float speed{0.1f};
  bool growing{false};
  int grid_width;
  int grid_height;
};

// Explicit template instantiation with our parameters
constexpr size_t len_color_cycle_s = 3;
constexpr size_t no_colors = len_color_cycle_s * kFramesPerSecond;
using Snake = SnakeObj<no_colors>;

#endif
