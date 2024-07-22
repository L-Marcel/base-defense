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
      gp->window.draw(this->circle);
    } else if(this->hasRectangle == true){
      gp->window.draw(this->rectangle);
    };
    this->gp->animate(this);
    this->gp->window.draw(*this->sprite);
  };

  Object2D::~Object2D() {
    delete this->sprite->getTexture();
    delete this->sprite;
  };

  Object2D::Object2D(string spriteSheet, Box box) {
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

  Object2D* Object2D::create(GameProcess* gp, string spriteSheet, Box box) {
    Object2D* instance = new Object2D(spriteSheet, box);
    instance->gp = gp;
    gp->objects.add(instance);
    return instance;
  };

  void Object2D::free() {
    if(this->gp) {
      this->gp->objects.remove(this);
    };

    for(unsigned int i = 0; i < this->collisions.length(); i++) {
      Collision* collision = this->collisions.get(i);
      collision->destroy();
    };

    delete this;
  };

  void Object2D::animate(float fps, unsigned short int textureRow, bool loop, float image) {
    this->image = image;
    this->loop = loop;
    this->fps = fps;
    sf::IntRect old = this->sprite->getTextureRect();
    Vector<unsigned int> size = this->sprite->getTexture()->getSize();

    this->sprite->setTextureRect(Box((int(floor(this->image)) * old.width) % size.x, (textureRow * old.height) % size.y, old.width, old.height));
  };

  void Object2D::scale(float scale) {
    this->sprite->setScale(scale, scale);
  };

  void Object2D::scale(float xScale, float yScale) {
    this->sprite->setScale(xScale, yScale);
  };

  void Object2D::setRectangle(float width, float height){
    if(this->hasCircle) return;

    this->rectangle.setSize(Vector<float>(width, height));
    this->rectangle.setOrigin(width/2, height/2);
    this->rectangleWidth = width;
    this->rectangleHeight = height;
    this->hasRectangle = true;
  };

  void Object2D::setCircle(float radius){
    if(this->hasRectangle) return;
    this->circle.setRadius(radius);
    this->circle.setOrigin(radius, radius);
    this->circleRadius = radius;
    this->hasCircle = true;
  };
};