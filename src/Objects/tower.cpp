#include <Objects/tower.hpp>

namespace Game {
  string Tower::type() {
    return "Tower";
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
    return tower;
  };
};