#include "actor_component.h"
#include "actor.h"

ActorComponent::ActorComponent(Actor* owner, const std::string& name)
  : m_Name(name)
  , m_Owner(owner)
{
}