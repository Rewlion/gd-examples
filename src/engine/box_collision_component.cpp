#include "box_collision_component.h"

BoxCollisionComponent::BoxCollisionComponent(Actor* owner, const std::string& name)
  : SceneComponent(owner, name)
  , m_Size(0, 0)
{
  
}
