#include <Buttons.hpp>

namespace Game{
  string Button::type() {
    return "Button";
  };

  Button::~Button() {};

  Button* Button::create(string sprite, Box box, bool pauseBt) {
    Button* button = new Button(sprite, box);
    button->pausable = !pauseBt;
    button->buttonWidth = box.getSize().x;
    button->buttonHeight = box.getSize().y;
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

  bool Button::wasBridged(){
    return this->bridged;
  };

  void Button::setBridged(bool bridged){
    this->bridged = bridged;
  };

  bool Button::isMouseHovering(){
    Point mouse = Mouse::position();
    return (
      mouse.x <= (this->position.x + this->buttonWidth) &&
      mouse.x >= (this->position.x - this->buttonWidth) &&
      mouse.y <= (this->position.y + this->buttonHeight) &&
      mouse.y >= (this->position.y - this->buttonHeight) &&
      this->visible
    );
  };
};