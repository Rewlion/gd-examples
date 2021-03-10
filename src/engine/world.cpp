#include "world.h"

#include "box_collision_component.h"

namespace
{
  bool CollideBox(BoxCollisionComponent* causerBox, const std::vector<BoxCollisionComponent*>& targetBoxes)
  {
    const glm::vec2 causerBoxXY = causerBox->GetWorldLocation();
    const glm::vec2 causerBoxSize = causerBox->GetSize();
    HitEvent& causerBoxHitEvent = causerBox->GetHitEvent();

    bool hasCollision = false;

    for (auto* targetBox : targetBoxes)
    {
      const glm::vec2 targetBoxXY = targetBox->GetWorldLocation();
      const glm::vec2 targetBoxSize = targetBox->GetSize();

      if (causerBoxXY.x < targetBoxXY.x + targetBoxSize.x && 
          causerBoxXY.x + causerBoxSize.x > targetBoxXY.x &&
          causerBoxXY.y < targetBoxXY.y + targetBoxSize.y &&
          causerBoxXY.y + causerBoxSize.y > targetBoxXY.y)
      {
        HitEvent& targetBoxHitEvent = causerBox->GetHitEvent();

        causerBoxHitEvent(targetBox->GetOwner());
        targetBoxHitEvent(causerBox->GetOwner());

        hasCollision = true;
      }
    }

    return hasCollision;
  }
}

void World::Tick(const float dt)
{
  for (std::unique_ptr<Actor>& actor : m_OwnedActors)
  {
    actor->Tick(dt);
    for (std::unique_ptr<ActorComponent>& component : actor->m_OwnedComponents)
      component->Tick(dt);
  }
}

bool World::CheckForCollisions(Actor* causer)
{
  std::vector<BoxCollisionComponent*> causerBoxComps = causer->GetComponents<BoxCollisionComponent>();
  if (causerBoxComps.empty())
    return false;

  bool hasCollision = false;

  for (std::unique_ptr<Actor>& actor : m_OwnedActors)
  {
    if (actor.get() == causer)
      continue;

    std::vector<BoxCollisionComponent*> targetBoxComps = actor->GetComponents<BoxCollisionComponent>();
    if (targetBoxComps.empty())
      continue;

    for (auto* causerBox : causerBoxComps)
      if (CollideBox(causerBox, targetBoxComps))
        hasCollision = true;
  }

  return hasCollision;
}
