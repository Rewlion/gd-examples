#pragma once

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

class QuadPawn
{
public:
  QuadPawn();
  QuadPawn(const unsigned int x, const unsigned int y, unsigned int side, const float velocity);

  inline void Initialize(const unsigned int x, const unsigned int y, unsigned int side, const float velocity)
  {
    m_X = x;
    m_Y = y;
    m_Side = side;
    m_Velocity = velocity;
  }

  inline SDL_Rect GetSDLRect() const
  {
    SDL_Rect r;
    r.x = m_X;
    r.y = m_Y;
    r.w = m_Side;
    r.h = m_Side;

    return r;
  }

  inline void MoveRight(const float dx)
  {
    m_X += dx;
  }

  inline float GetVelocity() const
  {
    return m_Velocity;
  }

private:
  float m_X, m_Y;
  float m_Side;
  float m_Velocity;
};