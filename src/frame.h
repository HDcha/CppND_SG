///
/// @file
/// @copyright Copyright (C) 2022, Christoph Haupt
///

#ifndef RAINBOWSNAKEPROJECT_FRAME_H
#define RAINBOWSNAKEPROJECT_FRAME_H

class Frame {

 public:
  Frame(Game *game, Renderer &renderer)
      : game(game),
        renderer(renderer){};

  void start() // save the current time
  { frame_start = SDL_GetTicks(); };

  void end() // modifies game title and waits until the frame has ended.
  {
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
    if (frame_duration < kMsPerFrame) {
      SDL_Delay(kMsPerFrame - frame_duration);
    }
  }

 private:
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start{};
  Uint32 frame_end{};
  Uint32 frame_duration{};
  int frame_count = 0;
  Game *game;
  Renderer renderer;
};
#include "game.h"
#endif //RAINBOWSNAKEPROJECT_FRAME_H
