#include "quad_controller.h"
#include "quad.h"

#include <engine/input_component.h>

AQuadController::AQuadController()
{
  m_InputComponent->SetKeyBinding('a', -1.0f, [&](float v) {
    AQuad* quad = dynamic_cast<AQuad*>(m_Pawn);
    quad->SetLeftMovementScale(v);
  });

  m_InputComponent->SetKeyBinding('d', +1.0f, [&](float v) {
    AQuad* quad = dynamic_cast<AQuad*>(m_Pawn);
    quad->SetRightMovementScale(v);
  });

  m_InputComponent->SetKeyBinding('w', -1.0f, [&](float v) {
    AQuad* quad = dynamic_cast<AQuad*>(m_Pawn);
    quad->SetUpMovementScale(v);
  });

  m_InputComponent->SetKeyBinding('s', +1.0f, [&](float v) {
    AQuad* quad = dynamic_cast<AQuad*>(m_Pawn);
    quad->SetBotMovementScale(v);
  });
}
