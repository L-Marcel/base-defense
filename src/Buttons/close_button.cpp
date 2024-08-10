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
    CloseButton* closeButton = new CloseButton("close_button.png", Box(53, 16, 106, 32));
    closeButton->animate(1, 1, 0, false);
    closeButton->pausable = false;
    closeButton->depth = 500;
    closeButton->position = CENTER;
    closeButton->scale(3);

    GameProcess::add(closeButton);
    return closeButton;
  };
};