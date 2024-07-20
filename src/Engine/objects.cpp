#include <Engine.hpp>

namespace Game {
  string Object::type() {
    return "Object";
  };

  void Object::step() {};

  void Object::collision() {};

  void Object::draw() {};
 
  Object::~Object() {};

  Object::Object() {};

  Object* Object::create(GameProcess* gp) {
    Object* instance = new Object();
    instance->gp = gp;
    gp->objects.add(instance);
    return instance;
  };

  void Object::destroy() {
    this->gp->queue_free.add(this);
  };

  void Object::free() {
    if(this->gp) {
      this->gp->objects.remove(this);
    };
    delete this;
  };
};