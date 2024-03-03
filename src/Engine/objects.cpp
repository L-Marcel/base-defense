#include "../../include/Engine.hpp"

namespace lm {
  Box::Box(int x, int y, int w, int h) : IntRect(Vector2(x, y), Vector2(w, h)) {};

  Object::Object() {
    this->onStep = [](Object* self, Room* room, GameProcess* gp) {};
  };

  Object::Object(string spriteSheet, Box box) {
    this->sprite = new Sprite();
    this->texture = new Texture();

    if(this->texture->loadFromFile(spriteSheet)){
      this->sprite->setTexture(*this->texture);
      Vector2 pos = box.getPosition();
      box.top = 0;
      box.left = 0;

      this->fps = 0;
      this->sprite->setTextureRect(box);
      this->sprite->setOrigin(pos.x, pos.y);
      this->sprite->setScale(1, 1);

      this->onStep = [](Object* self, Room* room, GameProcess* gp) {};
    };
  };

  void Object::animate(float fps, unsigned short int textureRow, bool loop, float image) {
    this->image = image;
    this->loop = loop;
    this->fps = fps;
    IntRect old = this->sprite->getTextureRect();
    Vector2u size = this->sprite->getTexture()->getSize();

    this->sprite->setTextureRect(Box((int(floor(this->image)) * old.width) % size.x, (textureRow * old.height) % size.y, old.width, old.height));
  };

  void Object::scale(float scale) {
    this->sprite->setScale(scale, scale);
  };

  void Object::scale(float xScale, float yScale) {
    this->sprite->setScale(xScale, yScale);
  };

  void Object::draw(RenderWindow* window, unsigned short int frame) {
    IntRect old = this->sprite->getTextureRect();
    Vector2u size = this->sprite->getTexture()->getSize();
    this->image += this->fps/60.f;

    int image = int(floor(this->image)) * old.width;

    if(!this->loop) image = min(image, int(size.x) - old.width);

    this->sprite->setTextureRect(Box(image % size.x, old.top, old.width, old.height));
    this->sprite->setPosition(this->x, this->y);
    window->draw(*this->sprite);
  };

  void Object::step(void (*func)(Object* self, Room* room, GameProcess* gp)) {
    this->onStep = func;
  };
};