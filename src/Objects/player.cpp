#include <Objects/enemy.hpp>
#include <Objects/base.hpp>
#include <Input.hpp>

namespace Game {
  string Player::type() {
    return "Player";
  };

  void Player::step() {
    // if(this->hasCircle){
    //   this->gp->window.draw(this->circle);
    // } else if(this->hasRectangle) {
    //   this->gp->window.draw(this->rectangle);
    // };

    this->safe = false;
    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      string type = collider->type();
      if(type == "Base") {
        this->safe = true;
        Base* base = (Base*) collider;
        if(this->path.isStopped()) {
          base->health.heal(1.0/60.0);
        } else {
          base->health.heal(1.0/180.0);
        };
      } else if(type == "Bullet"){
        Bullet* bullet = (Bullet*) collider;
        if(!bullet->isAlly()){
          collider->destroy();
          this->health.damage(bullet->damage);
        }
      };
    };
    
    Vector<float> mouse = Mouse::position(&this->gp->window);
    if(mouse != this->position) {
      this->rotation = Math::pointDirection(mouse - this->position) - 90.0;
    };

    if(Mouse::right()) {
      this->path.setDestiny(mouse);
    };

    Vector3<double> destiny = this->path.getDestiny(this->position, this->direction, this->speed);
    this->position.x = float(destiny.x);
    this->position.y = float(destiny.y);
    this->direction = destiny.z;

    if(this->animationFinished && (Input::fire() || Mouse::left())) {
      this->animate(8, 6, 1, false);
      this->shoot();
    };
  };
  
  Player::~Player() {
    for(unsigned int i = 0; i < this->gp->objects.length(); i++) {
      Object* object = this->gp->objects.get(i);
      if(object->type() == "Enemy") {
        Enemy* enemy = (Enemy*) object;
        enemy->player = nullptr;
      };
    };
  };

  void Player::shoot() {
    Bullet* bullet = Bullet::create(this->gp, this, true);
    bullet->damage = this->damage;
    bullet->canBeBlocked = !this->safe;
    this->shoot_sound.setPitch(1 + ((rand() % 6) - 3) * 0.125);
    this->shoot_sound.setVolume(50);
    this->shoot_sound.play();
  };

  Player* Player::create(GameProcess* gp) {
    Player* player = new Player("player.png", Box(16, 13, 32, 32));
    player->speed = 5.0;
    player->animate(8, 1, 0, false);
    player->position = CENTER;
    player->setCircle(11);
    player->depth = 150;
    player->gp = gp;
    gp->objects.add(player);

    Collision::create(gp, player, "Bullet");
    Collision::create(gp, player, "Base");

    return player;
  };
};