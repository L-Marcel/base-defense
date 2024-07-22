#include <Objects/example.hpp>

namespace Game{
  string Example::type(){
    return "Example";
  };

  void Example::step() {
    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      if(collider->type() == "Bullet") {
        collider->destroy();
        this->health.damage(20);
      };
    };
  };

  void Example::draw() {
    if(this->hasCircle){
      this->circle.setPosition(this->position.x, this->position.y);
    } else if(this->hasRectangle) {
      this->rectangle.setPosition(this->position.x, this->position.y);
    };

    if(this->hasCircle){
      this->gp->window.draw(this->circle);
    } else if(this->hasRectangle){
      this->gp->window.draw(this->rectangle);
    };
  };

  Example::~Example() {};

  Example* Example::create(GameProcess* gp, string spriteSheet, Box box) {
    Example* example = new Example(spriteSheet, box);
    example->gp = gp;
    gp->objects.add(example);
    return example;
  };
};