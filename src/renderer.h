///
/// @file
/// @copyright Copyright (C) 2022, Christoph Haupt
///

#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"
#include "gui_objects/food.h"
#include "gui_objects/snake.h"
#include <vector>

class Renderer {
 public:
  Renderer();
  ~Renderer();

  void Render(const v_p_gui_objects &gui_objects);
  void Render(const Snake *);
  void Render(const Food *);
  void Render(const GuiObject *gui_object);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Rect block{};
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  std::vector<std::array<uint8_t, 4>> color_palette_snake;
  int snake_color_frame_count = 0;
};

#endif
