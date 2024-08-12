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
    RestartButton* restart_button = new RestartButton("restart_button.png", Box(53, 16, 106, 32));
    restart_button->animate(1, 1, 0, false);
    restart_button->pausable = false;
    restart_button->depth = 500;
    restart_button->position = CENTER;
    restart_button->scale(3);

    GameProcess::add(restart_button);
    return restart_button;
  };
};