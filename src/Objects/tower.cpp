#include <Objects/base.hpp>

namespace Game {
  string Tower::type() {
    return "Tower";
  };

  void Tower::step() {
    this->sprite->setColor(Color::White);
    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      string type = collider->type();
      if(type == "Player") {
        Color color = this->sprite->getColor();
        color.a = 125;
        this->sprite->setColor(color);
      } else if(type == "Bullet") {
        Bullet* bullet = (Bullet*) collider;
        base->health.damage(bullet->damage / 5.0);
        collider->destroy();
      };
    };
  };

  Tower::~Tower() {};

  Tower::Tower(string spriteSheet, Box box) 
  : Object2D(spriteSheet, box) {};

  Tower* Tower::create(Base* base) {
    Tower* tower = new Tower("tower.png", Box(8, 8, 16, 16));
    tower->depth = 10;
    tower->scale(2);
    tower->base = base;
    GameProcess::add(tower);

    Collision::create(tower, "Player");
    Collision::create(tower, "Bullet");

    return tower;
  };
};