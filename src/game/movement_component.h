#pragma once

#include "actor_component.h"

class MovementComponent : public ActorComponent
{
public:
  MovementComponent(Actor* owner, const std::string& name);

  virtual void Tick(const float dt) override;

  inline void SetRightMovementScale(const float scale)
  {
    m_RightMovementScale = scale;
  }

  inline void SetLeftMovementScale(const float scale)
  {
    m_LeftMovementScale = scale;
  }

  inline void SetUpMovementScale(const float scale)
  {
    m_UpMovementScale = scale;
  }

  inline void SetBotMovementScale(const float scale)
  {
    m_BotMovementScale = scale;
  }

  inline void SetVelocity(const float velocity)
  {
    m_Velocity = velocity;
  }

private:
  float m_RightMovementScale;
  float m_LeftMovementScale;
  float m_UpMovementScale;
  float m_BotMovementScale;

  float m_Velocity;

};