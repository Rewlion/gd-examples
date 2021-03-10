#pragma once

#include "actor.h"

class AController : public Actor
{
public:
  AController();

  inline void Possess(Actor* pawn)
  {
    assert(pawn);
    m_Pawn = pawn;
  }

  inline Actor* GetPossessedPawn() const
  {
    return m_Pawn;
  }

protected:
  Actor* m_Pawn;

private:
  using Actor::SetWorldLocation;
  using Actor::GetWorldLocation;
};
