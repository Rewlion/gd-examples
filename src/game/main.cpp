#include "game.h"

#include <iostream>
#include <stdexcept>

int main()
{
  try
  {
    Game::Settings settings;
    settings.window.height = 480;
    settings.window.width = 640;
    settings.level.quadSize = { 20.0f, 20.0f };
    settings.level.quadVelocity = 300.0f;
    settings.level.quadLocation = { 200, 200 };
    settings.level.quadColor = { 255,255,255,255 };

    Game game;
    game.Initialize(settings);

    game.Start();

    return 0;
  }
  catch (const std::exception& e)
  {
    std::printf("error: %s\n", e.what());
    return -1;
  }
}
