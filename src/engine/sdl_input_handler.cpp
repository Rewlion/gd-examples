#include "sdl_input_handler.h"

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

void SDLInputHandler::PollEvents()
{
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.key.keysym.sym < ASCII_SIZE)
    {
      KeyBinding& binding = m_KeyBindings[e.key.keysym.sym];

      if (e.type == SDL_KEYDOWN && binding.lastSdlEventType != SDL_KEYDOWN)
      {
        binding.callback(binding.value);
        binding.lastSdlEventType = e.type;
      }
      else if (e.type == SDL_KEYUP)
      {
        binding.callback(0.0f);
        binding.lastSdlEventType = e.type;
      }
    }
  }
}

void SDLInputHandler::SetKeyBinding(const unsigned char key, const float value, const KeyInputCallback& callback)
{
  m_KeyBindings[key] = KeyBinding{ value, callback, 0 };
}
