#include "game.h"
#include "SDL.h"
#include <iostream>

Game::Game(size_t grid_width, size_t grid_height)
    : snake((int) grid_width, (int) grid_height),
      engine(dev()),
      food(),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer, size_t target_frame_duration) {
  bool running = true;
  Frame frame(this, target_frame_duration, renderer);

  while (running) {
    frame.start();

    // Input, Update, Render - the main game loop.
    Controller::HandleInput(running, snake);
    Update();
    renderer.Render(snake, food);

    frame.end();
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() { // todo move update functions in object functions
  if (!snake.alive) return;

  snake.Update();

  // Check if there's food over here
  if (food.x == (int) (snake.head_x) && food.y == (int) (snake.head_y)) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
