#include <Objects/wall.hpp>

namespace Game {
  string Wall::type() {
    return "Wall";
  };

  Wall::~Wall() {};

  Wall::Wall(string spriteSheet, Box box) 
  : Object2D(spriteSheet, box) {};

  Wall* Wall::create(GameProcess* gp, bool big) {
    Wall* wall;

    if(big) {
      wall = new Wall("long_wall.png", Box(90, 0, 180, 4));
    } else {
      wall = new Wall("short_wall.png", Box(58, 0, 116, 4));
    };

    wall->depth = 200;
    wall->scale(2);
    wall->gp = gp;
    gp->objects.add(wall);
    return wall;
  };
};