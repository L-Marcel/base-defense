#include <Objects/enemy.hpp>

namespace Game {
  Wall* Enemy::wab = nullptr;
  Wall* Enemy::wbc = nullptr;
  Wall* Enemy::wcd = nullptr;
  Wall* Enemy::wda = nullptr;

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
          if(this->free_queued){
            MedicalKit* medkit = MedicalKit::create(this->position);
            medkit->drop();
          }
        }
      }
    };

    const Player* player = Player::get();
    if(player == nullptr) return;

    if(this->animationFinished) {
      Segment path = this->path.getPath(this->position, this->speed, this->range);
      this->position = path.end;

      if(player->safe && this->path.isStopped()) {
        unsigned short int sector = this->path.getSector(this->position);
        switch(sector) {
          case 0:
            this->direction = Math::pointDirection(
              Playerfinder::rab.start - this->position
            );
            break;
          case 1:
            if(this->wab->enabled && !this->focusingBase) {
              this->focusingBase = true;
              this->direction = Math::pointDirection(
                Point(
                  clamp(this->position.x + (rand() % 101) - 50, Playerfinder::rab.start.x, Playerfinder::rab.end.x),
                  Playerfinder::rab.start.y
                ) - this->position
              );
            } else if(!this->wab->enabled) {
              this->focusingBase = false;
              this->direction = Math::pointDirection(player->position - this->position);
            };
            break;
          case 2:
            this->direction = Math::pointDirection(
              Playerfinder::rbc.start - this->position
            );
            break;
          case 3:
            if(this->wda->enabled && !this->focusingBase) {
              this->focusingBase = true;
              this->direction = Math::pointDirection(
                Point(
                  Playerfinder::rda.start.x,
                  clamp(this->position.y + (rand() % 101) - 50, Playerfinder::rda.end.y, Playerfinder::rda.start.y)
                ) - this->position
              );
            } else if(!this->wda->enabled) {
              this->focusingBase = false;
              this->direction = Math::pointDirection(player->position - this->position);
            };
            break;
          case 5:
            if(this->wbc->enabled && !this->focusingBase) {
              this->focusingBase = true;
              this->direction = Math::pointDirection(
                Point(
                  Playerfinder::rbc.start.x,
                  clamp(this->position.y + (rand() % 101) - 50, Playerfinder::rbc.start.y, Playerfinder::rbc.end.y)
                ) - this->position
              );
            } else if(!this->wbc->enabled) {
              this->focusingBase = false;
              this->direction = Math::pointDirection(player->position - this->position);
            };
            break;
          case 6:
            this->direction = Math::pointDirection(
              Playerfinder::rda.start - this->position
            );
            break;
          case 7:
            if(this->wcd->enabled && !this->focusingBase) {
              this->focusingBase = true;
              this->direction = Math::pointDirection(
                Point(
                  clamp(this->position.x + (rand() % 101) - 50, Playerfinder::rcd.end.x, Playerfinder::rcd.start.x),
                  Playerfinder::rcd.start.y
                ) - this->position
              );
            } else if(!this->wcd->enabled) {
              this->focusingBase = false;
              this->direction = Math::pointDirection(player->position - this->position);
            };
            break;
          case 8:
            this->direction = Math::pointDirection(
              Playerfinder::rcd.start - this->position
            );
            break;
          default:
            break;
        };
      } else if(player->safe) {
        this->direction = path.angle();
      } else if(this->path.isStopped()) {
        this->focusingBase = false;
        this->direction = Math::pointDirection(player->position - this->position);
      } else {
        this->focusingBase = false;
        this->direction = path.angle();
      };

      this->rotation = this->direction - 90.0;
      bool canShoot = this->path.isStopped();
      if(canShoot) {
        this->animate(8, 6, 1, false);
        this->shoot();
      };
    };
  };

  Enemy::~Enemy() {};

  Enemy* Enemy::create() {
    Enemy* enemy = new Enemy("enemy.png", Box(16, 16, 32, 32));
    enemy->speed = 1.25;
    enemy->animate(8, 1, 0, false);
    enemy->position = Point(600.f, 100.f);
    enemy->setCircle(12);
    enemy->circle.setFillColor(Color::Blue);
    enemy->depth = 100;
    enemy->scale(2);
    GameProcess::add(enemy);

    Collision::create(enemy, "Bullet");

    return enemy;
  };

  void Enemy::shoot(){
    Bullet* bullet = Bullet::create(this);
    bullet->damage = this->damage;
    this->shoot_sound.setPitch(1 + ((rand() % 6) - 3) * 0.125);
    this->shoot_sound.setVolume(50);
    this->shoot_sound.play();
  };
};