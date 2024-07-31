#include <Buttons.hpp>

namespace Game{
  string Button::type() {
    return "Button";
  };

  Button::~Button() {};

  Button* Button::create(string sprite, Box box, bool pauseBt) {
    Button* button = new Button(sprite, box);
    button->pausable = !pauseBt;
    GameProcess::add(button);
    return button;
  };

  Button::Button(){ };

  Button::Button(string spriteSheet, Box box) {
    Texture* texture = new Texture();
    this->sprite = new Sprite();

    if(texture->loadFromFile("assets/sprites/" + spriteSheet)){
      this->sprite->setTexture(*texture);
      Vector<int> pos = box.getPosition();
      box.top = 0;
      box.left = 0;

      this->fps = 0;
      this->sprite->setTextureRect(box);
      this->sprite->setOrigin(pos.x, pos.y);
      this->sprite->setScale(1, 1);
    } else {
      throw new TextureNotFound(spriteSheet);
    };
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
};