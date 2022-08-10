#include "game.h"
#include "gui_object.h"
#include "display_parameters.h"
#include <iostream>

Game::Game() {
  // add barrier
  add_barriers_cage();

  // add food
  gui_objects.emplace_back(std::make_unique<Food>(kGridWidth, kGridHeight, &this->gui_objects));

  // add snake last, so it is rendered on top of everything else
  auto snake_ptr = std::make_unique<Snake>((int) kGridWidth, (int) kGridHeight, &this->gui_objects);
  snake = snake_ptr.get();
  gui_objects.emplace_back(std::move(snake_ptr));
}

void Game::Run() {
  bool running = true;
  Renderer renderer;
  Frame frame(this, renderer);

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

int Game::GetScore() const { return snake->get_score(); }
int Game::GetSize() const { return snake->get_size(); }
void Game::add_barriers_cage() {
  gui_objects.emplace_back(std::make_unique<Barrier>(0, 0, 1, kGridWidth, &gui_objects));
  gui_objects.emplace_back(std::make_unique<Barrier>(0, 0, kGridHeight, 1, &gui_objects));
  gui_objects.emplace_back(std::make_unique<Barrier>(kGridHeight - 1, 0, kGridHeight, 1, &gui_objects));
  gui_objects.emplace_back(std::make_unique<Barrier>(0, kGridHeight - 1, 1, kGridWidth, &gui_objects));
}
