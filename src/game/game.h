#pragma once

#include "quad_pawn.h"

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
      float quadVelocity = 0.0f;
      float quadXStart = 0;
      float quadYStart = 0;
      float quadSide = 0;
    } level;
  };

public:
  Game();
  ~Game();

  void Initialize(const Settings& settings);

  void Start();

private:
  void Tick(const float dt);
  void ProcessInput();
  void MoveQuad(const float dt);
  void RenderFrame();

private:
  Settings m_Settings;
  SDL_Window* m_Window;
  SDL_Renderer* m_Renderer;

  QuadPawn m_Quad;
  bool m_IsMovingLeft, m_IsMovingRight;

  bool m_ShouldGameStop;
};
