#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const size_t &screen_width,
                   const size_t &screen_height,
                   const size_t &grid_width, const size_t &grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, (int) screen_width,
                                (int) screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(const v_p_gui_objects &gui_objects) {

  block.w = (int) (screen_width / grid_width);
  block.h = (int) (screen_height / grid_height);

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  for (const auto &u_ptr : gui_objects) {
    auto ptr = u_ptr.get();
    if (auto ptr_snake = dynamic_cast<Snake *>(ptr); ptr_snake != nullptr)
      Render(ptr_snake);
    else if (auto ptr_food = dynamic_cast<Food *>(ptr); ptr_food != nullptr)
      Render(ptr_food);
    else // render as obstacle
      Render(ptr);
  }

  // update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::Render(const Snake *snake) {

  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  for (SDL_Point const &point : snake->occupied_squares) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's head
  snake->occupied_squares.end()->x;
  snake->occupied_squares.end()->y;
  if (snake->alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);
}

void Renderer::Render(const Food *food) {
  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = food->occupied_squares[0].x * block.w;
  block.y = food->occupied_squares[0].y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);
}

// Render obstacle
void Renderer::Render(const GuiObject *gui_object) {
  SDL_SetRenderDrawColor(sdl_renderer, 0x44, 0x44, 0x44, 0xFF);
  for (const auto &square : gui_object->occupied_squares) {
    block.x = square.x * block.w;
    block.y = square.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
