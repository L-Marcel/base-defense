#include <Objects/enemy.hpp>
#include <Objects/base.hpp>
#include <Input.hpp>

namespace Game {
  Player* Player::player = nullptr;
  
  string Player::type() {
    return "Player";
  };

  void Player::step() {
    // if(this->hasCircle){
    //   this->GameProcess::draw(this->circle);
    // } else if(this->hasRectangle) {
    //   this->GameProcess::draw(this->rectangle);
    // };
    
    if(GameProcess::getFrame() % 60 == 0) {
      this->safe = false;
    };

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
      } else if(type == "MedicalKit") {
        collider->destroy();
        this->health.heal(10);
      };
    };
    
    Point mouse = Mouse::position();
    if(mouse != this->position) {
      this->rotation = Math::pointDirection(mouse - this->position) - 90.0;
    };

    if(Mouse::isRightDown()) {
      this->path.setDestiny(mouse);
    };

    Segment path = this->path.getPath(this->position, this->speed);
    this->position = path.end;
    this->direction = path.angle();

    if(this->animationFinished && (Input::isDown(Keyboard::Q) || Mouse::isLeftDown())) {
      this->animate(8, 6, 1, false);
      this->shoot();
    };
  };
  
  Player::~Player() {
    Player::player = nullptr;
  };

  void Player::shoot() {
    Bullet* bullet = Bullet::create(this, true);
    bullet->damage = this->damage;
    bullet->canBeBlocked = !this->safe;
    this->shoot_sound.setPitch(1 + ((rand() % 6) - 3) * 0.125);
    this->shoot_sound.setVolume(50);
    this->shoot_sound.play();
  };

  Player* Player::create() {
    Player* player = new Player("player.png", Box(16, 13, 32, 32));

    if(Player::player != nullptr) {
      delete Player::player;
    };

    Player::player = player;
    player->speed = 5.0;
    player->damage = 35;
    player->animate(8, 1, 0, false);
    player->position = CENTER;
    player->setCircle(11);
    player->depth = 150;
    GameProcess::add(player);
    
    Collision::create(player, "Bullet");
    Collision::create(player, "Base");
    Collision::create(player, "MedicalKit");

    return player;
  };

  const Player* Player::get() {
    return Player::player;
  };
};