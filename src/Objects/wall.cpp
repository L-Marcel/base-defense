#include <Objects/wall.hpp>

namespace Game {
  string Wall::type() {
    return "Wall";
  };

  void Wall::step() {
    bool wasEnabled = this->enabled;
    this->enabled = true;
    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      if(collider->type() == "Player") {
        this->enabled = false;
      };
    };

    bool changed = wasEnabled != this->enabled;
    if(changed && this->enabled) {
      this->animate(8, 4, 0, true);
    } else if(changed) {
      this->animate(0, 1, 1, false);
    };
  };

  Wall::~Wall() {};

  Wall::Wall(string spriteSheet, Box box) 
  : Object2D(spriteSheet, box) {};

  Wall* Wall::create(GameProcess* gp, bool big) {
    Wall* wall;

    if(big) {
      wall = new Wall("long_wall.png", Box(90, 2, 180, 4));
    } else {
      wall = new Wall("short_wall.png", Box(58, 2, 116, 4));
    };

    wall->depth = 200;
    wall->scale(2);
    wall->animate(8, 4, 0, true);
    wall->gp = gp;
    gp->objects.add(wall);

    Collision::create(gp, wall, "Player");

    return wall;
  };
};