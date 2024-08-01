#include <Buttons.hpp>

namespace Game{
  string FullscreenButton::type() {
    return "FullscreenButton";
  };

  void FullscreenButton::step() {
    if(this->isHovered()) {
      if(Mouse::isLeftDown()) this->animate(1, 1, 2, false);
      else this->animate(1, 1, 1, false);

      if(Mouse::isLeftReleased()) GameProcess::changeFullscreen();
    } else this->animate(1, 1, 0, false);
  };

  FullscreenButton::~FullscreenButton() {};

  FullscreenButton* FullscreenButton::create() {
    FullscreenButton* fullscreenButton = new FullscreenButton("fullscreen_button.png", Box(53, 16, 106, 32));
    fullscreenButton->animate(1, 1, 0, false);
    fullscreenButton->pausable = false;
    fullscreenButton->depth = 500;
    fullscreenButton->position = CENTER;
    fullscreenButton->scale(3);

    GameProcess::add(fullscreenButton);
    return fullscreenButton;
  };
};