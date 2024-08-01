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

  Button::Button(string spriteSheet, Box box) 
  : Object2D(spriteSheet, box) {};

  Button* Button::create(string sprite, Box box, bool pauseBt) {
    Button* button = new Button(sprite, box);
    button->pausable = !pauseBt;
    GameProcess::add(button);
    return button;
  };
};