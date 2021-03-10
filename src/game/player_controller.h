#include "controller.h"

class InputComponent;

class APlayerController : public AController
{
public:
  APlayerController();

  virtual void Tick(const float dt) override;

protected:
  InputComponent* m_InputComponent;
};
