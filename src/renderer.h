#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"
#include "snake.h"
#include <vector>

class Renderer {
 public:
  Renderer(const size_t &screen_width, const size_t &screen_height,
           const size_t &grid_width, const size_t &grid_height);
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

  const size_t screen_width;
  const size_t screen_height;
  const size_t grid_width;
  const size_t grid_height;
};

#endif
