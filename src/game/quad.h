#pragma once

#include <engine/actor.h>

class MovementComponent;
class InputComponent;
class SpriteComponent;
class BoxCollisionComponent;

class AQuad : public Actor
{
public:
  AQuad();

  void Initialize(const glm::vec2& location, const glm::ivec2& size, const glm::i8vec4& color, const float velocity);

  void SetLeftMovementScale(const float scale);
  void SetRightMovementScale(const float scale);
  void SetUpMovementScale(const float scale);
  void SetBotMovementScale(const float scale);

private:
  MovementComponent* m_MovementComponent;
  SpriteComponent* m_QuadSpriteComponent;
  BoxCollisionComponent* m_BoxComponent;
};