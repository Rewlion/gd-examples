#pragma once

#include "scene_component.h"
#include "event.h"

#include <glm/glm.hpp>

typedef OneParamEvent<Actor*> HitEvent;

class BoxCollisionComponent : public SceneComponent
{
public:
  BoxCollisionComponent(Actor* owner, const std::string& name);

  inline glm::vec2 GetSize() const
  {
    return m_Size;
  }

  inline void SetSize(const glm::vec2 size)
  {
    m_Size = size;
  }

  HitEvent& GetHitEvent()
  {
    return m_HitEvent;
  }

private:
  glm::vec2 m_Size;
  HitEvent m_HitEvent;
};
