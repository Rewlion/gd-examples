#include "quad.h"

#include "movement_component.h"
#include "input_component.h"
#include "sprite_component.h"

#include <math.h>

AQuad::AQuad()
{
  m_MovementComponent = AddComponent<MovementComponent>("Movement Component");

  m_QuadSpriteComponent = AddComponent<SpriteComponent>("Quad Sprite Component");
  m_QuadSpriteComponent->SetColor(255, 255, 255, 255);

  m_GreenFlyingParticle = AddComponent<SpriteComponent>("Blue Particle Component");
  m_GreenFlyingParticle->SetColor(0, 255, 0, 255);
  m_GreenFlyingParticle->AttachTo(m_QuadSpriteComponent);

  m_BlueFlyingParticle = AddComponent<SpriteComponent>("Blue Particle Component");
  m_BlueFlyingParticle->SetColor(0, 0, 255, 255);
  m_BlueFlyingParticle->AttachTo(m_QuadSpriteComponent);
}

void AQuad::SetLeftMovementScale(const float scale)
{
  m_MovementComponent->SetLeftMovementScale(scale);
}

void AQuad::SetRightMovementScale(const float scale)
{
  m_MovementComponent->SetRightMovementScale(scale);
}

void AQuad::SetUpMovementScale(const float scale)
{
  m_MovementComponent->SetUpMovementScale(scale);
}

void AQuad::SetBotMovementScale(const float scale)
{
  m_MovementComponent->SetBotMovementScale(scale);
}

void AQuad::Tick(const float dt)
{
  static float totalTime = 0.0f;

  totalTime += dt * 2.0;

  m_GreenFlyingParticle->SetLocalLocation({
    102.0f * std::cos(totalTime), 90.0f * std::sin(1 - totalTime)
  });

  m_BlueFlyingParticle->SetLocalLocation({
    70.0f * std::cos(-totalTime), 55.0f * std::sin(totalTime - 1)
  });
}

void AQuad::Initialize(const glm::vec2& location, const glm::ivec2& size, const glm::i8vec4& color, const float velocity)
{
  SetWorldLocation(location);
  m_QuadSpriteComponent->SetColor(color.r, color.g, color.b, color.a);
  m_QuadSpriteComponent->SetSize(size);
  m_MovementComponent->SetVelocity(velocity);

  m_GreenFlyingParticle->SetSize(size/2);
  m_BlueFlyingParticle->SetSize(size/5);
}