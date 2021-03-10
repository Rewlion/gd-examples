#include "player_controller.h"

#include "input_component.h"

APlayerController::APlayerController()
{
  m_InputComponent = AddComponent<InputComponent>("Player Input Component");
}

void APlayerController::Tick(const float dt)
{
}