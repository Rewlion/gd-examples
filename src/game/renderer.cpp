#include "renderer.h"
#include "sprite_component.h"
#include "world.h"

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include <assert.h>
#include <vector>

Renderer::Renderer()
  : m_Renderer(nullptr)
  , m_World(nullptr)
{
}

void Renderer::Initialize(SDL_Renderer* renderer, World* world)
{
  assert(renderer);
  assert(world);

  m_Renderer = renderer;
  m_World = world;
}

void Renderer::Tick(const float)
{
  SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 1);
  SDL_RenderClear(m_Renderer);

  std::vector<SpriteComponent*> sprites = m_World->GetComponents<SpriteComponent>();
  for (auto* sprite : sprites)
  {
    const glm::ivec2 upperLeft = sprite->GetWorldLocation();
    const glm::ivec2 size = sprite->GetSize();
    const glm::ivec4 color = sprite->GetColor();

    SDL_Rect rect;
    rect.x = upperLeft.x;
    rect.y = upperLeft.y;
    rect.w = size.x;
    rect.h = size.y;

    SDL_SetRenderDrawColor(m_Renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawRect(m_Renderer, &rect);
  }

  SDL_RenderPresent(m_Renderer);
}