#include "game.h"
#include "gui_object.h"
#include <iostream>

Game::Game(size_t grid_width, size_t grid_height) {
  // add barrier
  add_barriers_cage(grid_width, grid_height);

  // add food
  gui_objects.emplace_back(std::make_unique<Food>(grid_width, grid_height, &this->gui_objects));

  // add snake last, so it is rendered on top of everything else
  auto snake_ptr = std::make_unique<Snake>((int) grid_width, (int) grid_height, &this->gui_objects);
  snake = snake_ptr.get();
  gui_objects.emplace_back(std::move(snake_ptr));
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

  snake->update();
}

int Game::GetScore() const { return snake->score; }
int Game::GetSize() const { return snake->size; }
void Game::add_barriers_cage(const size_t &grid_width, const size_t &grid_height) {
  gui_objects.emplace_back(std::make_unique<Barrier>(0, 0, 1, grid_width, &this->gui_objects));
  gui_objects.emplace_back(std::make_unique<Barrier>(0, 0, grid_height, 1, &this->gui_objects));
  gui_objects.emplace_back(std::make_unique<Barrier>(grid_height - 1, 0, grid_height, 1, &this->gui_objects));
  gui_objects.emplace_back(std::make_unique<Barrier>(0, grid_height - 1, 1, grid_width, &this->gui_objects));
}
