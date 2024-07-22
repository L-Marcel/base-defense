#include <Objects/base.hpp>

namespace Game {
  string Base::type() {
    return "Base";
  };

  void Base::step() {
    // if(this->hasCircle){
    //   gp->window.draw(this->circle);
    // } else if(this->hasRectangle){
    //   gp->window.draw(this->rectangle);
    // };
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
    Tower* tower_two = Tower::create(gp);
    tower_two->position = Vector<float>(448, 488);
    Tower* tower_three = Tower::create(gp);
    tower_three->position = Vector<float>(832, 232);
    Tower* tower_four = Tower::create(gp);
    tower_four->position = Vector<float>(832, 488);

    Wall* wall_one = Wall::create(gp, false);
    wall_one->rotation = 270;
    wall_one->position = Vector<float>(432, 360);
    Wall* wall_two = Wall::create(gp, false);
    wall_two->rotation = 90;
    wall_two->position = Vector<float>(848, 360);
    Wall* wall_three = Wall::create(gp);
    wall_three->position = Vector<float>(640, 216);
    Wall* wall_four = Wall::create(gp);
    wall_four->rotation = 180;
    wall_four->position = Vector<float>(640, 504);

    BaseWall* base_wall_one = BaseWall::create(gp, false);
    base_wall_one->rotation = 270;
    base_wall_one->position = Vector<float>(432, 360);
    BaseWall* base_wall_two = BaseWall::create(gp, false);
    base_wall_two->rotation = 90;
    base_wall_two->position = Vector<float>(848, 360);
    BaseWall* base_wall_three = BaseWall::create(gp);
    base_wall_three->position = Vector<float>(640, 216);
    BaseWall* base_wall_four = BaseWall::create(gp);
    base_wall_four->rotation = 180;
    base_wall_four->position = Vector<float>(640, 504);
  
    return base;
  };
};