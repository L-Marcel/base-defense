#include <Objects/ammo_kit.hpp>

namespace Game {
  string AmmoKit::type() {
    return "AmmoKit";
  };

  void AmmoKit::step() {
    this->timer.start();
    if(this->timer.isFinished()) this->destroy();
  };

  AmmoKit::~AmmoKit() {};

  AmmoKit* AmmoKit::create(Point position) {
    AmmoKit* ammokit = new AmmoKit("ball.png", Box(8, 8, 16, 16));
    ammokit->setCircle(10);
    ammokit->scale(2);
    ammokit->depth = 50;
    ammokit->position = position;
    ammokit->position.y += 20.0;
    ammokit->timer.setDuration(10);
    return ammokit;
  };
};