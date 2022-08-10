///
/// @file
/// @copyright Copyright (C) 2022, Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
///
#ifndef RAINBOWSNAKEPROJECT_BARRIER_H
#define RAINBOWSNAKEPROJECT_BARRIER_H

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
#include "gui_object.h"
#endif //RAINBOWSNAKEPROJECT_BARRIER_H
