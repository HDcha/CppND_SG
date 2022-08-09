#include "display_parameters.h"
#include "game.h"
#include "renderer.h"
#include <iostream>

int main() {

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight, kFramesPerSecond);
  Game game(kGridWidth, kGridHeight);
  game.Run(std::move(renderer), kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}
