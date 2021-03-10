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

  m_InputComponent = AddComponent<InputComponent>("Input Component");

  m_InputComponent->SetKeyBinding('a', -1.0f, [&](float v) {
    m_MovementComponent->SetLeftMovementScale(v);
  });
  m_InputComponent->SetKeyBinding('d', +1.0f, [&](float v) {
    m_MovementComponent->SetRightMovementScale(v);
  });
  m_InputComponent->SetKeyBinding('w', -1.0f, [&](float v) {
    m_MovementComponent->SetUpMovementScale(v);
  });
  m_InputComponent->SetKeyBinding('s', +1.0f, [&](float v) {
    m_MovementComponent->SetBotMovementScale(v);
  });
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