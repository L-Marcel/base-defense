#include <Objects/player.hpp>
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
        if(this->targetPosition == this->position) {
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

    if(Mouse::right()){
      this->targetPosition = mouse;
    };

    if(this->targetPosition != this->position) {
      double distance = Math::pointDistance(this->targetPosition, this->position);

      Vector<float> difference = this->targetPosition - this->position;
      this->direction = Math::pointDirection(difference);
      this->position += Math::pointInRadius(
        min(double(this->speed), distance), 
        this->direction
      );
    };

    if(this->animationFinished && (Input::fire() || Mouse::left())) {
      this->animate(8, 6, 1, false);
      this->shoot();
    };
  };
  
  Player::~Player() {};

  void Player::shoot() {
    Bullet* bullet = Bullet::create(this->gp, this, true);
    bullet->damage = this->damage;
    bullet->canBeBlocked = !this->safe;
    this->shoot_sound.setPitch(1 + ((rand() % 6) - 3) * 0.125);
    this->shoot_sound.play();
  };

  Player* Player::create(GameProcess* gp) {
    Player* player = new Player("player.png", Box(16, 13, 32, 32));
    player->speed = 5.0;
    player->animate(8, 1, 0, false);
    player->position = Vector<float>(640, 360);
    player->targetPosition = player->position;
    player->setCircle(11);
    player->depth = 150;
    player->gp = gp;
    gp->objects.add(player);

    Collision::create(gp, player, "Bullet");
    Collision::create(gp, player, "Base");

    return player;
  };
};