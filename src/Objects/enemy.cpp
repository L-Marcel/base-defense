#include <Objects/enemy.hpp>

namespace Game {
  string Enemy::type() {
    return "Enemy";
  };

  void Enemy::step() {
    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      string type = collider->type();
      if(type == "Bullet"){
        Bullet* bullet = (Bullet*) collider;
        if(bullet->isAlly()){
          collider->destroy();
          this->health.damage(bullet->damage);
        }
      }
    };

    double playerDistance = Math::pointDistance(this->targetPlayer->position, this->position);
    double baseDistance = Math::pointDistance(this->base->position, this->position);

    if(this->base->position != this->position && baseDistance > this->range) {
      Vector<float> difference = this->base->position - this->position;
      this->direction = Math::pointDirection(difference);
      this->position += Math::pointInRadius(
        min(double(this->speed), playerDistance), 
        this->direction
      );
    };

    if(playerDistance <= this->range){
      this->rotation = Math::pointDirection(this->targetPlayer->position - this->position) - 90.0;
    } else {
      this->rotation = Math::pointDirection(this->base->position - this->position) - 90.0;
    };

    if(this->animationFinished && (baseDistance <= this->range || playerDistance <= this->range)){
      this->animate(2, 4, 0, false);
      this->shoot();
    };
  };

  Enemy::~Enemy() {};

  Enemy* Enemy::create(GameProcess* gp, Player* player, Object2D* base){
    Enemy* enemy = new Enemy("canhao.png", Box(16, 16, 32, 32));
    enemy->targetPlayer = player;
    enemy->base = base;
    enemy->speed = 1.0;
    enemy->position = Vector<float>(600.f, 100.f);
    enemy->setCircle(12);
    enemy->circle.setFillColor(Color::Blue);
    enemy->depth = 100;
    enemy->gp = gp;
    gp->objects.add(enemy);
    return enemy;
  };

  void Enemy::shoot(){
    Bullet* bullet = Bullet::create(this->gp, this);
    bullet->damage = this->damage;
    this->shoot_sound.setPitch(1 + ((rand() % 6) - 3) * 0.125);
    this->shoot_sound.setVolume(50);
    this->shoot_sound.play();
  };
};