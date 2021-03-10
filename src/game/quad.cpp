#include "quad.h"

#include <engine/movement_component.h>
#include <engine/input_component.h>
#include <engine/sprite_component.h>
#include <engine/box_collision_component.h>

#include <math.h>

AQuad::AQuad()
{
  m_MovementComponent = AddComponent<MovementComponent>("Movement Component");

  m_QuadSpriteComponent = AddComponent<SpriteComponent>("Quad Sprite Component");
  m_QuadSpriteComponent->SetColor(255, 255, 255, 255);

  m_BoxComponent = AddComponent<BoxCollisionComponent>("Collision Component");
  m_BoxComponent->AttachTo(m_QuadSpriteComponent);

  m_BoxComponent->GetHitEvent().Listen([&](Actor* a) {
    std::printf("%p hitted by %p\n", this, a);
  });
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

void AQuad::Initialize(const glm::vec2& location, const glm::ivec2& size, const glm::i8vec4& color, const float velocity)
{
  SetWorldLocation(location);
  m_QuadSpriteComponent->SetColor(color.r, color.g, color.b, color.a);
  m_QuadSpriteComponent->SetSize(size);
  m_BoxComponent->SetSize(size);
  m_MovementComponent->SetVelocity(velocity);
}