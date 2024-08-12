#include <Objects/ammo_kit.hpp>

namespace Game {
  const unsigned int AmmoKit::charge = 12;
  
  string AmmoKit::type() {
    return "AmmoKit";
  };

  void AmmoKit::step() {
    this->timer.tick();
    if(this->timer.isFinished()) this->destroy();
  };

  AmmoKit::~AmmoKit() {};

  AmmoKit* AmmoKit::create(Point position) {
    AmmoKit* ammo_kit = new AmmoKit("ammo_kit.png", Box(6, 5, 12, 10));
    ammo_kit->setCircle(10);
    ammo_kit->scale(2);
    ammo_kit->depth = 50;
    ammo_kit->position = position;
    ammo_kit->position.y += 20.0;
    ammo_kit->timer.start(10);
    return ammo_kit;
  };
};