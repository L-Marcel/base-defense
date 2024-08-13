#include <Misc/ammo.hpp>
#include <Objects/enemy.hpp>
#include <Objects/base.hpp>
#include <Input.hpp>

namespace Game {
  Player* Player::player = nullptr;
  
  string Player::type() {
    return "Player";
  };

  void Player::step() {    
    this->health.heal(regeneration / 60.0);
    this->attack_delay.tick();

    if(Base::get() == nullptr) return;

    if(GameProcess::getFrame() % 60 == 0) {
      this->safe = false;
    };

    bool bullet_can_be_blocked = true;
    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      string type = collider->type();
      if(type == "Base") {
        this->safe = true;
        bullet_can_be_blocked = false;
        Base* base = (Base*) collider;
        if(this->path.isStopped()) {
          base->health.heal(1.0/60.0 * base->regeneration);
        } else {
          base->health.heal(1.0/180.0 * base->regeneration);
        };
        break;
      };
    };

    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      string type = collider->type();
      if(type == "Bullet"){
        Bullet* bullet = (Bullet*) collider;
        if(!bullet->is_ally){
          collider->destroy();
          this->health.damage(bullet->damage);
        }
      } else if(type == "MedicalKit") {
        collider->destroy();
        this->health.heal(MedicalKit::heal);
      } else if(type == "AmmoKit") {
        collider->destroy();
        Base::get()->clip.recharge(AmmoKit::charge);
      };
    };

    if(this->legs == nullptr) return;
    
    Point mouse = Mouse::position();
    if(mouse != this->position) {
      this->rotation = Math::pointDirection(mouse - this->position) - 90.0;
      this->legs->rotation = Math::pointDirection(mouse - this->position) - 90.0;
    };

    if(Mouse::isRightDown()) {
      this->path.setDestiny(mouse);
    };

    Segment path = this->path.getPath(this->position, this->speed);
    if(this->position != path.end && this->legs->animation_finished) {
      this->legs->animate(8, 8, 0, true);
    } else if(this->position == path.end && !this->legs->animation_finished) {
      this->legs->animate(8, 1, 0, false);
    };
    
    this->position = path.end;
    this->direction = path.angle();

    this->legs->position.x = this->position.x;
    this->legs->position.y = this->position.y;
    if(this->attack_delay.isFinished() && (Input::isDown(Keyboard::Q) || Mouse::isLeftDown())) {
      this->shoot(bullet_can_be_blocked);
    } else if(this->animation_finished && Input::isDown(Keyboard::R)){
      this->recharge();
    };
  };
  
  Player::~Player() {
    Player::player = nullptr;
  };

  void Player::shoot(bool can_be_blocked) {
    if(this->clip.get() > 0) {
      Bullet* bullet = Bullet::create(this, true);
      bullet->damage = this->damage;
      bullet->can_be_blocked = can_be_blocked;

      float chance = (float(rand()) / RAND_MAX);
      if(chance >= (this->not_consume_ammo_chance / 100.0)) {
        this->clip.consume(1);
      };

      this->shoot_sound.setPitch(1 + ((rand() % 6) - 3) * 0.125);
      this->shoot_sound.play();
      this->animate(12, 6, 1, false);
    } else {
      this->empty_clip_sound.play();
    };
    this->attack_delay.start(1/this->attack_speed);    
  };

  void Player::recharge(){
    const Base* base = Base::get();
    if(base->clip.get() > 0 && this->clip.get() < this->clip.getLimit()){
      this->recharge_sound.play();
      unsigned int blankAmmo = this->clip.getLimit() - this->clip.get();
      this->clip.recharge(base->clip.get());
      base->clip.consume(blankAmmo);
      this->animate(8, 5, 2, false);
      this->attack_delay.start(1);
    };
  };

  Player* Player::create() {
    Player* player = new Player("player.png", Box(16, 13, 32, 32), 6);
    player->legs = Object2D::create("player_legs.png", Box(16, 13, 32, 32));
    player->legs->scale(2);
    player->legs->depth = 149;

    Player::player = player;
    player->attack_speed = 1.4;
    player->speed = 5.0;
    player->damage = 35;
    player->regeneration = 1;
    player->animate(8, 1, 0, false);
    player->position = CENTER;
    player->setCircle(11);
    player->depth = 150;
    player->scale(2);
    GameProcess::add(player);
    
    Collision::create(player, "Bullet");
    Collision::create(player, "Base");
    Collision::create(player, "MedicalKit");
    Collision::create(player, "AmmoKit");

    return player;
  };

  const Player* Player::get() {
    return Player::player;
  };
};