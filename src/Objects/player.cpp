#include <Objects/player.hpp>
#include <Objects/bullet.hpp>
#include <Misc/ammo.hpp>
#include <Input.hpp>

namespace Game {
  string Player::type() {
    return "Player";
  };

  void Player::step() {
    if(this->hasCircle){
      gp->window.draw(this->circle);
    } else if(this->hasRectangle == true){
      gp->window.draw(this->rectangle);
    };
    
    for(unsigned int i = 0; i < this->colliders.length(); i++) {
      Object2D* collider = this->colliders.get(i);
      string type = collider->type();
      if(type == "Example") {
        collider->destroy();
        this->scale(8.0);
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
      if(this->firstAttack) this->animate(8, 0, false);
      else this->animate(8, 1, false);
      
      this->firstAttack = !this->firstAttack;
      this->shoot();
    };
  };
  
  Player::~Player() {};

  void Player::shoot() {
    if (this->ammo.get() > 0)
    {
      Bullet::create(this->gp, this, true);
      this->ammo.shoot(1);
      this->shoot_sound.setPitch(1 + ((rand() % 6) - 3) * 0.125);
      this->shoot_sound.play();
    }else
    {
      this->empty_clip_sound.setPitch(1 + ((rand() % 6) - 3) * 0.125);
      this->empty_clip_sound.play();
    }
    
  };

  Player* Player::create(GameProcess* gp) {
    Player* player = new Player("player.png", Box(12, 14, 24, 28));
    Ammo ammo = Ammo(player);
    player->speed = 5.0;
    player->position = Vector<float>(gp->window.getSize()) * 0.5f;
    player->targetPosition = player->position;
    player->setCircle(32);
    player->circle.setFillColor(Color::Red);
    player->gp = gp;
    gp->objects.add(player);
    player->ammo = ammo;
    return player;
  };
};