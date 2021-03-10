#pragma once

struct SDL_Renderer;
class World;

class Renderer
{
public:
  Renderer();

  void Initialize(SDL_Renderer*, World* world);

  void Tick(const float dt);

private:
  SDL_Renderer* m_Renderer;
  World* m_World;
};