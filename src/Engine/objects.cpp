#include <Engine.hpp>

namespace Game {
  void Object::step(GameProcess* gp) {};
  string Object::type() {
    return "Object";
  };
 
  Object::~Object() {
    delete this->sprite;
    delete this->texture;
  };

  Object::Object(string spriteSheet, Box box) {
    this->sprite = new Sprite();
    this->texture = new Texture();

    if(this->texture->loadFromFile(spriteSheet)){
      this->sprite->setTexture(*this->texture);
      Vector<int> pos = box.getPosition();
      box.top = 0;
      box.left = 0;

      this->fps = 0;
      this->sprite->setTextureRect(box);
      this->sprite->setOrigin(pos.x, pos.y);
      this->sprite->setScale(1, 1);
    };
  };

  Object* Object::create(GameProcess* gp, string spriteSheet, Box box) {
    Object* instance = new Object(spriteSheet, box);
    instance->_list = &gp->objects;
    gp->objects.add(instance);
    return instance;
  };

  void Object::destroy() {
    if(this->_list) {
      this->_list->remove(this);
    };
    delete this;
  };

  void Object::animate(float fps, unsigned short int textureRow, bool loop, float image) {
    this->image = image;
    this->loop = loop;
    this->fps = fps;
    sf::IntRect old = this->sprite->getTextureRect();
    Vector<unsigned int> size = this->sprite->getTexture()->getSize();

    this->sprite->setTextureRect(Box((int(floor(this->image)) * old.width) % size.x, (textureRow * old.height) % size.y, old.width, old.height));
  };

  void Object::scale(float scale) {
    this->sprite->setScale(scale, scale);
  };

  void Object::scale(float xScale, float yScale) {
    this->sprite->setScale(xScale, yScale);
  };
};