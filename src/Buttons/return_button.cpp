#include <Buttons.hpp>
#include <Menus.hpp>

namespace Game{
  string ReturnButton::type() {
    return "ReturnButton";
  };

  void ReturnButton::step() {
    if(this->isHovered()) {
      if(Mouse::isLeftPressed()) GameProcess::click_sound.play();
      if(Mouse::isLeftDown()) this->animate(1, 1, 2, false);
      else this->animate(1, 1, 1, false);
      if(Mouse::isLeftReleased()) GameProcess::navigate(this->create_previous_menu());
    } else this->animate(1, 1, 0, false);
  };

  ReturnButton::~ReturnButton() {};

  ReturnButton* ReturnButton::create(function<Menu*()> create_previous_menu) {
    ReturnButton* return_button = new ReturnButton("return_button.png", Box(53, 16, 106, 32));
    return_button->create_previous_menu = create_previous_menu;
    return_button->animate(1, 1, 0, false);
    return_button->pausable = false;
    return_button->depth = 500;
    return_button->position = CENTER;
    return_button->scale(3);

    GameProcess::add(return_button);
    return return_button;
  };
};