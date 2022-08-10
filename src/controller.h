#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "gui_objects/snake.h"

class Controller {
 public:
  static void HandleInput(bool &running, Snake &snake) ;

 private:
  static void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) ;
};

#endif
