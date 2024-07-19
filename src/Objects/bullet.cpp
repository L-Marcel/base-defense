#include <Objects/bullet.hpp>

namespace Game {
    void Bullet::step(){
        this->position.x += this->speed * cos(this->direction);
        this->position.y += this->speed * sin(this->direction);
    };

    string Bullet::type() {
        return "Bullet";
    };

    Bullet::~Bullet() {};
};