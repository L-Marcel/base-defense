#include <Buttons.hpp>

namespace Game{
  string ResolutionButton::type() {
    return "ResolutionButton";
  };

  void ResolutionButton::step() {
    if(this->isHovered()) {
      if(Mouse::isLeftDown()) this->animate(1, 1, 2, false);
      else this->animate(1, 1, 1, false);

      if(Mouse::isLeftReleased()) GameProcess::setResolution(this->resolution);
    } else this->animate(1, 1, 0, false);
  };

  ResolutionButton::~ResolutionButton() {};

  ResolutionButton* ResolutionButton::create(Resolution resolution) {
    string sprite = to_string(int(resolution.x)) + "x" + to_string(int(resolution.y)) + "_button.png";

    ResolutionButton* resolutionButton = new ResolutionButton(sprite, Box(53, 16, 106, 32));
    resolutionButton->resolution = resolution;
    resolutionButton->animate(1, 1, 0, false);
    resolutionButton->pausable = false;
    resolutionButton->depth = 500;
    resolutionButton->position = CENTER;
    resolutionButton->scale(3);

    GameProcess::add(resolutionButton);
    return resolutionButton;
  };
};