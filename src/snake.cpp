#include "snake.h"
#include <algorithm>
#include <cmath>

void Snake::update() {
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

void Snake::UpdateHead() {
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
void Snake::update_tail() {
  if (!growing) {
    // Remove the tail from the vector.
    occupied_squares.erase(occupied_squares.begin());
  } else {
    growing = false;
    size++;
  }
}

void Snake::move_head(const SDL_Point &current_head_cell) {
  occupied_squares.push_back(current_head_cell);
}
void Snake::collision_check(const SDL_Point &current_head_cell) {
  if (auto const &gui_object = is_occupied(current_head_cell.x, current_head_cell.y); gui_object) {
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
