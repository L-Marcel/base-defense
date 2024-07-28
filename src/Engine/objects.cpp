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
    if(!this->free_queued) {
      this->gp->queue_free.add(this);
      this->free_queued = true;
    };
  };

  void Object::free() {
    if(this->gp) {
      this->gp->objects.remove(this);
    };
    delete this;
  };

  bool Object::isPausable(){
    return this->pausable;
  };

  bool Object::isVisible(){
    return this->visible;
  };

  void Object::setVisible(bool visible){
    this->visible = visible;
  }
};