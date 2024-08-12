#include <Buttons.hpp>

namespace Game{
  string Button::type() {
    return "Button";
  };

  bool Button::isHovered(){
    Point mouse = Mouse::position();
    int width = this->sprite->getTextureRect().width * this->sprite->getScale().x;
    int height = this->sprite->getTextureRect().height * this->sprite->getScale().y;

    return (
      mouse.x <= (this->position.x + width/2.0) &&
      mouse.x >= (this->position.x - width/2.0) &&
      mouse.y <= (this->position.y + height/2.0) &&
      mouse.y >= (this->position.y - height/2.0) &&
      this->visible &&
      !this->free_queued
    );
  };

  Button::~Button() {};

  Button::Button() {};

  Button::Button(string sprite_sheet, Box box) 
  : Object2D(sprite_sheet, box) {};

  Button* Button::create(string sprite, Box box, bool pause_button) {
    Button* button = new Button(sprite, box);
    button->pausable = !pause_button;
    GameProcess::add(button);
    return button;
  };
};