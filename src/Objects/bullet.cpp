#include <Objects/bullet.hpp>

namespace Game {
  void Bullet::step(){
    this->position += Math::pointInRadius(this->speed, this->direction);
  };

  string Bullet::type() {
    return "Bullet";
  };

  Bullet::~Bullet() {};

  Bullet* Bullet::create(GameProcess* gp, Object2D* object, bool ally) {
    Bullet* bullet = new Bullet("bullet.png", Box(8, 8, 16, 16));
    bullet->position = object->position;
    bullet->setCircle(18);
    bullet->scale(1);
    bullet->direction = object->rotation + 90;
    bullet->speed = 7;
    bullet->ally = ally;
    bullet->gp = gp;
    gp->objects.add(bullet);
    return bullet;
  };

  bool Bullet::isAlly() {
    return this->ally;
  };
};