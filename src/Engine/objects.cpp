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
};