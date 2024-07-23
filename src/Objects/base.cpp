#include <Objects/base.hpp>
#include <Objects/bullet.hpp>


namespace Game {
  string Base::type() {
    return "Base";
  };

  void Base::step() {
    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      string type = collider->type();
      //
    };
  };

  Base::~Base() {};

  Base* Base::create(GameProcess* gp) {
    Base* base = new Base();
    base->depth = -50;
    base->position = Vector<float>(640, 360);
    base->setRectangle(416, 288);
    base->gp = gp;
    gp->objects.add(base);

    Tower* tower_one = Tower::create(gp);
    tower_one->position = Vector<float>(448, 232);
    tower_one->setRectangle(32, 32);
    Tower* tower_two = Tower::create(gp);
    tower_two->position = Vector<float>(448, 488);
    tower_two->setRectangle(32, 32);
    Tower* tower_three = Tower::create(gp);
    tower_three->position = Vector<float>(832, 232);
    tower_three->setRectangle(32, 32);
    Tower* tower_four = Tower::create(gp);
    tower_four->position = Vector<float>(832, 488);
    tower_four->setRectangle(32, 32);

    Wall::create(gp, 0);
    Wall::create(gp, 1);
    Wall::create(gp, 2);
    Wall::create(gp, 3);

    return base;
  };
};