#include <Objects/bullet.hpp>

namespace Game
{
    void Bullet::step(GameProcess *gp){
        this->update();
    }

    string Bullet::type()
    {
        return "Bullet";
    }

    void Bullet::update() {
        this->x += this->speed * cos(this->direction);
        this->y += this->speed * sin(this->direction);
    };

    void Bullet::setDirection(float direction) {
        this->direction = direction;
    };

    void Bullet::setSpeed(float speed) {
        this->speed = speed;
    };
}



