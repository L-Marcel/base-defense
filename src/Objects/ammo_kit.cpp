#include <Objects/ammo_kit.hpp>

namespace Game {
  const unsigned int AmmoKit::charge = 10;
  
  string AmmoKit::type() {
    return "AmmoKit";
  };

  void AmmoKit::step() {
    this->timer.tick();
    if(this->timer.isFinished()) this->destroy();
  };

  AmmoKit::~AmmoKit() {};

  AmmoKit* AmmoKit::create(Point position) {
    AmmoKit* ammokit = new AmmoKit("ammokit.png", Box(6, 5, 12, 10));
    ammokit->setCircle(10);
    ammokit->scale(2);
    ammokit->depth = 50;
    ammokit->position = position;
    ammokit->position.y += 20.0;
    ammokit->timer.start(10);
    return ammokit;
  };
};