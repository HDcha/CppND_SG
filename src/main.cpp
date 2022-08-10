///
/// @file
/// @copyright Copyright (C) 2022, Christoph Haupt
///

#include "game.h"
#include <iostream>

int main() {

  Game game;
  game.Run();
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}
