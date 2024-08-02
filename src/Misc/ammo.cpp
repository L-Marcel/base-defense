#include <Misc/ammo.hpp>

namespace Game {
  unsigned int Ammo::get() {
    return this->total;
  };

  float Ammo::percent() {
    return float(this->total / this->limit);
  };

  void Ammo::consume(unsigned int amount) {
    if(amount > this->total) {
      this->total = 0;
    } else {
      this->total = this->total - amount;
    };
  };

  void Ammo::recharge(unsigned int amount) {
    this->total = min(this->total + amount, this->limit);
  };

  void Ammo::upgrade(unsigned int amount) {
    this->limit += amount;
  };

  Ammo::Ammo() {};

  Ammo::Ammo(Object* object, unsigned int limit) {
    this->object = object;
    this->limit = limit;
    this->total = limit;
  };
}
