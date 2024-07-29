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

    Segment path = this->path.getDestiny(this->position, this->speed, this->range);
    this->position = path.end;

    if(this->player->safe && this->path.isStopped()) {
      if(!this->focusingBase) {
        unsigned short int sector = this->path.getSector(this->position);
        this->focusingBase = true;
        switch(sector) {
          case 0:
            this->direction = Math::pointDirection(
              this->path.rab.start - this->position
            );
            break;
          case 1:
            this->direction = Math::pointDirection(
              Point(
                clamp(this->position.x + (rand() % 101) - 50, this->path.rab.start.x, this->path.rab.end.x),
                this->path.rab.start.y
              ) - this->position
            );
            break;
          case 2:
            this->direction = Math::pointDirection(
              this->path.rbc.start - this->position
            );
            break;
          case 3:
            this->direction = Math::pointDirection(
              Point(
                this->path.rda.start.x,
                clamp(this->position.y + (rand() % 101) - 50, this->path.rda.end.y, this->path.rda.start.y)
              ) - this->position
            );
            break;
          case 5:
            this->direction = Math::pointDirection(
              Point(
                this->path.rbc.start.x,
                clamp(this->position.y + (rand() % 101) - 50, this->path.rbc.start.y, this->path.rbc.end.y)
              ) - this->position
            );
            break;
          case 6:
            this->direction = Math::pointDirection(
              this->path.rda.start - this->position
            );
            break;
          case 7:
            this->direction = Math::pointDirection(
              Point(
                clamp(this->position.x + (rand() % 101) - 50, this->path.rcd.end.x, this->path.rcd.start.x),
                this->path.rcd.start.y
              ) - this->position
            );
            break;
          case 8:
            this->direction = Math::pointDirection(
              this->path.rcd.start - this->position
            );
            break;
          default:
            break;
        };
      };
    } else if(this->player->safe) {
      this->direction = path.angle();
    } else if(this->path.isStopped()) {
      this->focusingBase = false;
      this->direction = Math::pointDirection(this->player->position - this->position);
    } else {
      this->focusingBase = false;
      this->direction = path.angle();
    };

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
    enemy->position = Point(600.f, 100.f);
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