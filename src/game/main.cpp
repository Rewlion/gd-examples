#include "quad.h"
#include "quad_controller.h"

#include <engine/engine.h>

#include <iostream>
#include <stdexcept>

class GameInitializer : public Engine::GameInitializer
{
public:
  virtual void Initialize(World* world)
  {
    const glm::vec2 quadSize = { 20.0f, 20.0f };
    const float quadVelocity = 300.0f;
    const glm::vec2 quadLocation = { 200, 200 };
    const glm::i8vec4 quadColor = { 255,255,255,255 };

    AQuad* quad = world->SpawnActor<AQuad>();
    quad->Initialize(quadLocation, quadSize, quadColor, quadVelocity);

    AQuadController* controller = world->SpawnActor<AQuadController>();
    controller->Possess(quad);

    AQuad* wall = world->SpawnActor<AQuad>();
    wall->Initialize(quadLocation + glm::vec2{ 100, 0 }, quadSize, quadColor, quadVelocity);
  }
};

int main()
{
  try
  {
    Engine::Settings settings;
    settings.window.height = 480;
    settings.window.width = 640;

    GameInitializer gameInit;
    Engine engine;
    engine.Initialize(settings, &gameInit);

    engine.StartGameLoop();

    return 0;
  }
  catch (const std::exception& e)
  {
    std::printf("error: %s\n", e.what());
    return -1;
  }
}
