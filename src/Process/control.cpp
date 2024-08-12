#include <Game.hpp>

namespace Game {
  void GameProcess::add(Object* object) {
    GameProcess::gp->objects.add(object);
  };

  void GameProcess::destroy(Object* object) {
    GameProcess::gp->queueFree.add(object);
  };

  unsigned short int GameProcess::length() {
    return GameProcess::gp->objects.length();
  };

  Object* GameProcess::get(unsigned short int index) {
    return GameProcess::gp->objects.get(index);
  };

  void GameProcess::restart() {
    GameProcess::resume();
    GameProcess::gp->clear();
    GameProcess::gp->paused = false;

    Shop::reset();
    Shop::common_stock = {
      {"base", 7},
      {"health", 6},
      {"max_clip", 4},
      {"max_ammo", 6},
      {"attack_speed", 4}
    };
    Shop::rare_stock = {
      {"repair_speed", 9},
      {"regeneration", 7},
      {"sentry_speed", 4}
    };
    Shop::epic_stock = {
      {"ricochet", 1},
      {"friendly_fire", 1},
      {"ammo_consume", 1}
    };
    Spawn::spawn_speed = 0.50;
    Spawn::amount = 0;
    Spawn::wave = 0;
    Base::vengeful_bullets = false;
    Base::friendly_fire = true;
    Enemy::amount = 0;
    Sentry::not_consume_ammo_chance = 0;
    Sentry::attack_speed = 0.4;
  };
};