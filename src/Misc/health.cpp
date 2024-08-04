#include <Misc/health.hpp>

namespace Game {
  float Health::get() const{
    return this->total;
  };

  float Health::percent() const{
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
