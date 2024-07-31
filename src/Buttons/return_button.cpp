#include <Buttons.hpp>
#include <Menus.hpp>

namespace Game{
  string ReturnButton::type() {
    return "ReturnButton";
  };

  void ReturnButton::step() {
    if(this->isHovered()) {
      if(Mouse::isLeftDown()) this->animate(1, 1, 2, false);
      else this->animate(1, 1, 1, false);
      if(Mouse::isLeftReleased()) GameProcess::navigate(this->create_previous_menu());
    } else this->animate(1, 1, 0, false);
  };

  ReturnButton::~ReturnButton() {};

  ReturnButton* ReturnButton::create(function<Menu*()> create_previous_menu) {
    ReturnButton* returnButton = new ReturnButton("return_button.png", Box(53, 16, 106, 32));
    returnButton->create_previous_menu = create_previous_menu;
    returnButton->animate(1, 1, 0, false);
    returnButton->pausable = false;
    returnButton->depth = 500;
    returnButton->position = CENTER;
    returnButton->scale(3);

    GameProcess::add(returnButton);
    return returnButton;
  };
};