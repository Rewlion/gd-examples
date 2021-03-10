#pragma once

#include "actor.h"

#include<algorithm>
#include<iterator>

class World
{
public:
  void Tick(const float dt);

  template<class TActor>
  TActor* SpawnActor()
  {
    auto a = std::make_unique<TActor>();
    TActor* r = a.get();

    m_OwnedActors.push_back(std::move(a));
    return r;
  }

  template<class TComponent>
  std::vector<TComponent*> GetComponents()
  {
    std::vector<TComponent*> comps;

    for (std::unique_ptr<Actor>& actor : m_OwnedActors)
    {
      std::vector<TComponent*> targetComps = actor->GetComponents<TComponent>();
      std::copy(targetComps.begin(), targetComps.end(), std::back_inserter(comps));
    }

    return comps;
  }

  bool CheckForCollisions(Actor*);

private:
  std::vector<std::unique_ptr<Actor>> m_OwnedActors;
};