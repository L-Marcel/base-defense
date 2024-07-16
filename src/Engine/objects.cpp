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
  Object::Object() {};
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

  /*
  Object::Object(string spriteSheet, Box box, int width, int height) {
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
  */

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
  
  void Object::RectCollision(float height, float width){
    if(this->hasCCol == true) return;
    
    Vector<float> size;
    size.x = height;
    size.y = width;
    Rectangle rect(size);
    rect_collision = rect;
    rect_collision.setOrigin(height/2, width/2);
    this->rcolHeight = height;
    this->rcolWidth = width;
    this->hasRCol = true;
  }

  void Object::CircCollision(float Radius){
    if(this->hasRCol == true) return;

    Circle circ(Radius);
    circ_collision = circ;
    circ_collision.setOrigin(Radius, Radius);
    this->cRadius = Radius;
    this->hasCCol = true;
  }

  Vector<float> Object::getPos(){
    Vector<float> posicao;
    posicao.x = this->x;
    posicao.y = this->y;
    return posicao;
  }
};