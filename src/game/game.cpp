#include "game.h"

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include <string>
#include <chrono>
#include <stdexcept>

Game::Game()
  : m_Window(nullptr)
  , m_Renderer(nullptr)
  , m_IsMovingLeft(false)
  , m_IsMovingRight(false)
  , m_ShouldGameStop(false)
{
}

Game::~Game()
{
  SDL_Quit();
}

void Game::Initialize(const Settings& settings)
{
  m_Settings = settings;

  if (SDL_CreateWindowAndRenderer(settings.window.width, settings.window.height, 0, &m_Window, &m_Renderer))
    throw std::runtime_error(SDL_GetError());

  m_Quad.Initialize(settings.level.quadXStart, settings.level.quadYStart, settings.level.quadSide, settings.level.quadVelocity);
}

void Game::Start()
{
  auto t1 = std::chrono::steady_clock::now();
  while (m_ShouldGameStop == false)
  {
    const auto t2 = std::chrono::steady_clock::now();
    const float dt = std::chrono::duration_cast<std::chrono::duration<float>>(t2 - t1).count();
    t1 = t2;

    Tick(dt);
  }
}

void Game::Tick(const float dt)
{
  ProcessInput();
  MoveQuad(dt);
  RenderFrame();
}

void Game::ProcessInput()
{
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    switch (e.key.keysym.sym)
    {
    case SDLK_a:
    {
      if (e.type == SDL_KEYDOWN)
        m_IsMovingLeft = true;
      else if (e.type == SDL_KEYUP)
        m_IsMovingLeft = false;

      break;
    }

    case SDLK_d:
    {
      if (e.type == SDL_KEYDOWN)
        m_IsMovingRight = true;
      else if (e.type == SDL_KEYUP)
        m_IsMovingRight = false;

      break;
    }
    }
  }
}

void Game::MoveQuad(const float dt)
{
  const float dx = static_cast<float>(m_Quad.GetVelocity() * dt);

  if (m_IsMovingLeft)
    m_Quad.MoveRight(-1.0f * dx);
  else if (m_IsMovingRight)
    m_Quad.MoveRight(dx);
}

void Game::RenderFrame()
{
  SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 1);
  SDL_RenderClear(m_Renderer);

  SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 1);
  SDL_Rect rect = m_Quad.GetSDLRect();
  SDL_RenderDrawRect(m_Renderer, &rect);

  SDL_RenderPresent(m_Renderer);
}