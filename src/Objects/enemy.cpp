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
          this->health.damage(50);
        }
      }
    };

    double playerDistance = Math::pointDistance(this->targetPlayer->position, this->position);
    double baseDistance = Math::pointDistance(this->Base->position, this->position);

    if(this->Base->position != this->position && baseDistance > this->Range) {
      Vector<float> difference = this->Base->position - this->position;
      this->direction = Math::pointDirection(difference);
      this->position += Math::pointInRadius(
        min(double(this->speed), playerDistance), 
        this->direction
      );
    };

    if(playerDistance <= this->Range){
      this->rotation = Math::pointDirection(this->targetPlayer->position - this->position) - 90.0;
    } 
    else {
      this->rotation = Math::pointDirection(this->Base->position - this->position) - 90.0;
    }

    if(this->animationFinished && (baseDistance <= this->Range || playerDistance <= this->Range)){
      this->animate(8, 0, false);
      this->shoot();
    };
  };

  Enemy::~Enemy() {};

  Enemy* Enemy::create(GameProcess* gp, Player* player, Object2D* base){
    Enemy* enemy = new Enemy("canhao.png", Box(16, 16, 32, 32));
    enemy->targetPlayer = player;
    enemy->Base = base;
    enemy->speed = 1.0;
    enemy->setCircle(12);
    enemy->circle.setFillColor(Color::Blue);
    enemy->position = Vector<float>(600.f, 100.f);
    enemy->gp = gp;
    gp->objects.add(enemy);
    return enemy;
  };

  void Enemy::shoot(){
    Bullet::create(this->gp, this);
    this->shoot_sound.setPitch(1 + ((rand() % 6) - 3) * 0.125);
    this->shoot_sound.play();
  };
};