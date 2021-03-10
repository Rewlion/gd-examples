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
    settings.level.quadSide = 20.0f;
    settings.level.quadVelocity = 300.0f;
    settings.level.quadXStart = 320.0f;
    settings.level.quadYStart = 240.0f;

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
