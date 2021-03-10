#include "world.h"

void World::Tick(const float dt)
{
  for (std::unique_ptr<Actor>& actor : m_OwnedActors)
  {
    actor->Tick(dt);
    for (std::unique_ptr<ActorComponent>& component : actor->m_OwnedComponents)
      component->Tick(dt);
  }
}