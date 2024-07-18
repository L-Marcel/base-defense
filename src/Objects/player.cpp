#include <Objects/player.hpp>
#include <Objects/bullet.hpp>
namespace Game {
    void Player::step(GameProcess* gp) {
        Vector<float> movement = Input::keyboard(
            Keyboard::A,
            Keyboard::W,
            Keyboard::D,
            Keyboard::S,
            2
        );
        
        this->x+=movement.x;
        this->y+=movement.y;
        
        Vector<float> pos = Mouse::position(&gp->window);
        this->rotation = Math::pointDirection(pos.x - this->x, pos.y - this->y) - 90.0;

        if(this->animationFinished && Mouse::left()) {
            if(this->firstAttack) this->animate(8, 0, false);
            else this->animate(8, 1, false);
            
            this->firstAttack = !this->firstAttack;
            this->shoot(gp);
        };
    };

    void Player::shoot(GameProcess* gp){
        Bullet* bullet = new Bullet("assets/bullet.png", Box(8, 8, 16, 16));
        //Bullet bullet();
        bullet->x = this->x;
        bullet->y = this->y;

        bullet->scale(1);
        
        Vector<float> pos = Mouse::position(&gp->window);
        float dx = pos.x - this->x;
        float dy = pos.y - this->y;
        float direction = std::atan2(dy, dx);
        
        bullet->setDirection(direction);
        bullet->setSpeed(7.0f);

        gp->addObject(bullet);
    };

    string Player::type() {
        return "Player";
    };
    
};