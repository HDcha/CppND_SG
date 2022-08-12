///
/// @file
/// @copyright Copyright (C) 2022, Christoph Haupt
///

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "gui_objects/snake.h"

class Controller {
 public:
  static void HandleInput(bool &running, Snake &snake) ;
};

#endif
