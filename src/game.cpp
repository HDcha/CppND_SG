#include "game.h"
#include "gui_object.h"
#include <iostream>

Game::Game(size_t grid_width, size_t grid_height) {

  // add snake
  auto snake_ptr = std::make_unique<Snake>((int) grid_width, (int) grid_height);
  snake = snake_ptr.get();
  gui_objects.emplace_back(std::move(snake_ptr));

  // add food
  gui_objects.emplace_back(std::make_unique<Food>(grid_width, grid_height));
}

void Game::Run(Controller const &controller, Renderer &renderer, size_t target_frame_duration) {
  bool running = true;
  Frame frame(this, target_frame_duration, renderer);

  while (running) {
    frame.start();

    // Input, update, Render - the main game loop.
    Controller::HandleInput(running, *snake);
    Update();
    renderer.Render(gui_objects);

    frame.end();
  }
}


void Game::Update() {
  if (!snake->alive) return;

  snake->update(&gui_objects);
}

int Game::GetScore() const { return snake->score; }
int Game::GetSize() const { return snake->size; }
