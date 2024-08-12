#include <Misc/health.hpp>
#include <Engine/process.hpp>

namespace Game {
  float Health::get() {
    return this->total;
  };

  float Health::percent() {
    return this->total/this->limit;
  };

  void Health::damage(float amount) {
    this->total = max(this->total - amount, 0.0f);
    if(this->total <= 0 && this->object != nullptr) {
      this->object->destroy();
      string type = this->object->type();
      if(type == "Player" || type == "Base") GameProcess::defeat();
    };
  };

  void Health::heal(float amount) {
    this->total = min(this->total + amount, this->limit);
  };

  void Health::upgrade(float amount) {
    this->limit += amount;
  };

  Health::Health() {};

  Health::Health(Object* object, float limit) {
    this->object = object;
    this->limit = limit;
    this->total = limit;
  };
}
