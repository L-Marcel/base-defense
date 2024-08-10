#include <Buttons.hpp>
#include <Menus.hpp>

namespace Game{
  string OptionsButton::type() {
    return "OptionsButton";
  };

  void OptionsButton::step() {
    if(this->isHovered()) {
      if(Mouse::isLeftPressed()) GameProcess::click_sound.play();
      if(Mouse::isLeftDown()) this->animate(1, 1, 2, false);
      else this->animate(1, 1, 1, false);

      if(Mouse::isLeftReleased()) GameProcess::navigate(ResolutionMenu::create());
    } else this->animate(1, 1, 0, false);
  };

  OptionsButton::~OptionsButton() {};

  OptionsButton* OptionsButton::create() {
    OptionsButton* optionsButton = new OptionsButton("options_button.png", Box(53, 16, 106, 32));
    optionsButton->animate(1, 1, 0, false);
    optionsButton->pausable = false;
    optionsButton->depth = 500;
    optionsButton->position = CENTER;
    optionsButton->scale(3);

    GameProcess::add(optionsButton);
    return optionsButton;
  };
};