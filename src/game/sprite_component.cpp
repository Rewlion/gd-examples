#include "sprite_component.h"

#include "actor.h"

SpriteComponent::SpriteComponent(Actor* owner, const std::string& name)
  : SceneComponent(owner, name)
  , m_Size(0,0)
  , m_Color(0,0,0,0)
{
}

