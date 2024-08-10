#include <Buttons.hpp>

namespace Game{
  string RestartButton::type() {
    return "RestartButton";
  };

  void RestartButton::step() {
    if(this->isHovered()) {
      if(Mouse::isLeftPressed()) GameProcess::click_sound.play();
      if(Mouse::isLeftDown()) this->animate(1, 1, 2, false);
      else this->animate(1, 1, 1, false);

      if(Mouse::isLeftReleased()) GameProcess::restart();
    } else this->animate(1, 1, 0, false);
  };

  RestartButton::~RestartButton() {};

  RestartButton* RestartButton::create() {
    RestartButton* restartButton = new RestartButton("restart_button.png", Box(53, 16, 106, 32));
    restartButton->animate(1, 1, 0, false);
    restartButton->pausable = false;
    restartButton->depth = 500;
    restartButton->position = CENTER;
    restartButton->scale(3);

    GameProcess::add(restartButton);
    return restartButton;
  };
};