#pragma once

#include "scene_component.h"

class SpriteComponent : public SceneComponent
{
public:
  SpriteComponent(Actor* owner, const std::string& name);

  inline void SetSize(const glm::ivec2 size)
  {
    m_Size = size;
  }

  inline void SetColor(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a)
  {
    m_Color = glm::ivec4{ r,g,b,a };
  }

  inline glm::ivec2 GetSize() const
  {
    return m_Size;
  }

  inline glm::ivec4 GetColor() const
  {
    return m_Color;
  }

private:
  glm::ivec2 m_Size;
  glm::ivec4 m_Color;

};
