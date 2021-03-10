#pragma once

#include <array>
#include <functional>

constexpr size_t ASCII_SIZE = 256;
typedef std::function<void(float)> KeyInputCallback;

class SDLInputHandler
{
public:
  void PollEvents();

  void SetKeyBinding(const unsigned char key, const float value, const KeyInputCallback& callback);

private:
  struct KeyBinding
  {
    float value = 0.0f;
    KeyInputCallback callback = [](float) {};
    uint32_t lastSdlEventType = 0;
  };
private:
  std::array<KeyBinding, ASCII_SIZE> m_KeyBindings;
};
