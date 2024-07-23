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
      if(type == "Bullet") {
        Bullet* bullet = (Bullet*) collider;
        if(bullet->canBeBlocked) {
          collider->destroy();
        };
      };
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

    Wall* wall_one = Wall::create(gp, false);
    wall_one->rotation = 270;
    wall_one->position = Vector<float>(436, 360);
    wall_one->setRectangle(8, 232);
    Wall* wall_two = Wall::create(gp, false);
    wall_two->rotation = 90;
    wall_two->position = Vector<float>(844, 360);
    wall_two->setRectangle(8, 232);
    Wall* wall_three = Wall::create(gp);
    wall_three->position = Vector<float>(640, 220);
    wall_three->setRectangle(232, 8);
    Wall* wall_four = Wall::create(gp);
    wall_four->rotation = 180;
    wall_four->position = Vector<float>(640, 500);
    wall_four->setRectangle(232, 8);

    Collision::create(gp, base, "Bullet");

    return base;
  };
};