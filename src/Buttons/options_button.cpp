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
    OptionsButton* options_button = new OptionsButton("options_button.png", Box(53, 16, 106, 32));
    options_button->animate(1, 1, 0, false);
    options_button->pausable = false;
    options_button->depth = 500;
    options_button->position = CENTER;
    options_button->scale(3);

    GameProcess::add(options_button);
    return options_button;
  };
};