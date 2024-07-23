#include <Objects/bullet.hpp>

namespace Game {
  void Bullet::step(){
    // if(this->hasCircle){
    //   this->gp->window.draw(this->circle);
    // } else if(this->hasRectangle) {
    //   this->gp->window.draw(this->rectangle);
    // };

    this->position += Math::pointInRadius(this->speed, this->direction);
    this->rotation = this->direction;
  };

  string Bullet::type() {
    return "Bullet";
  };

  Bullet::~Bullet() {};

  Bullet* Bullet::create(GameProcess* gp, Object2D* object, bool ally) {
    Bullet* bullet = new Bullet("bullet.png", Box(3, 1.5, 6, 3));
    bullet->depth = 50;
    bullet->position = object->position;
    bullet->setCircle(3);
    bullet->scale(2);
    bullet->direction = object->rotation + 90;
    bullet->speed = 14;
    bullet->ally = ally;
    bullet->gp = gp;
    gp->objects.add(bullet);
    return bullet;
  };

  bool Bullet::isAlly() {
    return this->ally;
  };
};