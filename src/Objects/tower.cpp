#include <Objects/base.hpp>

namespace Game {
  string Tower::type() {
    return "Tower";
  };

  void Tower::step() {
    bool baseIsEnergized = Base::get() != nullptr;
    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      string type = collider->type();
      if(type == "Bullet" && collider->depth <= this->depth) {
        Bullet* bullet = (Bullet*) collider;
        if(baseIsEnergized && (Base::friendly_fire || !bullet->isAlly)) 
          Base::get()->health.damage(bullet->damage / 5.0);
        collider->destroy();
      };
    };
  };

  Tower::~Tower() {};

  Tower::Tower(string spriteSheet, Box box) 
  : Object2D(spriteSheet, box) {};

  Tower* Tower::create() {
    Tower* tower = new Tower("tower.png", Box(8, 8, 16, 16));
    tower->depth = 200;
    tower->scale(2);
    GameProcess::add(tower);

    Collision::create(tower, "Bullet");

    return tower;
  };
};