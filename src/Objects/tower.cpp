#include <Objects/tower.hpp>

namespace Game {
  string Tower::type() {
    return "Tower";
  };

  void Tower::step() {
    this->sprite->setColor(Color::White);
    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      if(collider->type() == "Player") {
        Color color = this->sprite->getColor();
        color.a = 125;
        this->sprite->setColor(color);
      };
    };
  };

  Tower::~Tower() {};

  Tower::Tower(string spriteSheet, Box box) 
  : Object2D(spriteSheet, box) {};

  Tower* Tower::create(GameProcess* gp) {
    Tower* tower = new Tower("tower.png", Box(8, 8, 16, 16));
    tower->depth = 200;
    tower->scale(2);
    tower->gp = gp;
    gp->objects.add(tower);

    Collision::create(gp, tower, "Player");

    return tower;
  };
};