#include "quad_pawn.h"

QuadPawn::QuadPawn()
  : m_Velocity(0.0f)
  , m_X(0.0f)
  , m_Y(0.0f)
  , m_Side(0.0f)
{
}

QuadPawn::QuadPawn(const unsigned int x, const unsigned int y, unsigned int side, const float velocity)
  : m_X(x)
  , m_Y(y)
  , m_Side(side)
  , m_Velocity(velocity)
{
}