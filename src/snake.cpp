#include "snake.h"
#include <algorithm>
#include <cmath>

void Snake::update(std::vector<std::unique_ptr<GuiObject>> *gui_objects) {
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)}; // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)}; // Capture the head's cell after updating.

  // update all the occupied_squares vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    UpdateBody(current_cell, prev_cell, gui_objects);
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

void Snake::UpdateBody(const SDL_Point &current_head_cell, const SDL_Point &prev_head_cell, std::vector<std::unique_ptr<GuiObject>> *gui_objects) {
  // todo add head to occupied_squares
  // Add previous head location to vector
  occupied_squares.push_back(prev_head_cell);

  if (!growing) {
    // Remove the tail from the vector.
    occupied_squares.erase(occupied_squares.begin());
  } else {
    growing = false;
    size++;
  }

  // Check if the snake has collided.
  for (const auto &gui_object : *gui_objects) {
    for (auto const &item : gui_object->occupied_squares) {
      if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
        if (auto food_ptr = dynamic_cast<FoodObject *>(gui_object.get()); food_ptr) {
          growing = true;
          food_ptr->randomize_position();
        } else {
          alive = false;
        }
      }
    }
  }
}

void Snake::GrowBody() { growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) const {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  return std::any_of(occupied_squares.cbegin(), occupied_squares.cend(), [x, y](auto item) { return item.x == x && item.y == y; });
}
