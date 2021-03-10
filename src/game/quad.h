#pragma once

#include "actor.h"

class MovementComponent;
class InputComponent;
class SpriteComponent;

class AQuad : public Actor
{
public:
  AQuad();

  virtual void Tick(const float dt) override;
  void Initialize(const glm::vec2& location, const glm::ivec2& size, const glm::i8vec4& color, const float velocity);

private:
  MovementComponent* m_MovementComponent;
  InputComponent* m_InputComponent;
  SpriteComponent* m_QuadSpriteComponent;

  SpriteComponent* m_GreenFlyingParticle;
  SpriteComponent* m_BlueFlyingParticle;
};