#include <Objects/player.hpp>
#include <Mouse.hpp>

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
                this->scale(8.0f);
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

        if(this->animationFinished && Mouse::left()) {
            this->shot_sound.setPitch(1 + ((rand() % 6) - 3) * 0.125);
            this->shot_sound.play();

            if(this->firstAttack) this->animate(8, 0, false);
            else this->animate(8, 1, false);

            this->firstAttack = !this->firstAttack;
        };
    };
    
    Player::~Player() {};

    Player* Player::create(GameProcess* gp, string spriteSheet, Box box) {
        Player* player = new Player(spriteSheet, box);
        player->speed = 5.0f;
        player->position = Vector<float>(gp->window.getSize()) * 0.5f;
        player->targetPosition = player->position;
        player->setCircle(32);
        player->circle.setFillColor(Color::Red);
        player->gp = gp;
        gp->objects.add(player);
        return player;
    };
};