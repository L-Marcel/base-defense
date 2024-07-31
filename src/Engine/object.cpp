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

  Object* Object::create() {
    Object* instance = new Object();
    GameProcess::add(instance);
    return instance;
  };

  void Object::destroy() {
    if(!this->free_queued) {
      GameProcess::destroy(this);
      this->free_queued = true;
    };
  };

  void Object::free() {
    delete this;
  };

  bool Object::isPausable(){
    return this->pausable;
  };
};