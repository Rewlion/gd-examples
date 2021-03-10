#pragma once

#include "world.h"
#include "renderer.h"

struct SDL_Window;
struct SDL_Renderer;

class Engine
{
public:
  class GameInitializer
  {
  public:
    virtual void Initialize(World* world) {}
    virtual ~GameInitializer() {}
  };

  struct Settings
  {
    struct Window
    {
      unsigned int width = 0;
      unsigned int height = 0;
    } window;
  };

public:
  Engine();

  void Initialize(const Settings& settings, GameInitializer* gameInitializer);
  void StartGameLoop();

  static World* GetWorld()
  {
    return &m_World;
  }

private:
  void Tick(const float dt);

private:
  Settings m_Settings;
  SDL_Window* m_Window;

  static World m_World;
  Renderer m_Renderer;

  bool m_ShouldGameStop;
};
