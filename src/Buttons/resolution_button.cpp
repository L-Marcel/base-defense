#include <Buttons.hpp>

namespace Game{
  string ResolutionButton::type() {
    return "ResolutionButton";
  };

  void ResolutionButton::step() {
    if(this->isHovered()) {
      if(Mouse::isLeftPressed()) GameProcess::click_sound.play();
      if(Mouse::isLeftDown()) this->animate(1, 1, 2, false);
      else this->animate(1, 1, 1, false);

      if(Mouse::isLeftReleased()) GameProcess::setResolution(this->resolution);
    } else this->animate(1, 1, 0, false);
  };

  ResolutionButton::~ResolutionButton() {};

  ResolutionButton* ResolutionButton::create(Resolution resolution) {
    string sprite = to_string(int(resolution.x)) + "x" + to_string(int(resolution.y)) + "_button.png";
    ResolutionButton* resolution_button = new ResolutionButton(sprite, Box(53, 16, 106, 32));
    resolution_button->resolution = resolution;
    resolution_button->animate(1, 1, 0, false);
    resolution_button->pausable = false;
    resolution_button->depth = 500;
    resolution_button->position = CENTER;
    resolution_button->scale(3);

    GameProcess::add(resolution_button);
    return resolution_button;
  };
};