#include <Objects/base_wall.hpp>

namespace Game {
  string BaseWall::type() {
    return "BaseWall";
  };

  BaseWall::~BaseWall() {};

  BaseWall::BaseWall(string spriteSheet, Box box) 
  : Object2D(spriteSheet, box) {};

  BaseWall* BaseWall::create(GameProcess* gp, bool big) {
    BaseWall* base_wall;

    if(big) {
      base_wall = new BaseWall("long_base_wall.png", Box(90, 0, 180, 9));
    } else {
      base_wall = new BaseWall("short_base_wall.png", Box(58, 0, 116, 9));
    };

    base_wall->scale(2);
    base_wall->gp = gp;
    gp->objects.add(base_wall);
    return base_wall;
  };
};