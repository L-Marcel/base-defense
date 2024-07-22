#include <Objects/player.hpp>
#include <Objects/bullet.hpp>
#include <Input.hpp>

namespace Game {
  string Player::type() {
    return "Player";
  };

  void Player::step() {
    // if(this->hasCircle){
    //   gp->window.draw(this->circle);
    // } else if(this->hasRectangle){
    //   gp->window.draw(this->rectangle);
    // };
    
    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      string type = collider->type();
      if(type == "Example") {
        collider->destroy();
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
    Bullet::create(this->gp, this, true);
    this->shoot_sound.setPitch(1 + ((rand() % 6) - 3) * 0.125);
    this->shoot_sound.play();
  };

  Player* Player::create(GameProcess* gp) {
    Player* player = new Player("player.png", Box(15, 13, 32, 32));
    player->speed = 5.0;
    player->animate(8, 1, 0, false);
    player->position = Vector<float>(640, 360);
    player->targetPosition = player->position;
    player->setCircle(32);
    player->depth = 100;
    player->gp = gp;
    gp->objects.add(player);
    return player;
  };
};