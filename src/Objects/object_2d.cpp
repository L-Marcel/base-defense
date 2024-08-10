#include <Objects.hpp>

namespace Game {
  string Object2D::type() {
    return "Object2D";
  };

  void Object2D::step() {};

  void Object2D::collision() { 
    if(this->hasCircle){
      this->circle.setPosition(this->position.x, this->position.y);
    } else if(this->hasRectangle) {
      this->rectangle.setPosition(this->position.x, this->position.y);
    };

    this->colliders.clear();
    for(unsigned int i = 0; i < this->collisions.length(); i++) {
      Collision* collision = this->collisions.get(i);
      collision->step();
    };
  };

  void Object2D::draw() {
    if(this->hasCircle){
      this->circle.setPosition(this->position.x, this->position.y);
    } else if(this->hasRectangle) {
      this->rectangle.setPosition(this->position.x, this->position.y);
    };

    if(this->sprite != nullptr) {
      GameProcess::animate(this);
      GameProcess::draw(*this->sprite);
    };
  };

  Object2D::~Object2D() {};

  Object2D::Object2D() {};
  Object2D::Object2D(string spriteSheet, Box box) {
    this->sprite = Sprites::load("assets/sprites/" + spriteSheet, box);
    this->fps = 0;
  };

  Object2D* Object2D::create(string spriteSheet, Box box) {
    Object2D* instance = new Object2D(spriteSheet, box);
    GameProcess::add(instance);
    return instance;
  };

  void Object2D::free() {
    for(unsigned int i = 0; i < this->collisions.length(); i++) {
      Collision* collision = this->collisions.get(i);
      collision->destroy();
    };

    delete this;
  };

  void Object2D::animate(float fps, unsigned short int frames, unsigned short int textureRow, bool loop, float image) {
    this->image = image;
    this->frames = frames;
    this->loop = loop;
    this->fps = fps;
    sf::IntRect old = this->sprite->getTextureRect();
    Vector<unsigned int> size = this->sprite->getTexture()->getSize();

    this->sprite->setTextureRect(Box((int(floor(this->image)) * old.width) % (this->frames * old.width), (textureRow * old.height) % size.y, old.width, old.height));
  };

  void Object2D::scale(float scale) {
    this->sprite->setScale(scale, scale);
  };

  void Object2D::scale(float xScale, float yScale) {
    this->sprite->setScale(xScale, yScale);
  };

  void Object2D::setRectangle(float width, float height){
    if(this->hasCircle) return;

    this->rectangle.setSize(Point(width, height));
    this->rectangle.setOrigin(width/2, height/2);
    this->rectangle.setPosition(this->position.x, this->position.y);
    this->rectangleWidth = width;
    this->rectangleHeight = height;
    this->hasRectangle = true;
  };

  void Object2D::setCircle(float radius){
    if(this->hasRectangle) return;
    this->circle.setRadius(radius);
    this->circle.setOrigin(radius, radius);
    this->circle.setPosition(this->position.x, this->position.y);
    this->circleRadius = radius;
    this->hasCircle = true;
  };
};