#include "movement_component.h"

#include "actor.h"

MovementComponent::MovementComponent(Actor* owner, const std::string& name)
  : ActorComponent(owner, name)
  , m_RightMovementScale(0.0f)
  , m_LeftMovementScale(0.0f)
  , m_UpMovementScale(0.0f)
  , m_BotMovementScale(0.0f)
  , m_Velocity(0.0f)
{
}

void MovementComponent::Tick(const float dt)
{
  glm::vec2 movementScale = glm::vec2{ m_LeftMovementScale + m_RightMovementScale, m_UpMovementScale + m_BotMovementScale };
  glm::vec2 dr = (m_Velocity * dt) * movementScale;
  glm::vec2 r = m_Owner->GetWorldLocation();
  m_Owner->SetWorldLocation(r + dr);
}