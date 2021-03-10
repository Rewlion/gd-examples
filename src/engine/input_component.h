#pragma once

#include "actor_component.h"
#include "sdl_input_handler.h"

class InputComponent : public ActorComponent
{
public:
  InputComponent(Actor* owner, const std::string& name);

  virtual void Tick(const float dt) override;

  inline void SetKeyBinding(const unsigned char key, const float value, const KeyInputCallback& callback)
  {
    m_InputHandler.SetKeyBinding(key, value, callback);
  }

private:
  SDLInputHandler m_InputHandler;
};