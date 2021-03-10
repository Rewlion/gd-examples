#pragma once

#include "quad.h"
#include "world.h"
#include "renderer.h"

#include <memory>

struct SDL_Window;
struct SDL_Renderer;

class QuadPawn;

class Game
{
public:
  struct Settings
  {
    struct Window
    {
      unsigned int width = 0;
      unsigned int height = 0;
    } window;

    struct Level
    {
      glm::vec2 quadLocation = glm::vec2{ 0.0f, 0.0f };
      glm::vec2 quadSize = glm::vec2{ 0.0f, 0.0f };
      glm::i8vec4 quadColor = glm::i8vec4{ 0,0,0,0 };
      float quadVelocity = 0.0f;
    } level;
  };

public:
  Game();
  ~Game();

  void Initialize(const Settings& settings);
  void InitializeLevel();
  void Start();

private:
  void Tick(const float dt);

private:
  Settings m_Settings;
  SDL_Window* m_Window;

  World m_World;
  Renderer m_Renderer;

  bool m_ShouldGameStop;
};
