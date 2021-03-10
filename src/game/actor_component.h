#pragma once

#include <string>

class Actor;

class ActorComponent
{
public:
  ActorComponent(Actor* owner, const std::string& name);
  virtual ~ActorComponent() {}

  virtual void Tick(const float dt) {};

  inline const std::string& GetName() const
  {
    return m_Name;
  }

protected:
  std::string m_Name;
  Actor* const m_Owner;
};