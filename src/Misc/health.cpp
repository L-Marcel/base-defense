#include <Misc/health.hpp>
#include <Engine/process.hpp>
#include <Objects/player.hpp>
#include <Objects/enemy.hpp>

namespace Game {
  float Health::get() {
    return this->total;
  };

  float Health::getLimit(){
    return this->limit;
  };

  float Health::percent() {
    return this->total/this->limit;
  };

  void Health::damage(float amount) {
    this->total = max(this->total - amount, 0.0f);
    if(this->total <= 0 && this->object != nullptr) {
      string type = this->object->type();
      this->object->destroy();
      if(type == "Player") {
        Player* player = (Player*) this->object;
        player->legs->destroy();
        player->legs = nullptr;
      } else if(type == "Enemy") {
        Enemy* enemy = (Enemy*) this->object;
        enemy->legs->destroy();
        enemy->legs = nullptr;
      };
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
