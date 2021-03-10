#include "game.h"
#include "quad_controller.h"
#include "quad.h"

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include <string>
#include <chrono>
#include <stdexcept>

World* worldSharePointer;

World* GetWorld()
{
  return worldSharePointer;
}

Game::Game()
  : m_Window(nullptr)
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

  SDL_Renderer* sdlRenderer = nullptr;
  if (SDL_CreateWindowAndRenderer(settings.window.width, settings.window.height, 0, &m_Window, &sdlRenderer))
    throw std::runtime_error(SDL_GetError());

  m_Renderer.Initialize(sdlRenderer, &m_World);

  worldSharePointer = &m_World;

  InitializeLevel();
}

void Game::InitializeLevel()
{
  AQuad* quad = m_World.SpawnActor<AQuad>();
  quad->Initialize(m_Settings.level.quadLocation, m_Settings.level.quadSize, m_Settings.level.quadColor, m_Settings.level.quadVelocity);

  AQuadController* controller = m_World.SpawnActor<AQuadController>();
  controller->Possess(quad);

  AQuad* wall = m_World.SpawnActor<AQuad>();
  wall->Initialize(m_Settings.level.quadLocation + glm::vec2{ 100, 0 }, m_Settings.level.quadSize, m_Settings.level.quadColor, m_Settings.level.quadVelocity);
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
  m_World.Tick(dt);
  m_Renderer.Tick(dt);
}

