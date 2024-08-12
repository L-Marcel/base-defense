#include <Buttons.hpp>

namespace Game{
  string CloseButton::type() {
    return "CloseButton";
  };

  void CloseButton::step() {
    if(this->isHovered()) {
      if(Mouse::isLeftPressed()) GameProcess::click_sound.play();
      if(Mouse::isLeftDown()) this->animate(1, 1, 2, false);
      else this->animate(1, 1, 1, false);

      if(Mouse::isLeftReleased()) GameProcess::close();
    } else this->animate(1, 1, 0, false);
  };

  CloseButton::~CloseButton() {};

  CloseButton* CloseButton::create() {
    CloseButton* close_button = new CloseButton("close_button.png", Box(53, 16, 106, 32));
    close_button->animate(1, 1, 0, false);
    close_button->pausable = false;
    close_button->depth = 500;
    close_button->position = CENTER;
    close_button->scale(3);

    GameProcess::add(close_button);
    return close_button;
  };
};