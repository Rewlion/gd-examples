#pragma once

#include "actor_component.h"

#include <glm/glm.hpp>

class Transform
{
public:
  Transform();

  inline glm::vec2 GetLocation() const
  {
    return m_Location;
  }

  inline void SetLocation(const glm::vec2 location)
  {
    m_Location = location;
  }

private:
  glm::vec2 m_Location;
};

class SceneComponent : public ActorComponent
{
public:
  SceneComponent(Actor* owner, const std::string& name);

  inline void AttachTo(const SceneComponent* parent)
  {
    assert(parent);
    m_ParentAttachment = parent;
  }

  glm::vec2 GetWorldLocation() const;

  inline glm::vec2 GetLocalLocation() const
  {
    return m_Transform.GetLocation();
  }

  inline void SetLocalLocation(const glm::vec2 location)
  {
    m_Transform.SetLocation(location);
  }

private:
  const SceneComponent* m_ParentAttachment;
  Transform m_Transform;
};