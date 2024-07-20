#include <Misc/health.hpp>

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
    };
  };

  void Health::heal(float amount) {
    this->total = min(this->total + amount, this->limit);
  };

  Health::Health() {};

  Health::Health(Object* object, float limit) {
    this->object = object;
    this->limit = limit;
    this->total = limit;
  };
}
