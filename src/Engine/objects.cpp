#include <Engine.hpp>

namespace Game {
  void Object::step(GameProcess* gp) {};

  string Object::type() {
    return "Object";
  };

  void Object::draw(GameProcess* gp) {};
 
  Object::~Object() {};

  Object::Object() {};

  Object* Object::create(GameProcess* gp) {
    Object* instance = new Object();
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
  
  void Object::RectCollision(float width, float height){
    if(this->hasCCol == true) return;
    
    Vector<float> size;
    size.x = width;
    size.y = height;
    Rectangle rect(size);
    rect_collision = rect;
    rect_collision.setOrigin(width/2, height/2);
    this->rcolWidth = width;
    this->rcolHeight = height;
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