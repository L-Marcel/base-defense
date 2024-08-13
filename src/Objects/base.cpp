#include <Objects/base.hpp>
#include <Objects/enemy.hpp>

namespace Game {
  Base* Base::base = nullptr;
  bool Base::vengeful_bullets = false;
  bool Base::friendly_fire = true;
  
  string Base::type() {
    return "Base";
  };

  Base::~Base() {
    Base::base = nullptr;
  };

  Base* Base::create() {
    Base* base = new Base();
    base->health = Health(base, 100);
    base->clip = Ammo(base, 32);
    base->depth = -50;
    base->regeneration = 1;
    base->position = CENTER;
    base->setRectangle(BASE_SIZE.x, BASE_SIZE.y);
    Base::base = base;
    GameProcess::add(base);

    Tower* tower_one = Tower::create();
    tower_one->position = TOP_LEFT_TOWER_POSITION;
    tower_one->setRectangle(TOWER_SIZE, TOWER_SIZE);
    Sentry* sentry_one = Sentry::create();
    sentry_one->position = tower_one->position;
    Tower* tower_two = Tower::create();
    tower_two->position = BOTTOM_LEFT_TOWER_POSITION;
    tower_two->setRectangle(TOWER_SIZE, TOWER_SIZE);
    Sentry* sentry_two = Sentry::create();
    sentry_two->position = tower_two->position;
    Tower* tower_three = Tower::create();
    tower_three->position = TOP_RIGHT_TOWER_POSITION;
    tower_three->setRectangle(TOWER_SIZE, TOWER_SIZE);
    Sentry* sentry_three = Sentry::create();
    sentry_three->position = tower_three->position;
    Tower* tower_four = Tower::create();
    tower_four->position = BOTTOM_RIGHT_TOWER_POSITION;
    tower_four->setRectangle(TOWER_SIZE, TOWER_SIZE);
    Sentry* sentry_four = Sentry::create();
    sentry_four->position = tower_four->position;

    Enemy::wab = Wall::create(2);
    Enemy::wbc = Wall::create(1);
    Enemy::wcd = Wall::create(3);
    Enemy::wda = Wall::create(0);

    return base;
  };

  const Base* Base::get() {
    return Base::base;
  };
};