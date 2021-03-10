#include "input_component.h"

InputComponent::InputComponent(Actor* owner, const std::string& name)
  : ActorComponent(owner, name)
{
}

void InputComponent::Tick(const float)
{
  m_InputHandler.PollEvents();
}