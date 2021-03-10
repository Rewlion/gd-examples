#include "scene_component.h"

Transform::Transform()
  : m_Location(0.0f, 0.0f)
{
}

SceneComponent::SceneComponent(Actor* owner, const std::string& name)
  : ActorComponent(owner, name)
  , m_ParentAttachment(nullptr)
{
}

glm::vec2 SceneComponent::GetWorldLocation() const
{
  const SceneComponent* sc = this;

  glm::vec2 worldLocation{};

  while (sc != nullptr)
  {
    worldLocation += sc->m_Transform.GetLocation();
    sc = sc->m_ParentAttachment;
  }

  return worldLocation;
}