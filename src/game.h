#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "controller.h"
#include "gui_object.h"
#include "renderer.h"
#include "snake.h"
#include <memory>
#include <random>

class Game {
 public:
  Game(size_t grid_width, size_t grid_height);
  void Run(Renderer &&renderer, size_t target_frame_duration);
  [[nodiscard]] int GetScore() const;
  [[nodiscard]] int GetSize() const;

 private:
  v_p_gui_objects gui_objects;
  Snake *snake;

  void Update();
  void add_barriers_cage(const size_t &grid_width, const size_t &grid_height);
};

class Frame { //CHA
 public:
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start{}; //todo refactor to class Frame with start/finish
  Uint32 frame_end{};
  Uint32 frame_duration{};
  int frame_count = 0;
  size_t target_frame_duration;
  Game *game;
  Renderer renderer;

  Frame(Game *game, const size_t &target_frame_duration, Renderer &renderer)
      : game(game), target_frame_duration(target_frame_duration), renderer(renderer){};
  void start() { frame_start = SDL_GetTicks(); };
  void end() {
    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_end = SDL_GetTicks();
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(game->GetScore(), frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this Frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct Frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
};

#endif
