#include <Buttons.hpp>

namespace Game{
  string FullscreenButton::type() {
    return "FullscreenButton";
  };

  void FullscreenButton::step() {
    if(this->isHovered()) {
      if(Mouse::isLeftPressed()) GameProcess::click_sound.play();
      if(Mouse::isLeftDown()) this->animate(1, 1, 2, false);
      else this->animate(1, 1, 1, false);
      if(Mouse::isLeftReleased()) GameProcess::changeFullscreen();
    } else this->animate(1, 1, 0, false);
  };

  FullscreenButton::~FullscreenButton() {};

  FullscreenButton* FullscreenButton::create() {
    FullscreenButton* fullscreen_button = new FullscreenButton("fullscreen_button.png", Box(53, 16, 106, 32));
    fullscreen_button->animate(1, 1, 0, false);
    fullscreen_button->pausable = false;
    fullscreen_button->depth = 500;
    fullscreen_button->position = CENTER;
    fullscreen_button->scale(3);

    GameProcess::add(fullscreen_button);
    return fullscreen_button;
  };
};