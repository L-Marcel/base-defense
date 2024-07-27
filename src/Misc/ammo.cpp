#include <Misc/ammo.hpp>

namespace Game {
  float Ammo::get() {
    return this->total;
  };

  void Ammo::shoot(float amount) {
    this->total = max(this->total - amount, 0.0f);
    if(this->total <= 0 && this->object != nullptr) {
      printf("Sem munição!");
    };
  };

  void Ammo::recharge(float amount) {
    this->total = min(this->total + amount, this->limit);
  };

  Ammo::Ammo() {};

  Ammo::Ammo(Object* object, float limit) {
    this->object = object;
    this->limit = limit;
    this->total = limit;
  };
}
