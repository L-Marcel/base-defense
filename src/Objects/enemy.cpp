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
        };
      };
    };

    if(this->player == nullptr) return;

    Vector3<double> destiny = this->path.getDestiny(this->position, this->direction, this->speed, this->range);
    this->position.x = float(destiny.x);
    this->position.y = float(destiny.y);
    this->direction = destiny.z;
    this->rotation = this->direction - 90.0;

    bool canShoot = this->path.isStopped();

    if(this->animationFinished && canShoot) {
      this->animate(2, 4, 0, false);
      this->shoot();
    };
  };

  Enemy::~Enemy() {};

  Enemy* Enemy::create(GameProcess* gp, Player* player) {
    Enemy* enemy = new Enemy("canhao.png", Box(16, 16, 32, 32));
    enemy->player = player;
    enemy->path = Playerfinder(player);
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