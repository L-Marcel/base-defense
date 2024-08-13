#include <Objects/base.hpp>
#include <Objects/enemy.hpp>

namespace Game {
  float Sentry::not_consume_ammo_chance = 0;
  float Sentry::attack_speed = 0.4;
  
  string Sentry::type() {
    return "Sentry";
  };

  void Sentry::step() {
    this->attack_delay.tick();
    const Base* base = Base::get();

    this->energized = base != nullptr && base->clip.get() > 0;
    if(!this->energized && this->animation_finished) {
      this->animate(1, 1, int(!this->right), false);
      return;
    };

    if(base == nullptr) return;

    bool has_target = false;
    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      if(collider->type() == "Enemy" && this->target == collider->position) {
        has_target = true;
        break;
      };
    };

    if(!has_target) {
      for(unsigned int i = 0; i < this->colliders.length(); i++) {
        Object2D* collider = this->colliders.get(i);
        string type = collider->type();
        if(type == "Enemy" &&
          (
            !has_target ||
            Math::pointDistance(this->position, collider->position) < Math::pointDistance(this->position, target)
          )
        ) {
          this->target = collider->position;
          has_target = true;
        };
      };
    };

    if(has_target) {
      this->direction = Math::pointDirection(this->position - this->target);
      this->rotation = this->direction;

      if(this->attack_delay.isFinished() && base->clip.get() > 0) {
        float chance = (rand() % 10000) / 100.0;
        if(chance >= (this->not_consume_ammo_chance / 100.0)) {
          base->clip.consume(1);
        };
        
        this->shoot();
      };
    } else if(this->animation_finished) {
      this->animate(1, 1, 2 + int(!this->right), false);
      this->attack_delay.start(1/this->attack_speed);
    };
  };

  void Sentry::shoot() {
    Bullet* bullet = Bullet::create(this, true);
    bullet->damage = 50;
    bullet->can_be_blocked = false;
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
    this->attack_delay.start(1/this->attack_speed);
  };

  Sentry::~Sentry() {};

  Sentry::Sentry(string sprite_sheet, Box box) 
  : Object2D(sprite_sheet, box) {};

  Sentry* Sentry::create() {
    Sentry* sentry = new Sentry("sentry.png", Box(15, 8, 20, 16));
    sentry->depth = 250;
    sentry->scale(2);
    sentry->setCircle(256);
    sentry->animate(1, 1, 2, false);
    GameProcess::add(sentry);
    sentry->attack_delay.start(1/sentry->attack_speed);
    Collision::create(sentry, "Enemy");

    return sentry;
  };
};