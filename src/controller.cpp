///
/// @file
/// @copyright Copyright (C) 2022, Christoph Haupt
///

#include "controller.h"
#include "SDL.h"
#include "gui_objects/snake.h"

void Controller::HandleInput(bool &running, Snake &snake) {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          snake.set_direction_if_possible(Snake::Direction::kUp);
          break;

        case SDLK_DOWN:
          snake.set_direction_if_possible(Snake::Direction::kDown);
          break;

        case SDLK_LEFT:
          snake.set_direction_if_possible(Snake::Direction::kLeft);
          break;

        case SDLK_RIGHT:
          snake.set_direction_if_possible(Snake::Direction::kRight);
          break;
      }
    }
  }
}
