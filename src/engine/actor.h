#pragma once

#include "actor_component.h"
#include "scene_component.h"

#include <vector>
#include <memory>

class Actor
{
  friend class World;

public:
  Actor();
  virtual ~Actor() {};

  template<class TComponent>
  TComponent* AddComponent(const std::string& name)
  {
    auto newComponent = std::make_unique<TComponent>(this, name);

    if constexpr (std::is_base_of<SceneComponent, TComponent>::value == true)
    {
      if (m_RootComponent == nullptr)
        m_RootComponent = reinterpret_cast<SceneComponent*>(newComponent.get());
    }

    auto* r = newComponent.get();
    m_OwnedComponents.push_back(std::move(newComponent));

    return r;
  }

  template<class TComponent>
  TComponent* GetComponent(const std::string& name)
  {
    for (std::unique_ptr<ActorComponent>& component : m_OwnedComponents)
    {
      const bool areNamesEqual = component->GetName() == name;
      const bool isTargetComponent = dynamic_cast<TComponent>(component.get()) != nullptr; //hack + slow

      if (areNamesEqual && isTargetComponent)
        return reinterpret_cast<TComponent*>(component.get());
    }
  }

  template<class TComponent>
  std::vector<TComponent*> GetComponents()
  {
    std::vector<TComponent*> comps;

    for (std::unique_ptr<ActorComponent>& component : m_OwnedComponents)
    {
      auto* targetComponent = dynamic_cast<TComponent*>(component.get()); //hack + slow

      if (targetComponent)
        comps.push_back(targetComponent);
    }

    return comps;
  }

  inline void SetWorldLocation(const glm::vec2 location)
  {
    if (m_RootComponent)
      m_RootComponent->SetLocalLocation(location);
  }

  inline glm::vec2 GetWorldLocation() const
  {
    return m_RootComponent ? m_RootComponent->GetLocalLocation() : glm::vec2{ 0.0f, 0.0f };
  }

protected:
  virtual void Tick(const float dt);

protected:
  SceneComponent* m_RootComponent;

private:
  std::vector<std::unique_ptr<ActorComponent>> m_OwnedComponents;
};