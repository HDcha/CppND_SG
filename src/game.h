///
/// @file
/// @copyright Copyright (C) 2022, Christoph Haupt
///

#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "controller.h"
#include "gui_objects/gui_object.h"
#include "gui_objects/snake.h"
#include "renderer.h"
#include <memory>
#include <random>

class Game {
 public:
  Game();
  void Run(); // start the game cycle
  [[nodiscard]] int GetScore() const;
  [[nodiscard]] int GetSize() const;

 private:
  v_p_gui_objects gui_objects;
  Snake *snake;

  void Update();
  void add_barriers_cage();
};

#endif
