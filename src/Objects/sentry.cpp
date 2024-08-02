#include <Objects/base.hpp>
#include <Objects/enemy.hpp>

namespace Game {
  string Sentry::type() {
    return "Sentry";
  };

  void Sentry::step() {
    const Base* base = Base::get();
    this->energized = base != nullptr && base->clip.get() > 0;
    if(!this->energized && this->animationFinished) {
      this->animate(1, 1, int(!this->right), false);
      return;
    };

    Enemy* nearest = nullptr;
    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      string type = collider->type();
      if(
        type == "Enemy" &&
        (
          nearest == nullptr || 
          Math::pointDistance(this->position, collider->position) < Math::pointDistance(this->position, nearest->position)
        )
      ) nearest = (Enemy*) collider;
    };

    if(nearest != nullptr) {
      this->direction = Math::pointDirection(this->position - nearest->position);
      this->rotation = this->direction;

      if(this->animationFinished) {
        base->clip.consume(1);
        this->shoot();
      };
    } else if(this->animationFinished) {
      this->animate(1, 1, 2 + int(!this->right), false);
    };
  };

  void Sentry::shoot() {
    Bullet* bullet = Bullet::create(this, true);
    bullet->damage = this->damage;
    bullet->canBeBlocked = false;
    bullet->depth = 225;
    bullet->direction = this->rotation + 180;
    
    Point cannons_center = this->position - Math::pointInRadius(16, this->rotation);
    if(!this->right) {
      bullet->position = cannons_center + Math::pointInRadius(4, this->rotation + 90);
    } else {
      bullet->position = cannons_center + Math::pointInRadius(4, this->rotation + 270);
    };

    this->shoot_sound.setPitch(1 + ((rand() % 6) - 3) * 0.125);
    this->shoot_sound.play();
    this->animate(8, 6, 4 + int(!this->right), false);
    this->right = !this->right;
  };

  Sentry::~Sentry() {};

  Sentry::Sentry(string spriteSheet, Box box) 
  : Object2D(spriteSheet, box) {};

  Sentry* Sentry::create() {
    Sentry* sentry = new Sentry("sentry.png", Box(15, 8, 20, 16));
    sentry->depth = 250;
    sentry->scale(2);
    sentry->setCircle(256);
    sentry->animate(1, 1, 2, false);
    GameProcess::add(sentry);

    Collision::create(sentry, "Enemy");

    return sentry;
  };
};